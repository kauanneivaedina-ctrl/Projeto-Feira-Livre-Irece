#include "produto.h"

typedef struct {
    int codigo;
    char nome[50];
    int banca;
    char diaFeira[15];
    ProdutoFeira produtosVendidos[10];
    int quantidadeProdutos;
} Feirante;