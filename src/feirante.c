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
    printf("=====Listando feirantes=====\n\n");
    for(int i = 0; i < quantidade; i++){
        printf("------------%s------------\n",feirantes[i].nome);
        printf("Codigo: %d\n", feirantes[i].codigo);
        printf("Banca: %d\n", feirantes[i].banca);
        printf("Dia da feira: %s\n", feirantes[i].diaFeira);
        printf("-----Produtos vendidos-----:\n");
        for(int j = 0; j < feirantes[i].quantidadeProdutos; j++){
            printf("Produto: %s\n", feirantes[i].produtosVendidos[j].nome);
            printf("Preco: %.2f\n", feirantes[i].produtosVendidos[j].preco);
            printf("Quantidade vendida: %d\n", feirantes[i].produtosVendidos[j].quantidadeVendida);
            printf("---------------------------\n");
        }
        printf("==================================\n\n");
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

void salvarFeirantes(Feirante feirantes[], int quantidade, char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        printf("Erro ao criar arquivo\n");
        exit(1);
    }

    for(int i = 0; i < quantidade; i++){
        fprintf(arquivo,"%d;", feirantes[i].codigo);
        fprintf(arquivo,"%s;", feirantes[i].nome);
        fprintf(arquivo,"%d;", feirantes[i].banca);
        fprintf(arquivo,"%s;", feirantes[i].diaFeira);
        fprintf(arquivo,"%d;", feirantes[i].quantidadeProdutos);
        for(int j = 0; j < feirantes[i].quantidadeProdutos; j++){
            fprintf(arquivo,"%s;", feirantes[i].produtosVendidos[j].nome);
            fprintf(arquivo,"%.2f;", feirantes[i].produtosVendidos[j].preco);
            fprintf(arquivo,"%d;", feirantes[i].produtosVendidos[j].quantidadeVendida);
        }
        fprintf(arquivo,"\n");
    }
}

int carregarFeirantes(Feirante **feirantes, int *quantidade, char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao carregar arquivo\n");
        exit(1);
    }

    Feirante temp;
    int qtd_feirantes = 0;
    while (fscanf(arquivo, "%d;%[^;];%d;%[^;];%d;",
                &temp.codigo,
                temp.nome,
                &temp.banca,
                temp.diaFeira,
                &temp.quantidadeProdutos) == 5){
        int totalProdutos = temp.quantidadeProdutos;
        for (int i = 0; i < totalProdutos; i++) {
            fscanf(arquivo, " %[^;];%f;%d;",
                   temp.produtosVendidos[i].nome,
                   &temp.produtosVendidos[i].preco,
                   &temp.produtosVendidos[i].quantidadeVendida);
        }
        adicionarAoVetor(feirantes, quantidade, temp);
        qtd_feirantes++;
    }

    fclose(arquivo);
    return qtd_feirantes;
}

void liberarFeirantes(Feirante **feirantes, int *quantidade){
    free(*feirantes);
    *feirantes = NULL;
    *quantidade = 0;
}