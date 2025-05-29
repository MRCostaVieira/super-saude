#include <cstdio>
#include <iostream>
#include <iterator>
#include <string.h>

using namespace std;

class Classe {
  public:
    char nome[50];
    char cpf[12];
    char endereco[50];
    string nomeApolice;
    double valorApolice = 0;
    int dependentes = 0;
    int preenchido = 0;
    double mensalidade() {
      return this->valorApolice * this->dependentes;
    }
    void limparObjeto() {
      memset(this->nome, 0, sizeof this->nome);
      memset(this->cpf, 0, sizeof this->cpf);
      memset(this->endereco, 0, sizeof this->nome);
      this->dependentes = 0;
    }
    void erroInclusao(int erro) {
      switch(erro) { // Exibir menssagem de erro
        case 1:
          printf("\nNome vazio. Reiniciando inclusão...\n");
          break;
        case 2:
          printf("\nCPF inválido. Reiniciando inclusão...\n");
          break;
        case 3:
          printf("\nEndereço vazio. Reiniciando inclusão...\n");
          break;
        case 4:
          printf("\nInforme um número válido de dependentes. Reiniciando inclusão...\n");
          break;
      }
      this->limparObjeto(); // Limpar campos do objeto
    }
};

// Criar objeto conveniado.
Classe conveniado;

bool validarCPF(const char* cpf) {
  int d10 = 0, d11 = 0;

  if(strlen(cpf) != 11) { // Verifica se o CPF tem exatamente 11 dígitos
    return false;
  }

  for (int i = 0; i < 9; i++) { // Calcula o primeiro dígito verificador (d10)
    d10 += (cpf[i] - '0') * (i + 1);
  }

  d10 = d10 % 11;
  if (d10 == 10) d10 = 0;

  for (int i = 0; i < 10; i++) { // Calcula o segundo dígito verificador (d11)
      d11 += (cpf[i] - '0') * i;
  }

  d11 = d11 % 11;
  if (d11 == 10) d11 = 0;

  // Compara os dígitos calculados com os fornecidos
  if (d10 == (cpf[9] - '0') && d11 == (cpf[10] - '0')){
    return true;
  }else{
    return false;
  }
}

int incluirConveniado() {
  int erro = 0;

  getchar();
  printf("Nome completo: ");
  scanf("%[^\n]", conveniado.nome);

  if (strlen(conveniado.nome) == 0){
    conveniado.erroInclusao(1);
    incluirConveniado();
    return 0;
  }

  getchar();
  printf("CPF válido: ");
  scanf("%[^\n]", conveniado.cpf);

  if(!validarCPF(conveniado.cpf)) { // Validar CPF
    conveniado.erroInclusao(2);
    incluirConveniado();
    return 0;
  }

  getchar();
  printf("Endereço completo: ");
  scanf("%[^\n]", conveniado.endereco);

  if (strlen(conveniado.endereco) == 0){
    conveniado.erroInclusao(3);
    incluirConveniado();
    return 0;
  }

  getchar();
  printf("Número de dependentes: ");
  scanf("%d", &conveniado.dependentes);

  if (conveniado.dependentes <= 0 || conveniado.dependentes >= 'a' || conveniado.dependentes >= 'A'){
    conveniado.erroInclusao(4);
    incluirConveniado();
    return 0;
  }

  conveniado.preenchido = 1; // Impedir sobreposição de dados no objeto

  printf("\nConveniado cadastrado com sucesso!");
  printf("\n");

  return 0;
}

void definirApolice() {
  string apolices[3] = {"Bronze", "Prata", "Ouro"};
  double precoApolices[3] = {600.00, 800.00, 950.00};
  int opcao = 0;

  printf("Definindo apólice...");
  printf("\n\nTipo de apólice | Preço por conveniado\n");

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

void consultarDados() {
  printf("Procurando dados do conveniado...\n\n");

  printf("Nome: %s\n", conveniado.nome);
  printf("CPF: %s\n", conveniado.cpf);
  printf("Endereço: %s\n", conveniado.endereco);

  if(conveniado.valorApolice == 0) { // Verificar se a apólice já foi escolhida
    printf("Apólice: Ainda não cadastrada.\n");
  } else {
    printf("Tipo de apólice: %s\n", conveniado.nomeApolice.c_str());
    printf("Valor unitário da apólice: %.2f\n", conveniado.valorApolice);
  }

  printf("Número de denpendentes: %d\n", conveniado.dependentes);
}

// Abrir menu de opções e chamar função desejada
int opcoes() {
  int opcao = 0;

  printf("\nMenu de opções:\n");
  printf("[1] Inclusão do conveniado\n");
  printf("[2] Tipo de apólice\n");
  printf("[3] Consultar dados do convenio\n");
  printf("[4] Cálculo do valor da mensalidade\n");
  printf("[5] Encerrar programa\n\n");
  printf("Escolher opção: ");
  scanf("%d", &opcao);

  if(opcao == 1) {
    if (conveniado.preenchido == 0) {
      printf("Iniciando a inclusão de conveniado...");
      printf("\nInforme os seguintes dados:\n\n");
      incluirConveniado();

    } else {
      printf("Conveniado já cadastrado!\n");
    }

  } else if (opcao == 2) {
    if (conveniado.preenchido == 0) {
      printf("Conveniado ainda não cadastrado!\n");

    } else if(conveniado.valorApolice != 0) {
      printf("Atualizando apólice\n");
      definirApolice();

    } else {
      definirApolice();
    }

  } else if (opcao == 3) {
    if (conveniado.preenchido == 0) {
      printf("Conveniado ainda não cadastrado!\n");

    } else {
      consultarDados();
    }

  } else if (opcao == 4) {
    if(conveniado.preenchido == 0 && conveniado.valorApolice == 0) {
      printf("Conveniado e apólice ainda não cadastrados!\n");

    } else if(conveniado.preenchido == 0) {
      printf("Conveniado ainda não cadastrado!\n");

    } else if(conveniado.valorApolice == 0) {
      printf("Apólice Ainda não cadastrada.\n");

    } else {
      printf("A mensalidade total é de R$%.2f", conveniado.mensalidade());
      printf("\n");
    }

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
  // Abrir menu de opções
  opcoes();
}
