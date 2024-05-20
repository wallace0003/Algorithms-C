#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int idade;
} Pessoas;


int registrar_pessoa(Pessoas pessoas[], int *qtd_pessoas) {
    char nome[20];
    int idade;


    while ((getchar()) != '\n' && getchar() != EOF);

    printf("Nome: ");
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = '\0'; 
    strcpy(pessoas[*qtd_pessoas].nome, nome);

    printf("Idade: ");
    scanf("%d", &idade);

    pessoas[*qtd_pessoas].idade = idade;

    (*qtd_pessoas)++;

    printf("Pessoa registrada com sucesso!\n");
    return 1;
}


int comparar_idade(const void *a, const void *b) {
    Pessoas *pessoaA = (Pessoas *)a;
    Pessoas *pessoaB = (Pessoas *)b;
    return (pessoaA->idade - pessoaB->idade);
}


int listar(Pessoas pessoas[], int *qtd_pessoas) {
    if (*qtd_pessoas == 0) {
        printf("Não há pessoas registradas!\n");
        return 0;
    }


    qsort(pessoas, *qtd_pessoas, sizeof(Pessoas), comparar_idade);


    printf("Lista de pessoas ordenadas por idade:\n");
    for (int i = 0; i < *qtd_pessoas; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 1;
}

int main() {
    Pessoas pessoas[100];
    int qtd_pessoas = 0;
    int opcao;

    while (1) {
        printf("1 -> Registrar pessoa\n");
        printf("2 -> Listar pessoas\n");
        printf("0 -> Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            registrar_pessoa(pessoas, &qtd_pessoas);
        } else if (opcao == 2) {
            listar(pessoas, &qtd_pessoas);
        } else if (opcao == 0) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
