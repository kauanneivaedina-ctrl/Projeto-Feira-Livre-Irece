#include "includes/feirante.h"
#include "includes/telas.h"

int adicionarAoVetor(Feirante **feirantes, int *quantidade, Feirante novoFeirante){
    int novaQuantidade = (*quantidade) + 1;
    Feirante *vetor_temp = (Feirante *) realloc(*feirantes, novaQuantidade * sizeof(Feirante));
    if(vetor_temp == NULL){
        printf("Erro ao alocar memoria para o novo feirante.\n");
        return 0; // Falha na alocação de memória
    }else{
        *feirantes = vetor_temp;
        (*feirantes)[*quantidade] = novoFeirante;
        *quantidade = novaQuantidade;
        return 1; // Sucesso
    }
}

Feirante *cadastrarFeirante(int codigo, Feirante dados){
    Feirante *novoFeirante = (Feirante *) malloc(sizeof(Feirante));
    if(novoFeirante == NULL){
        printf("Erro ao alocar memoria para o novo feirante.\n");
        return NULL; // Falha na alocação de memória
    }

    novoFeirante->codigo = codigo;
    strcpy(novoFeirante->nome, dados.nome);
    novoFeirante->banca = dados.banca;
    strcpy(novoFeirante->diaFeira, dados.diaFeira);

    //struct aninhada produtosVendidos
    novoFeirante->produtosVendidos[0] = dados.produtosVendidos[0];
    novoFeirante->quantidadeProdutos = dados.quantidadeProdutos;

    return novoFeirante;
}

void listarTodos(Feirante feirantes[], int quantidade){
    system("cls");
    if(quantidade == 0){
        printf("Não há feirantes cadastrados para listar\n");
        return;
    }

    printf("=====Listando feirantes=====\n\n");
    for(int i = 0; i < quantidade; i++){
        mostrarFeirante(&feirantes[i]);
    }   
}

Feirante *buscarPorCodigo(Feirante feirantes[], int quantidade, int codigoBuscado){
    for(int i = 0; i < quantidade; i++){
        if(feirantes[i].codigo == codigoBuscado){
            return &feirantes[i];
        }
    }
    printf("Feirante não encontrado.\n");
    system("pause");
    return NULL;
}

int removerFeirante(Feirante **feirantes, int (*quantidade), int codigo){
    if((*quantidade) == 0 || *feirantes == NULL){
        return 0;
    }

    int idx = - 1;
    for(int i = 0; i < (*quantidade); i++){
        if((*feirantes)[i].codigo == codigo){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        return 0;
    }

    system("cls");
    printf("=====Feirante a ser removido====\n\n");
    mostrarFeirante(&(*feirantes)[idx]);

    char resposta;
    printf("Tem certeza que deseja remover?(s/n) ");
    scanf(" %c", &resposta);

    if(resposta != 's' && resposta != 'S'){ 
        printf("Remoção cancelada.\n");
        return 0;
    }
    for(int i = idx; i < (*quantidade) - 1; i++){
        (*feirantes)[i] = (*feirantes)[i + 1];
    }

    int nova_quantidade = (*quantidade) - 1;
    if(nova_quantidade == 0){
        free(*feirantes);
        *feirantes = NULL;
        *quantidade = 0;
        return 1;
    }
    Feirante *temp = (Feirante *)realloc(*feirantes, sizeof(Feirante) * nova_quantidade);
    if(temp == NULL){
        return 0;
    }

    *feirantes = temp;
    *quantidade = nova_quantidade;
    return 1;
}

void liberarFeirantes(Feirante **feirantes, int *quantidade){
    free(*feirantes);
    *feirantes = NULL;
    *quantidade = 0;
}

void atualizarDiaFeira(Feirante *feirante, char *novoDiaFeira){
    strcpy(feirante->diaFeira, novoDiaFeira);
}

void remanejarFeirante(Feirante *feirantes, char *novoDia, int novaBanca) {
    strcpy(feirantes->diaFeira, novoDia);
    feirantes->banca = novaBanca;
}

float calcularTaxaDaFeira(Feirante *feirante, float percentualTaxa) {
    if (feirante == NULL) {
        printf("Erro: Nenhum feirante cadastrado.\n");
        return 0.0; 
    }

    float totalVendas = calcularFaturamentoFeirante(feirante);
    float taxa = totalVendas * (percentualTaxa / 100.0);
    return taxa;
}

float calcularFaturamentoFeirante(Feirante *feirante) {
    if (feirante == NULL) {
        printf("Erro: nenhum feirante cadastrado.\n");
        return 0.0; 
    }

    float faturamentoTotal = 0.0;
    for (int i = 0; i < feirante->quantidadeProdutos; i++) {
        faturamentoTotal += feirante->produtosVendidos[i].preco * feirante->produtosVendidos[i].quantidadeVendida;
    }

    return faturamentoTotal;
}

void contarFeirantesPorDia(Feirante feirantes[], int quantidade){
    int feirantes_por_dia[7] = {0};

for(int i = 0; i < quantidade; i++){
    if(strcasecmp((feirantes[i].diaFeira), "domingo") == 0) feirantes_por_dia[0]++;
    if(strcasecmp((feirantes[i].diaFeira), "segunda-feira") == 0) feirantes_por_dia[1]++;
    if(strcasecmp((feirantes[i].diaFeira), "terca-feira") == 0) feirantes_por_dia[2]++;
    if(strcasecmp((feirantes[i].diaFeira), "quarta-feira") == 0) feirantes_por_dia[3]++;
    if(strcasecmp((feirantes[i].diaFeira), "quinta-feira") == 0) feirantes_por_dia[4]++;
    if(strcasecmp((feirantes[i].diaFeira), "sexta-feira") == 0) feirantes_por_dia[5]++;
    if(strcasecmp((feirantes[i].diaFeira), "sabado") == 0) feirantes_por_dia[6]++;
}

    system("cls");
    printf("=====Quantidade de feirantes por dia da semana=====\n");
    printf("Domingo : %d\n", feirantes_por_dia[0]);
    printf("Segunda-feira : %d\n", feirantes_por_dia[1]);
    printf("Terca-feira : %d\n", feirantes_por_dia[2]);
    printf("Quarta-feira : %d\n", feirantes_por_dia[3]);
    printf("Quinta-feira : %d\n", feirantes_por_dia[4]);
    printf("Sexta-feira : %d\n", feirantes_por_dia[5]);
    printf("Sabado : %d\n", feirantes_por_dia[6]);
}

int proxCodigo(Feirante feirantes[], int quantidade) {
    int maior = 0;

    for(int i = 0; i < quantidade; i++){
        if(feirantes[i].codigo > maior){
            maior = feirantes[i].codigo;
        }
    }
    return maior + 1; // Retorna o próximo código disponível
}