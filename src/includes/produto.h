
#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct ProdutoFeira{
    char nome[30];
    float preco;
    int quantidadeVendida;
} ProdutoFeira;

typedef struct Feirante Feirante; // Forward declaration da struct Feirante
int adicionarProdutoNaBanca(Feirante *feirante, char *nome, float preco);
int registrarVendaProduto(Feirante *feirante, char *nomeProduto, int quantidadeVendidaAgora);

#endif