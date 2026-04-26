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

void solicitar_dificuldade()
{
  int dificuldade;
  printf("Escolha o nível de dificuldade (1 - Fácil, 2 - Médio, 3 - Difícil): ");
  scanf("%d", &dificuldade); // Aqui você pode adicionar lógica para validar a entrada do usuário e gerar cálculos com base na dificuldade escolhida.
}

// Vou trabalhar com um calculo simples de adição, subtração ou multiplicação com números pequenos.
void calculo_facil()
{
  srand(time(NULL)); // Inicializa o gerador de números aleatórios

  int definicao_operacao = rand() % 3; // Gera um número aleatório entre 0 e 2 para escolher a operação
  int num1 = 0, num2 = 0, resultado = 0;

  num1 = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100
  num2 = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100

  switch (definicao_operacao)
  {
  case 0:
    resultado = num1 + num2; // Calcula a soma
    printf("%d + %d = ?", num1, num2);
    break;

  case 1:
    resultado = num1 - num2; // Calcula a subtração
    printf("%d - %d = ?", num1, num2);
    break;

  case 2:
    resultado = num1 * num2; // Calcula a multiplicação
    printf("%d * %d = ?", num1, num2);
    break;

  default:
    break;
  }
}

int main()
{
  calculo_facil();

  return 0;
}