#include "includes/telas.h"

int exibirMenu() {
    int opcao;

    system("cls");
    printf("=========================================\n");
    printf("==== SISTEMA DA FEIRA LIVRE DE IRECE ====\n");
    printf("=========================================\n\n");
    printf("------------ Gerenciamento --------------\n");
    printf("1. Cadastrar feirante\n");
    printf("2. Listar todos os feirantes\n");
    printf("3. Buscar feirante por codigo\n");
    printf("4. Adicionar produto a banca\n");
    printf("5. Remover feirante\n");
    printf("\n");
    printf("---------- Operacoes e Vendas ----------\n");
    printf("6. Ordem de venda \n");
    printf("7. Atualizar dia de feira\n");
    printf("8. Remanejar feirante (banca e dia)\n");
    printf("\n");
    printf("-------- Financeiro e Relatorios --------\n");
    printf("9. Calcular faturamento de um feirante\n");
    printf("10. Calcular taxa da feira\n");
    printf("11. Contar feirantes por dia\n");
    printf("\n");
    printf("------------ Arquivo e Saida ------------\n");
    printf("12. Salvar dados em arquivo\n");
    printf("13. Carregar dados do arquivo\n");
    printf("0. Sair\n");
    printf("-----------------------------------------\n\n");
    printf("ESCOLHA UMA OPCAO: ");

    scanf(" %d", &opcao);
    return opcao;
}

Feirante dadosFeirante(){
    Feirante dados;
    ProdutoFeira produtosVendidos = {};

    system("cls");
    printf("=====Cadastro de Feirante=====\n\n");
    printf("Informe o nome do feirante: ");
    scanf(" %[^\n]", dados.nome);
    printf("Informe qual será a banca do feirante: ");
    scanf("%d", &dados.banca);
    printf("Informe em qual dia o feirante atuará na feira: ");
    scanf(" %[^\n]", dados.diaFeira);
    dados.produtosVendidos[0] = produtosVendidos;
    dados.quantidadeProdutos = 0;

    return dados;
}

char mostrarFeirante(Feirante *feiranteEncontrado){
    system("cls");
    printf("=====Feirante encontrado=====\n\n");
    printf("------------%s------------\n",feiranteEncontrado->nome);
    printf("Codigo: %d\n", feiranteEncontrado->codigo); 
    printf("Banca: %d\n", feiranteEncontrado->banca);
    printf("Dia da feira: %s\n", feiranteEncontrado->diaFeira);
    printf("-----Produtos vendidos-----:\n");
    for(int j = 0; j < feiranteEncontrado->quantidadeProdutos; j++){
        printf("Produto: %s\n", feiranteEncontrado->produtosVendidos[j].nome);
        printf("Preco: %.2f\n", feiranteEncontrado->produtosVendidos[j].preco);
        printf("Quantidade vendida: %d\n", feiranteEncontrado->produtosVendidos[j].quantidadeVendida);
        printf("---------------------------\n");
    }
    printf("==================================\n\n");

    printf("Deseja prosseguir com  a operacao?(s/n) ");
    char resposta;
    scanf(" %c", &resposta);

    return resposta;
}

ProdutoFeira dadosProduto(){
    ProdutoFeira produto;

    system("cls");
    printf("=====Cadastro de Produto=====\n\n");
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", produto.nome);
    printf("Informe o preco do produto: ");
    scanf("%f", &produto.preco);
    produto.quantidadeVendida = 0;

    return produto;
}

int buscarFeirante(Feirante feirantes[], int quantidade){
    int codigoBuscado;
    int resposta;

    printf("Digite o codigo do feirante que deseja buscar: ");
    scanf("%d", &codigoBuscado);
    Feirante *feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);
    if(feiranteEncontrado == NULL){
        printf("Feirante nao encontrado\n");
        return 0;
    }
     resposta = mostrarFeirante(feiranteEncontrado);

     if(resposta == 's' || resposta == 'S'){
        return 1;
     }else{
        return 0;
     }
}