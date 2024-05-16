#include <stdio.h>


void converte_maiusculas(char *string) {
    while (*string != '\0') {
        
        if (*string >= 'a' && *string <= 'z') {
            *string = *string - ('a' - 'A');
        }
        string++;
    }
}

int main() {
    char string[100]; 
    printf("Escreva alguma palavra e eu converterei ela em maiúsculas: ");
    scanf("%99s", string);
    printf("Antes da conversão: %s\n", string);

    
    converte_maiusculas(string);

    printf("Depois da conversão: %s\n", string);

    return 0;
}
