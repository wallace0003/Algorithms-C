#include <stdio.h>
#include <stdlib.h>


double calcular_media(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (double)soma / tamanho;
}


int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


double calcular_mediana(int vetor[], int tamanho) {
    qsort(vetor, tamanho, sizeof(int), comparar);
    if (tamanho % 2 == 0) {
        return (vetor[tamanho / 2 - 1] + vetor[tamanho / 2]) / 2.0;
    } else {
        return vetor[tamanho / 2];
    }
}


int calcular_moda(int vetor[], int tamanho) {
    qsort(vetor, tamanho, sizeof(int), comparar);
    int moda = vetor[0];
    int max_contagem = 1;
    int contagem_atual = 1;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] == vetor[i - 1]) {
            contagem_atual++;
        } else {
            if (contagem_atual > max_contagem) {
                max_contagem = contagem_atual;
                moda = vetor[i - 1];
            }
            contagem_atual = 1;
        }
    }


    if (contagem_atual > max_contagem) {
        max_contagem = contagem_atual;
        moda = vetor[tamanho - 1];
    }

    return moda;
}

int main(void) {
    int tamanho;

    printf("Digite o número de elementos do array: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    double media = calcular_media(vetor, tamanho);
    double mediana = calcular_mediana(vetor, tamanho);
    int moda = calcular_moda(vetor, tamanho);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    return 0;
}
