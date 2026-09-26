#include "includes/feirante.h"

void exibirMenu() {
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
}

int main() {
    Feirante *feirantes = NULL;     //variaveis de controle do vetor dinamico feirantes
    int quantidade = 0;       
    
    ProdutoFeira prodVazio = {"",0,0};

    int opcao;
    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                if(adicionarAoVetor(&feirantes, &quantidade, *cadastrarFeirante(001, "Joao", 001, "Segunda-feira", prodVazio, 0))) {
                    printf("Feirante cadastrado com sucesso!\n");
                } else {
                    printf("Erro ao cadastrar feirante.\n");
                }
                system("pause");
                break;

            case 2:
                listarTodos(feirantes, quantidade);
                system("pause");
                break;

            case 3:
                //buscar por codigo
                break;

            case 4:
                //adicionar produto a banca de um feirante
                break;

            case 5:
                //remover feirante
                break;

            case 6:
                //ordem de venda
                break;

            case 7:
                //atualizar dia de feira
                break;

            case 8:
                //remanejar feirante
                break;

            case 9:
                //calcular faturamento do feirante
                break;

            case 10:
                //calcular taxa da feira
                break;

            case 11:
                //contar feirantes por dia
                break;

            case 12:
                //salvar em arquivo
                break;

            case 13:
                //carregar de arquivo
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    printf("DEBUG quantidade: %d\n\n", quantidade);

    liberarFeirantes(&feirantes, &quantidade); // Liberar memória alocada para o vetor de feirantes
    return 0;
}