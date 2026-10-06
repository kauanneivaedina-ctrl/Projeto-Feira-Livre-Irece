
#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct ProdutoFeira{
    char nome[30];
    float preco;
    int quantidadeVendida;
} ProdutoFeira;

typedef struct Feirante Feirante;
int adicionarProdutoNaBanca(Feirante *feirante, ProdutoFeira produto);
int registrarVendaProduto(Feirante *feirante, char *nomeProduto, int quantidadeVendidaAgora);

#endif