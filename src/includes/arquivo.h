#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "feirante.h"

void salvarFeirantes(Feirante feirantes[], int quantidade, char *nomeArquivo);
int carregarFeirantes(Feirante **feirantes, int *quantidade, char *nomeArquivo);
int inicializarSistema(Feirante **feirantes, int *quantidade);

#endif