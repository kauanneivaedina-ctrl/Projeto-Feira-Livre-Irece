#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "includes/feirante.h"
#include "includes/produto.h"

int main()
{
    SetConsoleOutputCP(65001);

    Feirante feirantes[1];
    int quantidade = 0;
    int opcao_menu;

    do
    {
        system("cls");
        printf("===MENU DE OPÇÕES===\n\n");
        printf("[1] Cadastrar feirante\n");
        printf("[2] Listar feirantes\n");
        printf("[3] Buscar feirante por código\n");
        printf("[4] Atualizar dia frequentado pelo feirante\n");
        printf("[5] Remover feirante\n");
        printf("[6] Salvar alterações\n");
        printf("[7] Carregar arquivo salvo\n");
        printf("[8] Reiniciar número de feirantes\n");
        printf("[9] Registrar venda\n");
        printf("[10] Adicionar produto na banca\n");
        printf("[11] Remanejar feirante\n");
        printf("[12] Calcular faturamento de feirante\n");
        printf("[13] Calcular taxa da feira\n");
        printf("[14] Contar feirantes presentes no dia\n");
        printf("[0] Sair do sistema\n");
        printf("==================================================\n\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao_menu);

        switch (opcao_menu)
        {
            
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida. Tente novamente.\n");
        }
    }while(opcao_menu != 0);

    return 0;
}