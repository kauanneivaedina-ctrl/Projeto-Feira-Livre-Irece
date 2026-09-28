#include "includes/feirante.h"

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

Feirante *cadastrarFeirante(int codigo, char nome[], int banca, char diaFeira[], ProdutoFeira produtosVendidos, int quantidadeProdutos){
    Feirante *novoFeirante = (Feirante *) malloc(sizeof(Feirante));
    if(novoFeirante == NULL){
        printf("Erro ao alocar memoria para o novo feirante.\n");
        return NULL; // Falha na alocação de memória
    }

    novoFeirante->codigo = codigo;
    strcpy(novoFeirante->nome, nome);
    novoFeirante->banca = banca;
    strcpy(novoFeirante->diaFeira, diaFeira);

    //struct aninhada produtosVendidos
    novoFeirante->produtosVendidos[0] = produtosVendidos;
    novoFeirante->quantidadeProdutos = quantidadeProdutos;

    return novoFeirante;
}

void listarTodos(Feirante feirantes[], int quantidade){
    system("cls");
    if(quantidade == 0){
        printf("Não há feirantes cadastrados para listar");
    }

    printf("=====Listando feirantes=====\n\n");
    for(int i = 0; i < quantidade; i++){
        printf("------------%s------------\n",feirantes[i].nome);
        printf("Codigo: %d\n", feirantes[i].codigo);
        printf("Banca: %d\n", feirantes[i].banca);
        printf("Dia da feira: %s\n", feirantes[i].diaFeira);
        printf("-----Produtos vendidos-----:\n");

        //strcut aninhada produtosVendidos
        for(int j = 0; j < feirantes[i].quantidadeProdutos; j++){
            printf("Produto: %s\n", feirantes[i].produtosVendidos[j].nome);
            printf("Preco: %.2f\n", feirantes[i].produtosVendidos[j].preco);
            printf("Quantidade vendida: %d\n", feirantes[i].produtosVendidos[j].quantidadeVendida);
            printf("---------------------------\n");
        }
        printf("==================================\n");
    }
}

Feirante *buscarPorCodigo(Feirante feirantes[], int quantidade, int codigoBuscado){
    for(int i = 0; i < quantidade; i++){
        if(feirantes[i].codigo == codigoBuscado){
            return &feirantes[i];
        }
    }
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
    printf("----------%s----------\n",(*feirantes)[idx].nome);
    printf("Codigo: %d\n",(*feirantes)[idx].codigo);
    printf("Banca: %d\n",(*feirantes)[idx].banca);
    printf("Dia em feira: %s\n", (*feirantes)[idx].diaFeira);
    printf("----Produtos vendidos----\n");
    for(int i = 0; i < (*feirantes)[idx].quantidadeProdutos; i++){
        printf("nome: %s\n", (*feirantes)[idx].produtosVendidos->nome);
        printf("nome: %.2f\n", (*feirantes)[idx].produtosVendidos->preco);
        printf("nome: %d\n", (*feirantes)[idx].produtosVendidos->quantidadeVendida);
    }
    printf("==================================\n");

    char resposta;
    printf("Tem certeza que deseja remover?(s/n) ");
    scanf(" %c", &resposta);

    if(resposta == 'n' || resposta == 'N'){ 
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
    if(feirante == NULL || novoDiaFeira == NULL){
        printf("Erro: ponteiro nulo fornecido para atualizar o dia da feira.\n");
        return;
    }
    strcpy(feirante->diaFeira, novoDiaFeira);


}

void remanejarFeirante(Feirante *feirantes, char *novoDia, int novaBanca, int codigoFeirante) {
    for (int i = 0; i < quantidade; i++) {
        if (feirantes[i].codigo == codigoFeirante) {
            strcpy(feirantes[i].diaFeira, novoDia);
            feirantes[i].banca = novaBanca;
            printf("Feirante %s remanejado com sucesso para o dia %s e banca %d.\n", feirantes[i].nome, novoDia, novaBanca);
            return;
        }
    }
    printf("Erro: feirante com código %d não encontrado.\n", codigoFeirante);
}

