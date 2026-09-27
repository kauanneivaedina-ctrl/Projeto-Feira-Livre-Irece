#include "includes/feirante.h"

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