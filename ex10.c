#include <stdio.h>
#include <time.h>

int soma(int a, int b) {
    return a + b;
}

int main() {
    int num, num_2;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("Digite outro numero: ");
    scanf("%d", &num_2);

    clock_t inicio, fim;
    double tempo_gasto;

    
    inicio = clock();

    
    int resultado = soma(num, num_2);

    /
    fim = clock();

    
    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("A soma dos numeros e: %d\n", resultado);
    printf("Tempo gasto para calcular a soma: %f segundos\n", tempo_gasto);

    return 0;
}
