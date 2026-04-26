/*
Devemos desenvolver uma aplicação onde ao ser inicializada
solicite ao usuário escolher o nível de dificuldade do jogo
e após isso gera e apresenta, de forma aleatória,
um cálculo para que possamos informar o resultado.

Iremos limitar as operações em somar, diminuir e multiplicar.

Se o usuário acertar a resposta, somará 1 ponto ao seu score.

Acertando ou errando, ele poderá ou não continuar o jogo."
*/

/*
Separação de responsabilidades:
1. Função para solicitar o nível de dificuldade ao usuário.
2. Função para gerar um cálculo aleatório com base no nível de dificuldade escolhido.
3. Função para solicitar a resposta do usuário e verificar se está correta.
4. Função para atualizar o score do usuário.
5. Função para perguntar ao usuário se deseja continuar jogando ou encerrar o jogo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop_interacao_usuario();
int calculo_facil();
int calculo_medio();
int calculo_dificil();
int resposta_usuario();
int verificar_resposta(int resposta_usuario, int resposta_correta);

int main()
{
  srand(time(NULL)); // Inicializa o gerador de números aleatórios apenas uma vez

  loop_interacao_usuario();

  return 0;
}

void loop_interacao_usuario()
{
  int score = 0; // Variável para armazenar o score
  while (1)
  {
    int dificuldade;

    printf("Escolha o nível de dificuldade (0 - Sair,1 - Fácil, 2 - Médio, 3 - Difícil): ");
    scanf("%d", &dificuldade);

    switch (dificuldade)
    {
    case 0:
      printf("Encerrando o jogo. Obrigado por jogar!\n");
      printf("Seu score final foi: %d\n", score);
      printf("\n");
      return;

    case 1:
    {
      int resposta_correta = calculo_facil();
      int resposta = resposta_usuario();

      score += verificar_resposta(resposta, resposta_correta);

      printf("\n");
      break;
    }

    case 2:
    {
      int resposta_correta = calculo_medio();
      int resposta = resposta_usuario();

      score += verificar_resposta(resposta, resposta_correta);

      printf("\n");
      break;
    }

    case 3:
    {
      int resposta_correta = calculo_dificil();
      int resposta = resposta_usuario();

      score += verificar_resposta(resposta, resposta_correta);

      printf("\n");
      break;
    }

    default:
      printf("Opção inválida! Por favor, escolha um nível de dificuldade válido.\n");
      printf("\n");
      break;
    }
  }
}

// Vou trabalhar com um calculo simples de adição, subtração ou multiplicação com números pequenos.
int calculo_facil()
{
  int definicao_operacao = rand() % 3; // Gera um número aleatório entre 0 e 2 para escolher a operação
  int num1 = 0, num2 = 0, resultado = 0;

  num1 = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100
  num2 = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100

  switch (definicao_operacao)
  {
  case 0:
    resultado = num1 + num2; // Calcula a soma
    printf("%d + %d = ?", num1, num2);
    return resultado; // Retorna o resultado

  case 1:
    // Coloquei esse if para evitar uma subtração que de negativo
    if (num2 > num1)
    {
      resultado = num2 - num1; // Calcula a subtração
      printf("%d - %d = ?", num2, num1);
      return resultado; // Retorna o resultado
    }
    else
    {
      resultado = num1 - num2; // Calcula a subtração
      printf("%d - %d = ?", num1, num2);
      return resultado; // Retorna o resultado
    }

  case 2:
    resultado = num1 * num2; // Calcula a multiplicação
    printf("%d * %d = ?", num1, num2);
    return resultado; // Retorna o resultado

  default:
    return 0;
  }
}

int calculo_medio()
{
  int operacao1 = 1, operacao2 = 1;
  int num1 = 0, num2 = 0, num3 = 0, opr_num1_num2 = 0, resultado = 0;

  operacao1 = rand() % 3; // Gera um número aleatório entre 0 e 2 para escolher a operação
  operacao2 = rand() % 3; // Gera um número aleatório entre 0 e 2 para escolher a operação

  num1 = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100
  num2 = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100
  num3 = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100

  // Aqui vou definir qual vai ser a primeira operação
  switch (operacao1)
  {
  case 0:
    opr_num1_num2 = num1 + num2; // Calcula a soma
    printf("Quanto é %d + %d", num1, num2);
    break;

  case 1:
    // Como é de nivel médio, nao vou ajustar para ficar sem negativos
    opr_num1_num2 = num1 - num2; // Calcula a subtração
    printf("Quanto é %d - %d", num1, num2);
    break;

  case 2:
    opr_num1_num2 = num1 * num2; // Calcula a multiplicação
    printf("Quanto é %d * %d", num1, num2);
    break;

  default:
    return 0;
  }

  // Aqui vou definir qual vai ser a segunda operação
  switch (operacao2)
  {
  case 0:
    resultado = opr_num1_num2 + num3; // Calcula a soma
    printf(" + %d = ?", num3);
    return resultado; // Retorna o resultado

  case 1:
    // Como é de nivel médio, nao vou ajustar para ficar sem negativos
    resultado = opr_num1_num2 - num3; // Calcula a subtração
    printf(" - %d = ?", num3);
    return resultado; // Retorna o resultado

  case 2:
    resultado = opr_num1_num2 * num3; // Calcula a multiplicação
    printf(" * %d = ?", num3);
    return resultado; // Retorna o resultado

  default:
    return 0;
  }
}

int calculo_dificil()
{
  int operacao1 = 1, operacao2 = 1, operacao3 = 1;
  int num1 = 0, num2 = 0, num3 = 0, num4 = 0, opr_num1_num2 = 0, opr_num3_num4 = 0, resultado = 0;

  operacao1 = rand() % 3; // Gera um número aleatório entre 0 e 2 para escolher a operação
  operacao2 = rand() % 3; // Gera um número aleatório entre 0 e 2 para escolher a operação
  operacao3 = rand() % 3; // Gera um número aleatório entre 0 e 2 para escolher a operação

  num1 = (rand() % 100) + 1;
  num2 = (rand() % 100) + 1;
  num3 = (rand() % 100) + 1;
  num4 = (rand() % 100) + 1;

  // Aqui vou definir qual vai ser a primeira operação
  switch (operacao1)
  {
  case 0:
    opr_num1_num2 = num1 + num2;
    printf("Quanto é %d + %d", num1, num2);
    break;

  case 1:
    opr_num1_num2 = num1 - num2;
    printf("Quanto é %d - %d", num1, num2);
    break;

  case 2:
    opr_num1_num2 = num1 * num2;
    printf("Quanto é %d * %d", num1, num2);
    break;

  default:
    return 0;
  }

  // Aqui vou definir qual vai ser a segunda operação
  switch (operacao2)
  {
  case 0:
    opr_num3_num4 = opr_num1_num2 + num3;
    printf(" + %d ", num3);
    break;

  case 1:
    opr_num3_num4 = opr_num1_num2 - num3;
    printf(" - %d ", num3);
    break;

  case 2:
    opr_num3_num4 = opr_num1_num2 * num3;
    printf(" * %d ", num3);
    break;

  default:
    return 0;
  }

  // Aqui vou definir qual vai ser a terceira operação
  switch (operacao3)
  {
  case 0:
    resultado = opr_num3_num4 + num4;
    printf(" + %d = ?", num4);
    return resultado;

  case 1:
    resultado = opr_num3_num4 - num4;
    printf(" - %d = ?", num4);
    return resultado;

  case 2:
    resultado = opr_num3_num4 * num4;
    printf(" * %d = ?", num4);
    return resultado;

  default:
    return 0;
  }
}

// Função para solicitar a resposta do usuário
int resposta_usuario()
{
  int resposta_usuario;
  printf("\nDigite sua resposta: ");
  scanf("%d", &resposta_usuario);
  return resposta_usuario;
}

// Função para verificar a resposta do usuário
int verificar_resposta(int resposta_usuario, int resposta_correta)
{
  if (resposta_usuario == resposta_correta)
  {
    printf("\nResposta correta! Você ganhou 1 ponto.\n");
    return 1;
  }
  else
  {
    printf("\nResposta incorreta! A resposta correta era: %d\n", resposta_correta);
    return 0;
  }
}
