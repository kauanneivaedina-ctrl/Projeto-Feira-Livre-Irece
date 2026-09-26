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
    printf("=====Listando feirantes=====\n\n");
    for(int i = 0; i < quantidade; i++){
        printf("------------%s------------\n",feirantes[i].nome);
        printf("Codigo: %d\n", feirantes[i].codigo);
        printf("Banca: %d\n", feirantes[i].banca);
        printf("Dia da feira: %s\n", feirantes[i].diaFeira);
        printf("---------------------------\n\n");
    }
}

void liberarFeirantes(Feirante **feirantes, int *quantidade){
    free(*feirantes);
    *feirantes = NULL;
    *quantidade = 0;
}