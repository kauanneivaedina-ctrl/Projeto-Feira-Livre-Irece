#include "includes/arquivo.h"

void salvarFeirantes(Feirante feirantes[], int quantidade, char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        printf("Erro ao criar arquivo\n");
        exit(1);
    }

    for(int i = 0; i < quantidade; i++){
        fprintf(arquivo,"%d;", feirantes[i].codigo);
        fprintf(arquivo,"%s;", feirantes[i].nome);
        fprintf(arquivo,"%d;", feirantes[i].banca);
        fprintf(arquivo,"%s;", feirantes[i].diaFeira);
        fprintf(arquivo,"%d;", feirantes[i].quantidadeProdutos);
        for(int j = 0; j < feirantes[i].quantidadeProdutos; j++){
            fprintf(arquivo,"%s;", feirantes[i].produtosVendidos[j].nome);
            fprintf(arquivo,"%.2f;", feirantes[i].produtosVendidos[j].preco);
            fprintf(arquivo,"%d;", feirantes[i].produtosVendidos[j].quantidadeVendida);
        }
        fprintf(arquivo,"\n");
    }
}

int carregarFeirantes(Feirante **feirantes, int *quantidade, char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao carregar arquivo\n");
        exit(1);
    }

    Feirante temp;
    int qtd_feirantes = 0;
    while (fscanf(arquivo, "%d;%[^;];%d;%[^;];%d;",
                &temp.codigo,
                temp.nome,
                &temp.banca,
                temp.diaFeira,
                &temp.quantidadeProdutos) == 5){
        int totalProdutos = temp.quantidadeProdutos;
        for (int i = 0; i < totalProdutos; i++) {
            fscanf(arquivo, " %[^;];%f;%d;",
                   temp.produtosVendidos[i].nome,
                   &temp.produtosVendidos[i].preco,
                   &temp.produtosVendidos[i].quantidadeVendida);
        }
        adicionarAoVetor(feirantes, quantidade, temp);
        qtd_feirantes++;
    }

    fclose(arquivo);
    return qtd_feirantes;
}
