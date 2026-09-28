#include "includes/feirante.h"

float calcularTaxaDaFeira(Feirante *feirante, float percentualTaxa) {
    if (feirante == NULL) {
        printf("Erro: o ponteiro para o feirante é nulo.\n");
        return 0.0; 
    }

    float totalVendas = 0.0;
    for (int i = 0; i < feirante->quantidadeProdutos; i++) {
        totalVendas += feirante->produtosVendidos[i].preco * feirante->produtosVendidos[i].quantidadeVendida;
    }

    float taxa = totalVendas * (percentualTaxa / 100.0);
    return taxa;
}

float calcularFaturamentoFeirante(Feirante *feirante) {
    if (feirante == NULL) {
        printf("Erro: o ponteiro para o feirante é nulo.\n");
        return 0.0; 
    }

    float faturamentoTotal = 0.0;
    for (int i = 0; i < feirante->quantidadeProdutos; i++) {
        faturamentoTotal += feirante->produtosVendidos[i].preco * feirante->produtosVendidos[i].quantidadeVendida;
    }

    return faturamentoTotal;
}