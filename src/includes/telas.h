#ifndef TELAS_H
#define TELAS_H

#include "feirante.h"

Feirante dadosFeirante();
int exibirMenu();
void mostrarFeirante(Feirante *feiranteEncontrado);
ProdutoFeira dadosProduto();
const char* escolherDiaFeira();
int lerEntrada();
Feirante* buscarFeirante(Feirante feirantes[], int quantidade, const char* msg);

#endif