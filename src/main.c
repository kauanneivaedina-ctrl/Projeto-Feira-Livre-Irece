#include "includes/feirante.h"
#include "includes/relatorio.h"
#include "includes/arquivo.h"
#include "includes/telas.h"

int main() {
    Feirante *feirantes = NULL;     //variaveis de controle do vetor dinamico feirantes
    int quantidade = 0;     
    int codigoFeirante = 1;
    int opcao;
    Feirante *feiranteEncontrado = NULL;
    int codigoBuscado;
    char nomeArquivo[100];

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:{
                if(adicionarAoVetor(&feirantes, &quantidade, *cadastrarFeirante(codigoFeirante, dadosFeirante()))) {
                    printf("Feirante cadastrado com sucesso!\n");
                    codigoFeirante++;
                } else {
                    printf("Erro ao cadastrar feirante.\n");
                }
                system("pause");
                break;
            }

            case 2:
                listarTodos(feirantes, quantidade);
                system("pause");
                break;

            case 3: {
                printf("Digite o codigo do feirante que deseja buscar: ");
                scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);

                mostrarFeirante(feiranteEncontrado);
                system("pause");
                break;
            }

            case 4:
                printf("Digite o codigo do feirante que deseja adicionar o produto: ");
                scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);

                if(adicionarProdutoNaBanca(feiranteEncontrado, dadosProduto())){
                    printf("Produto adicionado com sucesso!\n");
                }
                system("pause");
                break;

            case 5:
                printf("Digite o codigo do feirante que deseja remover: ");
                scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);

                if(removerFeirante(&feirantes, &quantidade, feiranteEncontrado->codigo)){
                    printf("Feirante removido com sucesso!\n");
                }else{
                    printf("Feirante nao encontrado\n");
                }
                system("pause");
                break;

            case 6:
                printf("Digite o codigo do feirante que deseja registrar a venda: ");
                scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);
                printf("Digite o nome do produto vendido: ");
                char nomeProduto[30];
                scanf(" %[^\n]", nomeProduto);
                printf("Digite a quantidade vendida do produto: ");
                int quantidadeVendidaAgora;
                scanf("%d", &quantidadeVendidaAgora);

                if(registrarVendaProduto(feiranteEncontrado, nomeProduto, quantidadeVendidaAgora)){
                    printf("Venda registrada com sucesso!\n");
                }
                system("pause");
                break;

            case 7:
                printf("Digite o codigo do feirante que deseja atualizar o dia da feira: ");
                scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);

                atualizarDiaFeira(feiranteEncontrado, "Quinta-Feira");
                system("pause");
                break;

            case 8:
                printf("Digite o codigo do feirante que deseja remanejar: ");
                scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);

                remanejarFeirante(feiranteEncontrado, "Quarta-feira", quantidade, 5, 1);
                system("pause");
                break;

            case 9:{
                printf("Digite o codigo do feirante que deseja calcular o faturamento: ");
                scanf("%d", &codigoBuscado);
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, codigoBuscado);
                if(feiranteEncontrado == NULL) {
                    printf("Feirante não encontrado.\n");
                    system("pause");
                    break;
                }

                printf("O faturamento desse feirante é de R$ %.2f\n", calcularFaturamentoFeirante(feiranteEncontrado));
                system("pause");
                break;
            }

            case 10:{
                if(buscarFeirante(feirantes, quantidade)){
                    float taxa_feira = calcularTaxaDaFeira(feiranteEncontrado, 15.00);
                    printf("A taxa da feira para este feirante é de R$ %.2f\n", taxa_feira);
                    system("pause");
                    break;
                }else{
                    printf("Operacao cancelada\n");
                    system("pause");
                    break;
                }
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
                codigoFeirante = quantidade + 1; // Atualiza o código do próximo feirante
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