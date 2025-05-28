#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

class Classe {
  public:
    char nome[50];
    char cpf[11];
    char endereco[50];
    string nomeApolice;
    double valorApolice = 0;
    int dependentes = 0;
    int preenchido = 0;
    double mensalidade() {
        return this->valorApolice * this->dependentes;
    }
};

// Criar objeto conveniado.
Classe conveniado;

void definirApolice() {

    string apolices[3] = {"Bronze", "Prata", "Ouro"};
    double precoApolices[3] = {600.00, 800.00, 950.00};
    int opcao = 0;

    printf("\nDefinindo apólice...");
    printf("\nTipo de apólice | Preço por conveniado\n\n");

    // Exibir opções e valores
    for(int i = 0; i < (sizeof(apolices) / sizeof(apolices[0]) ); i++) {
       printf("[%d] %s | R$ %.2f\n", i+1, apolices[i].c_str(), precoApolices[i]);
    }

    printf("Escolher: ");
    scanf("%d", &opcao);

    // Atribuir dados ao objeto conveniado
    conveniado.nomeApolice = apolices[opcao - 1];
    conveniado.valorApolice = precoApolices[opcao - 1];

    printf("\nApólice escolhida com sucesso!");
    printf("\n");
}


// Abrir menu de opções e chamar função desejada
int opcoes() {
  int opcao = 0;

  printf("\nMenu de opções:\n");
  printf("[1] Inclusão do conveniado\n");
  printf("[2] Tipo de apólice\n");
  printf("[3] Consulta aos dados do convenio\n");
  printf("[4] Cálculo do valor da mensalidade\n");
  printf("[5] Encerrar programa\n\n");
  printf("Escolher opção:");

  scanf("%d", &opcao);

  if(opcao == 1) {
    // incluirConveniado();
  } else if (opcao == 2) {

    if (conveniado.preenchido == 0) {
      printf("\nConveniado ainda não cadastrado!\n");
    } else {
      definirApolice();
    }

  } else if (opcao == 3) {
    // consultarDados();
  } else if (opcao == 4) {

    printf("\nA mensalidade total é de R$%.f", conveniado.mensalidade());
    printf("\n");

  } else if (opcao == 5) {
    printf("Programa encerrado.\n");
    return 0;
  } else {
    printf("Opção não disponível.\n");
  }

  opcoes();
  return 1;
}

int main() {
    float valorApolice = 0;

    // Abrir menu de opções
    opcoes();
}
