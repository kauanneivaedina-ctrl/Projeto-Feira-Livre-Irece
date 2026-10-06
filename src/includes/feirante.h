
#ifndef FEIRANTE_H
#define FEIRANTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

typedef struct Feirante{
    int codigo;
    char nome[50];
    int banca;
    char diaFeira[15];
    ProdutoFeira produtosVendidos[10];
    int quantidadeProdutos;
} Feirante;

int adicionarAoVetor(Feirante **feirantes, int *quantidade, Feirante novoFeirante);
Feirante *cadastrarFeirante(int codigo, Feirante dados);
void listarTodos(Feirante feirantes[], int quantidade);
int removerFeirante(Feirante **feirantes, int *quantidade, int codigo);
Feirante *buscarPorCodigo(Feirante feirantes[], int quantidade, int codigoBuscado);
void liberarFeirantes(Feirante **feirantes, int *quantidade);
void remanejarFeirante(Feirante *feirantes, char *novoDia, int novaBanca);
void atualizarDiaFeira(Feirante *feirante, char *novoDiaFeira);
float calcularTaxaDaFeira(Feirante *feirante, float percentualTaxa);
float calcularFaturamentoFeirante(Feirante *feirante);
void contarFeirantesPorDia(Feirante feirantes[], int quantidade);
int proxCodigo(Feirante feirantes[], int quantidade);

#endif