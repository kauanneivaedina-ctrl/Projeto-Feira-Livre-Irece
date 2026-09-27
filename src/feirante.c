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

int adicionarProdutoNaBanca(Feirante *feirante, char *nome, float preco){
    if(feirante == NULL){
        printf("Erro: o ponteiro para o feirante é nulo.\n");
        return 0; 
    }
    if(feirante->quantidadeProdutos >= 10){
        printf("Erro: a banca do feirante %s já atingiu o limite de produtos.\n", feirante->nome);
        return 0; 
    }
    int posicao = feirante->quantidadeProdutos;

    strcpy(feirante->produtosVendidos[posicao].nome, nome);
    feirante->produtosVendidos[posicao].preco = preco;
    feirante->produtosVendidos[posicao].quantidadeVendida = 0;

    feirante->quantidadeProdutos++;
    return 1;
}

Feirante *buscarPorCodigo(Feirante feirantes[], int quantidade, int codigoBuscado){
    for(int i = 0; i < quantidade; i++){
        if(feirantes[i].codigo == codigoBuscado){
            return &feirantes[i];
        }
    }
    return NULL;
}

int registrarVendaProduto(Feirante *feirante, char *nomeProduto, int quantidadeVendidaAgora) {
    if (feirante == NULL) {
        printf("Erro: o ponteiro para o feirante é nulo.\n");
        return 0; 
    }

    for (int i = 0; i < feirante->quantidadeProdutos; i++) {
        if (strcmp(feirante->produtosVendidos[i].nome, nomeProduto) == 0) {
            feirante->produtosVendidos[i].quantidadeVendida += quantidadeVendidaAgora;
            return 1; 
        }
    }

    printf("Erro: produto %s não encontrado na banca do feirante %s.\n", nomeProduto, feirante->nome);
    return 0; 
}