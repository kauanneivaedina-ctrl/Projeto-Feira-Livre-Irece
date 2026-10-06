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

    opcao = lerEntrada();
    
    return opcao;
}

//função para ler os dados de cadastro de um novo feirante
Feirante dadosFeirante(){
    Feirante dados;
    ProdutoFeira produtosVendidos = {};

    system("cls");
    printf("=====Cadastro de Feirante=====\n\n");
    printf("Informe o nome do feirante: ");
    scanf(" %49[^\n]", dados.nome);
    printf("Informe qual será a banca do feirante: ");
    dados.banca = lerEntrada();

   printf("Informe em qual dia o feirante atuara na feira:\n");
    strcpy(dados.diaFeira, escolherDiaFeira());

    dados.produtosVendidos[0] = produtosVendidos;
    dados.quantidadeProdutos = 0;

    return dados;
}

void mostrarFeirante(Feirante *feiranteEncontrado){
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
}

//função para ler os dados de cadastro de um novo produto
ProdutoFeira dadosProduto(){
    ProdutoFeira produto;

    system("cls");
    printf("=====Cadastro de Produto=====\n\n");
    printf("Informe o nome do produto: ");
    scanf(" %29[^\n]", produto.nome);
    printf("Informe o preco do produto: ");
    while(scanf("%f", &produto.preco) != 1 || produto.preco < 0){
        printf("Entrada invalida! Digite apenas um numero real.\n");
        while(getchar() != '\n'); // Limpa o buffer de entrada
    }
    produto.quantidadeVendida = 0;

    return produto;
}

//Função do tipo const char que retorna uma string com o dia da feira escolhido.
const char* escolherDiaFeira() {
    printf("[1] Domingo\n");
    printf("[2] Segunda-feira\n");
    printf("[3] Terca-feira\n");
    printf("[4] Quarta-feira\n");
    printf("[5] Quinta-feira\n");
    printf("[6] Sexta-feira\n");
    printf("[7] Sabado\n");

    int diaEscolhido;
    diaEscolhido = lerEntrada();

    switch(diaEscolhido){
        case 1: return "domingo";
        case 2: return "segunda-feira";
        case 3: return "terca-feira";
        case 4: return "quarta-feira";
        case 5: return "quinta-feira";
        case 6: return "sexta-feira";
        case 7: return "sabado";
        default:
            printf("Opcao invalida! Digite um numero entre 1 e 7.\n");
            return escolherDiaFeira(); // Chama a função novamente para escolher o dia
    }

    return NULL; // Retorna NULL caso ocorra algum erro inesperado
}

//função que lê a entrada do usuário e valida se é um número inteiro positivo
int lerEntrada(){
    int entrada;
    while(scanf("%d", &entrada) != 1 || entrada < 0){
        printf("Entrada invalida!.\n");
        while(getchar() != '\n'); // Limpa o buffer de entrada
    }
    return entrada;
}

//função para encontrar um feirante, validar se ele existe e confirmar operação.
Feirante* buscarFeirante(Feirante feirantes[], int quantidade, const char* msg){
    printf("%s", msg);
    char resposta;
    int codigoBuscado = lerEntrada();

    Feirante *feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);

    system ("cls");
    mostrarFeirante(feiranteEncontrado);
    printf("Deseja continuar com este feirante? (s/n): ");
    scanf(" %c", &resposta);

    if(resposta != 's' && resposta != 'S') {
        printf("Operacao cancelada pelo usuario.\n");
        system("pause");
        return NULL;
    }

    if(feiranteEncontrado == NULL) {
        printf("Feirante não encontrado.\n");
        system("pause");
        return NULL;
    }
    return feiranteEncontrado;
}