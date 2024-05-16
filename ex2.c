#include <stdio.h>
#include <string.h>

void conta_vogais(char string[]) {
    char a = 'a';
    char e = 'e';
    char i = 'i';
    char o = 'o';
    char u = 'u';
    int contador = 0;

    int len_da_palavra = strlen(string);

    for (int j = 0; j < len_da_palavra; j++) {
        if (string[j] == a || string[j] == e || string[j] == i || string[j] == o || string[j] == u) {
            contador++;
        }
    }

    printf("O número de vogais da palavra digitada é: %d\n", contador);
}

int main() {
    char palavra[50];
    printf("Digite uma palavra: ");
    scanf("%49s", palavra);  
    conta_vogais(palavra);

    return 0;
}
