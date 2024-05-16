#include <stdio.h>
#include <stdlib.h>


void multiplica_matrizes(int linhas_a, int colunas_a, int colunas_b, int **matriz_a, int **matriz_b) {
    int **resultado = (int **)malloc(linhas_a * sizeof(int *));
    for (int i = 0; i < linhas_a; i++) {
        resultado[i] = (int *)malloc(colunas_b * sizeof(int));
    }

    for (int i = 0; i < linhas_a; i++) {
        for (int j = 0; j < colunas_b; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas_a; k++) {
                resultado[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }
    }

    printf("Resultado da multiplicação das matrizes:\n");
    for (int i = 0; i < linhas_a; i++) {
        for (int j = 0; j < colunas_b; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas_a; i++) {
        free(resultado[i]);
    }
    free(resultado);
}


void transpor_matriz(int linhas, int colunas, int **matriz) {
    int **transposta = (int **)malloc(colunas * sizeof(int *));
    for (int i = 0; i < colunas; i++) {
        transposta[i] = (int *)malloc(linhas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    printf("Matriz transposta:\n");
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < colunas; i++) {
        free(transposta[i]);
    }
    free(transposta);
}

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("\n");
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);
    printf("\n");

    
    int **primeira_matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        primeira_matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o elemento da linha %d e coluna %d: ", i, j);
            scanf("%d", &primeira_matriz[i][j]);
        }
    }
    printf("\n");

    
    int opcao;
    printf("Quais das opções abaixo você deseja fazer?\n");
    printf("1 - Multiplicar duas matrizes\n");
    printf("2 - Ver a transposta da matriz que você acabou de criar\n");
    printf("Qual a sua opção? \n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int linhas_b, colunas_b;
        printf("Digite o número de linhas da segunda matriz: ");
        scanf("%d", &linhas_b);
        printf("\n");
        printf("Digite o número de colunas da segunda matriz: ");
        scanf("%d", &colunas_b);
        printf("\n");

        if (colunas != linhas_b) {
            printf("Impossível realizar a multiplicação dessas duas matrizes!\n");
        } else {
            int **segunda_matriz = (int **)malloc(linhas_b * sizeof(int *));
            for (int i = 0; i < linhas_b; i++) {
                segunda_matriz[i] = (int *)malloc(colunas_b * sizeof(int));
            }

            for (int i = 0; i < linhas_b; i++) {
                for (int j = 0; j < colunas_b; j++) {
                    printf("Digite o elemento da linha %d e coluna %d: ", i, j);
                    scanf("%d", &segunda_matriz[i][j]);
                }
            }
            printf("\n");

            multiplica_matrizes(linhas, colunas, colunas_b, primeira_matriz, segunda_matriz);

            for (int i = 0; i < linhas_b; i++) {
                free(segunda_matriz[i]);
            }
            free(segunda_matriz);
        }
    } else if (opcao == 2) {
        transpor_matriz(linhas, colunas, primeira_matriz);
    }

    for (int i = 0; i < linhas; i++) {
        free(primeira_matriz[i]);
    }
    free(primeira_matriz);

    return 0;
}
