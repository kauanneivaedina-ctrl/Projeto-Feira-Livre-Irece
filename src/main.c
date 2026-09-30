#include "includes/feirante.h"
#include "includes/relatorio.h"
#include "includes/arquivo.h"

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
    Feirante *feiranteEncontrado = NULL;   
    
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

            case 3: {
                printf("Digite o codigo do feirante que deseja buscar: ");
                int codigoBuscado = scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);

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
                system("pause");
                break;
            }

            case 4:
                if(adicionarProdutoNaBanca(feirantes,"ProdutoTeste", 10.0)){
                    printf("Produto adicionado com sucesso!\n");
                }
                system("pause");
                break;

            case 5:
                if(removerFeirante(&feirantes, &quantidade, 3)){
                    printf("Feirante removido com sucesso!\n");
                }else{
                    printf("Feirante nao encontrado\n");
                }
                system("pause");
                break;

            case 6:
                if(registrarVendaProduto(feirantes,"ProdutoTeste", 5)){
                    printf("Venda registrada com sucesso!\n");
                }
                system("pause");
                break;

            case 7:
                atualizarDiaFeira(feirantes, "Quinta-Feira");
                system("pause");
                break;

            case 8:
                remanejarFeirante(feirantes, "Quarta-feira", quantidade, 5, 1);
                system("pause");
                break;

            case 9:{
                float faturamento = calcularFaturamentoFeirante(feirantes);
                printf("O faturamento desse feirante é de R$ %.2f\n", faturamento);
                system("pause");
                break;
            }

            case 10:{
                float taxa_feira = calcularTaxaDaFeira(feirantes, 15.00);
                printf("A taxa da feira para este feirante é de R$ %.2f\n", taxa_feira);
                system("pause");
                break;
            }

            case 11:{
                contarFeirantesPorDia(feirantes, quantidade);
                system("pause");
                break;
            }

            case 12:
                salvarFeirantes(feirantes, quantidade, "data/feirantes.txt");
                printf("Arquivo salvo com sucesso!\n");
                system("pause");
                break;

            case 13:{
                int feirantes_carregados = carregarFeirantes(&feirantes, &quantidade, "data/feirantes.txt");
                printf("%d feirantes foram carregados\n", feirantes_carregados);
                system("pause");
                break;
            }

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarFeirantes(&feirantes, &quantidade); // Liberar memória alocada para o vetor de feirantes
    return 0;
}