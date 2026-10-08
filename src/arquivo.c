#include "includes/arquivo.h"

void salvarFeirantes(Feirante feirantes[], int quantidade, char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        printf("Erro ao criar arquivo\n");
        return;
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

    fclose(arquivo);
}

int carregarFeirantes(Feirante **feirantes, int *quantidade, char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao carregar arquivo\n");
        return -1;
    }

    Feirante temp;      //variavel que guarda o feirante atual sendo lido.
    int qtd_feirantes = 0;
    while (fscanf(arquivo, "%d;%49[^;];%d;%14[^;];%d;",
                &temp.codigo,
                temp.nome,
                &temp.banca,
                temp.diaFeira,
                &temp.quantidadeProdutos) == 5){
        int totalProdutos = temp.quantidadeProdutos;
        for (int i = 0; i < totalProdutos; i++) {
            fscanf(arquivo, " %29[^;];%f;%d;",
                   temp.produtosVendidos[i].nome,
                   &temp.produtosVendidos[i].preco,
                   &temp.produtosVendidos[i].quantidadeVendida);
        }
        //aumenta o tamanho do vetor feirantes conforme o arquivo é lido.
        adicionarAoVetor(feirantes, quantidade, temp);
        qtd_feirantes++;
    }

    fclose(arquivo);
    //retorna a quantidade de feirantes carregados do arquivo
    return qtd_feirantes;
}

int inicializarSistema(Feirante **feirantes, int *quantidade){
    int carregados = carregarFeirantes(feirantes, quantidade, "data/feirantes.txt");
    if(carregados > 0){
        printf("%d feirantes foram carregados ao inicializar o sistema\n", carregados);
    }

    system("pause");
    return carregados;
}