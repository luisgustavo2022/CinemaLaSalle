#include <stdio.h>

int main() {
  // Declaração de variaveis 
  int escolhaFilme;
  char escolhaLanche, escolhaAcompanhamento;
  float valorIngresso = 30.50;
  int qtdInteiros, qtdMeias;
  float valorTotal = 0.0;

  printf("Bem-vindo ao Cinema La Salle!\n");

  // Mostra as opções de filme
  printf("Escolha um filme:\n");
  printf("1. Missão Impossível: Acerto de Contas\n");
  printf("2. Barbie\n");
  printf("3. Besouro Azul\n");
  printf("4. Oppenheimer\n");

  do {
    printf("Digite o número do filme desejado: ");
    if (scanf("%d", &escolhaFilme) != 1 || escolhaFilme < 1 ||
        escolhaFilme > 4) {
      printf(
          "Opção de filme inválida. Por favor, escolha um número de 1 a 4.\n");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
    }
  } while (escolhaFilme < 1 || escolhaFilme > 4);

  // Pergunta a quantidade de ingressos inteiros
  do {
    printf("Quantos ingressos inteiros deseja comprar? ");
    if (scanf("%d", &qtdInteiros) != 1 || qtdInteiros < 0) {
      printf("Quantidade inválida. Digite um valor não negativo.\n");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
    }
  } while (qtdInteiros < 0);

  // Pergunta a quantidade de meias-entradas
  do {
    printf("Quantos ingressos de meia-entrada deseja comprar? ");
    if (scanf("%d", &qtdMeias) != 1 || qtdMeias < 0) {
      printf("Quantidade inválida. Digite um valor não negativo.\n");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
    }
  } while (qtdMeias < 0);

  // Calcula o valor total dos ingressos
  valorTotal =
      (qtdInteiros * valorIngresso) + (qtdMeias * (valorIngresso / 2.0));

  // Mostra as regras de meia entrada
  printf("\nRegras de Meia Entrada:\n");
  printf("Menores de 10 anos e maiores de 65 anos pagam meia entrada.\n");

  // Pergunta se deseja um acompanhamento
  do {
    printf("\nDeseja um acompanhamento para comer junto com o filme? (S/N): ");
    if (scanf(" %c", &escolhaAcompanhamento) != 1 ||
        (escolhaAcompanhamento != 'S' && escolhaAcompanhamento != 's' &&
         escolhaAcompanhamento != 'N' && escolhaAcompanhamento != 'n')) {
      printf("Resposta inválida. Digite S para Sim ou N para Não.\n");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
    }
  } while (escolhaAcompanhamento != 'S' && escolhaAcompanhamento != 's' &&
           escolhaAcompanhamento != 'N' && escolhaAcompanhamento != 'n');

  if (escolhaAcompanhamento == 'S' || escolhaAcompanhamento == 's') {
    // Mostra as opções de acompanhamento
    printf("\nOpções de Acompanhamento:\n");
    printf("1. Pipoca\n");
    printf("2. Refrigerante\n");

    do {
      printf("Digite o número do acompanhamento desejado: ");
      if (scanf(" %c", &escolhaLanche) != 1 ||
          (escolhaLanche != '1' && escolhaLanche != '2')) {
        printf("Opção de acompanhamento inválida. Digite 1 para Pipoca ou 2 "
               "para Refrigerante.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
      }
    } while (escolhaLanche != '1' && escolhaLanche != '2');

    // Adiciona o preço do acompanhamento ao valor total
    if (escolhaLanche == '1') {
      valorTotal += 5.0; // Preço da pipoca
    } else if (escolhaLanche == '2') {
      valorTotal += 4.0; // Preço do refrigerante
    }
  }

  // Exibe o resumo da compra
  printf("\nResumo da compra:\n");
  switch (escolhaFilme) {
  case 1:
    printf("Filme escolhido: Missão Impossível: Acerto de Contas\n");
    break;
  case 2:
    printf("Filme escolhido: Barbie\n");
    break;
  case 3:
    printf("Filme escolhido: Besouro Azul\n");
    break;
  case 4:
    printf("Filme escolhido: Oppenheimer\n");
    break;
  default:
    printf("Opção de filme inválida.\n");
    return 1;
  }
  printf("Quantidade de ingressos inteiros: %d\n", qtdInteiros);
  printf("Quantidade de meias-entradas: %d\n", qtdMeias);
  printf("Valor total dos ingressos: R$ %.2f\n", valorTotal);

  if (escolhaAcompanhamento == 'S' || escolhaAcompanhamento == 's') {
    if (escolhaLanche == '1') {
      printf("Acompanhamento escolhido: Pipoca\n");
    } else if (escolhaLanche == '2') {
      printf("Acompanhamento escolhido: Refrigerante\n");
    }
  } else {
    printf("Nenhum acompanhamento escolhido.\n");
  }

  printf("\nAproveite o filme!\n");

  return 0;
}
