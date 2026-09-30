#include "includes/relatorio.h"

float calcularTaxaDaFeira(Feirante *feirante, float percentualTaxa) {
    if (feirante == NULL) {
        printf("Erro: Nenhum feirante cadastrado.\n");
        return 0.0; 
    }

    float totalVendas = calcularFaturamentoFeirante(feirante);
    float taxa = totalVendas * (percentualTaxa / 100.0);
    return taxa;
}

float calcularFaturamentoFeirante(Feirante *feirante) {
    if (feirante == NULL) {
        printf("Erro: nenhum feirante cadastrado.\n");
        return 0.0; 
    }

    float faturamentoTotal = 0.0;
    for (int i = 0; i < feirante->quantidadeProdutos; i++) {
        faturamentoTotal += feirante->produtosVendidos[i].preco * feirante->produtosVendidos[i].quantidadeVendida;
    }

    return faturamentoTotal;
}

void contarFeirantesPorDia(Feirante feirantes[], int quantidade){
    int feirantes_por_dia[7] = {};

for(int i = 0; i < quantidade; i++){
    if(strcmp(strlwr(feirantes[i].diaFeira), "domingo") == 0) feirantes_por_dia[0]++;
    if(strcmp(strlwr(feirantes[i].diaFeira), "segunda-feira") == 0) feirantes_por_dia[1]++;
    if(strcmp(strlwr(feirantes[i].diaFeira), "terca-feira") == 0) feirantes_por_dia[2]++;
    if(strcmp(strlwr(feirantes[i].diaFeira), "quarta-feira") == 0) feirantes_por_dia[3]++;
    if(strcmp(strlwr(feirantes[i].diaFeira), "quinta-feira") == 0) feirantes_por_dia[4]++;
    if(strcmp(strlwr(feirantes[i].diaFeira), "sexta-feira") == 0) feirantes_por_dia[5]++;
    if(strcmp(strlwr(feirantes[i].diaFeira), "sabado") == 0) feirantes_por_dia[6]++;
}

    system("cls");
    printf("=====Quantidade de feirantes por dia da semana=====\n");
    printf("Domingo : %d\n", feirantes_por_dia[0]);
    printf("Segunda-feira : %d\n", feirantes_por_dia[1]);
    printf("Terca-feira : %d\n", feirantes_por_dia[2]);
    printf("Quarta-feira : %d\n", feirantes_por_dia[3]);
    printf("Quinta-feira : %d\n", feirantes_por_dia[4]);
    printf("Sexta-feira : %d\n", feirantes_por_dia[5]);
    printf("Sabado : %d\n", feirantes_por_dia[6]);
}