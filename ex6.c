#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    int idade;
    float salario;
} Funcionarios;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int Cadastrar(Funcionarios funcionarios[], int *pos){
    char nome[30];
    int idade;
    float salario;

    clearBuffer();  

    printf("Digite o nome do funcionario: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  
    printf("\n");

    printf("Digite a idade do funcionario: ");
    scanf("%d", &idade);
    printf("\n");

    printf("Digite o salario do funcionario: ");
    scanf("%f", &salario);
    printf("\n");

    strcpy(funcionarios[*pos].nome, nome);
    funcionarios[*pos].idade = idade;
    funcionarios[*pos].salario = salario;

    (*pos)++;  

    printf("Funcionário adicionado com sucesso!\n");

    return 1;
}

int listar(Funcionarios funcionarios[], int *pos){
    if (*pos == 0){
        printf("Não há funcionários cadastrados!\n");
        return 0;
    }

    for(int i = 0; i < *pos; i++){
        printf("Nome: %s\t", funcionarios[i].nome);
        printf("Idade: %d\t", funcionarios[i].idade);
        printf("Salário: %.2f R$\t", funcionarios[i].salario);
        printf("\n");
    }
    printf("\n");
    
    return 1;
}


int buscarNome(Funcionarios funcionarios[], int *pos){
    if(*pos == 0){
        printf("Não há funcionários cadastrados!\n");
        return 0;
    }
    clearBuffer();
    
    int encontrado = 0;

    char nome[30];

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    for(int i = 0; i < *pos; i++){
        if(strcmp(funcionarios[i].nome, nome) == 0){
            printf("Nome: %s\t", funcionarios[i].nome);
            printf("Idade: %d\t", funcionarios[i].idade);
            printf("Salário: %.2f R$\t", funcionarios[i].salario);
            printf("\n");
            encontrado += 1;
        }
    }

    if(encontrado == 0){
        printf("Este funcionário não está cadastrado!\n");
        return 0;
    }

    return 1;
    
}

int salvar_em_binario(Funcionarios funcionarios[], int *pos) {
  FILE *f = fopen("funcionarios.bin", "wb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo para leitura\n");
    return 0;
  }

  int qtd = fwrite(funcionarios, 100, sizeof(Funcionarios), f);
  if (qtd == 0) {
    printf("Erro ao ler os Funcionários do arquivo\n");
    return 0;
  }
    
  qtd = fwrite(pos, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }
    
  if (fclose(f)) {
    printf("Erro ao fechar o arquivo após a leitura\n");
    return 0;
  }

  printf(
      "\nOs dados foram salvos em arquivo binário com o nome: 'Funcionarios.bin'. \n");
  return 1;
}

int carregar_de_binario(Funcionarios funcionarios[], int *pos) {

  FILE *f = fopen("funcionarios.bin", "rb");
  if (f == NULL) {
    printf("Não há funcionarios salvo no arquivo\n");
    return 0;
  }

  int qtd = fread(funcionarios, 100, sizeof(Funcionarios), f);
  if (qtd == 0) {
    printf("Erro ao ler os Funcionários do arquivo\n");
    return 0;
  }

  qtd = fread(pos, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }

  if (fclose(f)) {
    printf("Erro ao fechar o arquivo\n");
    return 0;
  }

  printf("\nFuncionários carregados com sucesso!\n");
  return 1;
}

int main(){
    Funcionarios funcionarios[100];
    int pos = 0;
    while(1){
        int opcao;

        printf("1 - Cadastrar funcionário\n");
        printf("2 - Listar funcionários\n");
        printf("3 - Buscar funcionário por nome\n");
        printf("4 - Salvar em arquivo binário\n");
        printf("5 - Carregar de arquivo binário\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada:");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1){
            Cadastrar(funcionarios, &pos);
        }
            
        else if (opcao == 2){
            listar(funcionarios, &pos);
        }

        else if(opcao == 3){
            buscarNome(funcionarios, &pos);
        }    

        else if(opcao == 4){
            salvar_em_binario(funcionarios, &pos);
        }

        else if (opcao == 5){
            carregar_de_binario(funcionarios, &pos);
        }
            
        else if (opcao == 0){
            printf("Saindo...\n");
            break;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
