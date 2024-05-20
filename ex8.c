#include <stdio.h>

// Função para inverter o array
int array_invertido(int vetor[], int tamanho) {
    int ultimo_indice = tamanho - 1;
    int novo_vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        novo_vetor[i] = vetor[ultimo_indice - i];
    }

    printf("Vetor invertido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", novo_vetor[i]);
    }

    printf("Vetor invertido com sucesso!\n");
    return 1;
}

int main(void) {
    int vetor[] = {1, 2, 3, 4, 5}; 
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 

    array_invertido(vetor, tamanho); 

    return 0;
}
