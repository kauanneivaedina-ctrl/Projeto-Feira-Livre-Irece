#include "includes/produto.h"
#include "includes/feirante.h"

int adicionarProdutoNaBanca(Feirante *feirante, ProdutoFeira produto) {
    if(feirante == NULL){
        printf("Erro: Nenhum feirante cadastrado.\n");
        return 0; 
    }
    if(feirante->quantidadeProdutos >= 10){
        printf("Erro: a banca do feirante %s já atingiu o limite de produtos.\n", feirante->nome);
        return 0; 
    }
    int posicao = feirante->quantidadeProdutos;

    strcpy(feirante->produtosVendidos[posicao].nome, produto.nome);
    feirante->produtosVendidos[posicao].preco = produto.preco;
    feirante->produtosVendidos[posicao].quantidadeVendida = produto.quantidadeVendida;

    feirante->quantidadeProdutos++;
    return 1;
}

int registrarVendaProduto(Feirante *feirante, char *nomeProduto, int quantidadeVendidaAgora) {
    if (feirante == NULL) {
        printf("Erro: nenhum feirante foi encontrado.\n");
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