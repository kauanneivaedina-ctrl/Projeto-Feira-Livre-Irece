#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

#ifndef FEIRANTE_H
#define FEIRANTE_H

typedef struct Feirante{
    int codigo;
    char nome[50];
    int banca;
    char diaFeira[15];
    ProdutoFeira produtosVendidos[10];
    int quantidadeProdutos;
} Feirante;

int adicionarAoVetor(Feirante **feirantes, int *quantidade, Feirante novoFeirante);
Feirante *cadastrarFeirante(int codigo, char nome[], int banca, char diaFeira[], ProdutoFeira produtosVendidos, int quantidadeProdutos);
void listarTodos(Feirante feirantes[], int quantidade);
int removerFeirante(Feirante **feirantes, int *quantidade, int codigo);
Feirante *buscarPorCodigo(Feirante feirantes[], int quantidade, int codigoBuscado);
void salvarFeirantes(Feirante feirantes[], int quantidade, char *nomeArquivo);
int carregarFeirantes(Feirante **feirantes, int *quantidade, char *nomeArquivo);
void liberarFeirantes(Feirante **feirantes, int *quantidade);
void remanejarFeirante(Feirante *feirantes, char *novoDia, int novaBanca, int codigoFeirante);


#endif

