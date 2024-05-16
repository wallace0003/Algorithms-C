#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[25];
    float preco;
    int quantidade;
} Produtos;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int cadastrar(Produtos produtos[], int *pos) {
    char nome[25];
    float preco;
    int quantidade;

    clearBuffer();  

    printf("Nome do produto: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  
    printf("\n");

    printf("Preço: ");
    scanf("%f", &preco);
    printf("\n");

    printf("Quantidade: ");
    scanf("%d", &quantidade);
    printf("\n");

    strcpy(produtos[*pos].nome, nome);
    produtos[*pos].preco = preco;
    produtos[*pos].quantidade = quantidade;

    (*pos)++;

    return 1;
}

int listar(Produtos produto[], int *pos) {
    if (*pos == 0) {
        printf("Não há produtos para serem listados\n");
        return 0;
    }

    for (int i = 0; i < *pos; i++) {
        printf("Produto: %s\n", produto[i].nome);
        printf("Preço: %.2f\n", produto[i].preco);
        printf("Quantidade: %d\n", produto[i].quantidade);
        printf("\n");
    }
    return 1;
}

int precoComQuantidade(Produtos produto[], int *pos) {
    if (*pos == 0) {
        printf("Não há produtos cadastrados\n");
        return 0;
    }

    float total = 0;

    for (int i = 0; i < *pos; i++) {
        total += produto[i].preco * produto[i].quantidade;
    }

    printf("Valor total em estoque: %.2f\n", total);

    return 1;
}

int main(void) {
    Produtos produtos[100];
    int pos = 0;
    int opcao;

    while (1) {
        printf("1 -> Cadastrar\n");
        printf("2 -> Listar\n");
        printf("3 -> Preços com quantidade\n");
        printf("0 -> Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrar(produtos, &pos);
        } else if (opcao == 2) {
            listar(produtos, &pos);
        } else if (opcao == 3) {
            precoComQuantidade(produtos, &pos);
        } else if (opcao == 0) {
            printf("\nSaindo...\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
