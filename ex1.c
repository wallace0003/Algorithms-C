#include <stdio.h>

int main(void) {
    int n_de_indices = 0;
    int numero = 0;
    int soma_array = 0;

    
    printf("Digite o número de elementos que você deseja inserir em seu Array: ");
    scanf("%d", &n_de_indices);
    printf("\n");


    int array[n_de_indices];

    
    for (int i = 0; i < n_de_indices; i++) {
        printf("Digite o elemento para o índice %d --> ", i);
        scanf("%d", &numero);
        array[i] = numero;
    }


    for (int i = 0; i < n_de_indices; i++) {
        soma_array += array[i];
    }

    printf("\n");
    printf("A soma dos elementos do array é: %d\n", soma_array);

    return 0;
}
