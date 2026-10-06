#include "includes/feirante.h"
#include "includes/arquivo.h"
#include "includes/telas.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001); // Configura a saída do console para aceitar acentos
    SetConsoleCP(65001); // Configura a entrada do console para aceitar acentos

    Feirante *feirantes = NULL;  //variaveis de controle do vetor dinamico feirantes
    int quantidade = 0;
    int codigoFeirante = 1;
    int opcao;
    Feirante *feiranteEncontrado = NULL;

    //função que carrega os feirantes do arquivo salvo ao inicilizar o sistema
    inicializarSistema(&feirantes, &quantidade);

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:{
                codigoFeirante = proxCodigo(feirantes, quantidade); // Atualiza o código do feirante para o próximo disponível
                Feirante *novoFeirante = cadastrarFeirante(codigoFeirante, dadosFeirante());
                if(adicionarAoVetor(&feirantes, &quantidade, *novoFeirante)) {
                    printf("Feirante cadastrado com sucesso!\n");
                    codigoFeirante++;
                } else {
                    printf("Erro ao cadastrar feirante.\n");
                }
                free(novoFeirante); //libera a memória alocada para o novo feirante
                system("pause");
                break;
            }

            case 2:
                listarTodos(feirantes, quantidade);
                system("pause");
                break;

            case 3: {
                printf("Digite o codigo do feirante que deseja buscar: ");
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, lerEntrada());
                if(feiranteEncontrado == NULL) break;

                system("cls");
                printf("=====Feirante encontrado=====\n");
                mostrarFeirante(feiranteEncontrado);
                system("pause");
                break;
            }

            case 4:
                feiranteEncontrado = buscarFeirante(feirantes, quantidade, "Digite o codigo do feirante que deseja adicionar um produto: ");
                if(feiranteEncontrado == NULL) break;

                if(adicionarProdutoNaBanca(feiranteEncontrado, dadosProduto())){
                    printf("Produto adicionado com sucesso!\n");
                }
                system("pause");
                break;

            case 5:
                printf("Digite o codigo do feirante que deseja remover: ");
                feiranteEncontrado = buscarPorCodigo(feirantes, quantidade, lerEntrada());
                if(feiranteEncontrado == NULL) break;

                if(removerFeirante(&feirantes, &quantidade, feiranteEncontrado->codigo)){
                    printf("Feirante removido com sucesso!\n");
                }
                system("pause");
                break;

            case 6:
                feiranteEncontrado = buscarFeirante(feirantes, quantidade, "Digite o codigo do feirante que deseja registrar uma venda: ");
                if(feiranteEncontrado == NULL) break;

                system("cls");
                printf("=====Registro de Venda=====\n\n");
                printf("Digite o nome do produto vendido: ");
                char nomeProduto[30];
                scanf(" %29[^\n]", nomeProduto);

                printf("Digite a quantidade vendida do produto: ");
                int quantidadeVendidaAgora;
                quantidadeVendidaAgora = lerEntrada();

                if(registrarVendaProduto(feiranteEncontrado, nomeProduto, quantidadeVendidaAgora)){
                    printf("Venda registrada com sucesso!\n");
                }
                system("pause");
                break;

            case 7:
                feiranteEncontrado = buscarFeirante(feirantes, quantidade, "Digite o codigo do feirante que deseja atualizar o dia da feira: ");
                if(feiranteEncontrado == NULL) break;

                printf("Escolha o novo dia da feira:\n");
                char novoDia[15];
                strcpy(novoDia, escolherDiaFeira());

                atualizarDiaFeira(feiranteEncontrado, novoDia);
                system("pause");
                break;

            case 8:
                feiranteEncontrado = buscarFeirante(feirantes, quantidade, "Digite o codigo do feirante que deseja remanejar: ");
                if(feiranteEncontrado == NULL) break;

                system("cls");
                printf("=====Remanejamento de Feirante=====\n\n");
                printf("Escolha o novo dia da feira:\n");
                strcpy(novoDia, escolherDiaFeira());
                
                printf("Digite a nova banca do feirante: ");
                int novaBanca;
                novaBanca = lerEntrada();

                remanejarFeirante(feiranteEncontrado, novoDia, novaBanca);
                system("pause");
                break;

            case 9:{
                feiranteEncontrado = buscarFeirante(feirantes, quantidade, "Digite o codigo do feirante que deseja calcular o faturamento: ");
                if(feiranteEncontrado == NULL) break;

                printf("O faturamento desse feirante é de R$ %.2f\n", calcularFaturamentoFeirante(feiranteEncontrado));
                system("pause");
                break;
            }

            case 10:{
                feiranteEncontrado = buscarFeirante(feirantes, quantidade, "Digite o codigo do feirante que deseja calcular a taxa da feira: ");
                if(feiranteEncontrado == NULL) break;

                float percentualTaxa;
                printf("Digite o percentual da taxa da feira (ex: 5 para 5%%): ");
                percentualTaxa = lerEntrada();

                float taxa = calcularTaxaDaFeira(feiranteEncontrado, percentualTaxa);
                printf("A taxa da feira para o feirante %s é de R$ %.2f\n", feiranteEncontrado->nome, taxa);
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
                printf("Gostaria de salvar os dados antes de sair? (s/n): ");
                char resposta;
                scanf(" %c", &resposta);

                if(resposta == 's' || resposta == 'S'){
                    salvarFeirantes(feirantes, quantidade, "data/feirantes.txt");
                    printf("Arquivo salvo com sucesso!\n");
                }
                
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                system("pause");
        }
    } while (opcao != 0);

    liberarFeirantes(&feirantes, &quantidade); // Liberar memória alocada para o vetor de feirantes
    return 0;
}