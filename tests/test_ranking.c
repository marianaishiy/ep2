#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "ranking.h"
// Testa a ordenação de um vetor não ordenado 
void test_ordenar_crescente_basico() {
  double dados[] = {8, 2, 3, 1, 5, 6, 7, 9};
  int n = 8;
  ordenar_crescente(dados, n);

  double esperado[] = {1, 2, 3, 5, 6, 7, 8, 9};
  for(int i = 0; i < n; i++){
    assert(dados[i] == esperado[i]);
  }
  printf("[passou] test_ordenar_crescente_basico\n");
}
// Testa a ordenação de um vetor já ordenado

void test_ordenar_crescente_ordenado(){
  double dados[] = {1, 2, 3, 4, 4};
  int n = 5;
  ordenar_crescente(dados, n);

  double esperado[] = {1, 2, 3, 4, 4};
  for(int i = 0; i < n; i++){
    assert(dados[i] == esperado[i]);
  }
  printf("[passou] test_ordenar_crescente_ordenado\n");
  }

  // Testa a ordenação de um vetor com apenas um elemento
void test_ordenar_crescente_um_elemento(){
  double dados[] = {5};
  int n = 1;
  ordenar_crescente(dados, n);
  assert(dados[0] == 5);
  printf("[passou] test_ordenar_crescente_um_elemento \n");
  }
//Testa a ordenação de um vetor com elementos com valores negativos
void test_ordenar_crescente_negativos(){
    double dados[] = {-3.5, -5.8, -10, -150, 0, 7.7};
    int n = 6;
    ordenar_crescente(dados, n);

    double esperado[] = {-150, -10, -5.8, -3.5, 0, 7.7};
    for(int i = 0; i < n; i++){
    assert(dados[i] == esperado[i]);
    }
    printf("[passou] test_ordenar_crescente_negativos \n");
  }

// Testa a ordenação de um vetor não ordenado 
void test_ordenar_decrescente_basico() {
  double dados[] = {8, 2, 3, 1, 5, 6, 8, 9};
  int n = 8;
  ordenar_decrescente(dados, n);

  double esperado[] = {9, 8, 8, 6, 5, 3, 2, 1};
  for(int i = 0; i < n; i++){
    assert(dados[i] == esperado[i]);
  }
  printf("[passou] test_ordenar_decrescente_basico\n");
}
// Testa a ordenação de um vetor já ordenado

void test_ordenar_decrescente_ordenado(){
  double dados[] = {1, 2, 3, 4, 5};
  int n = 5;
  ordenar_decrescente(dados, n);

  double esperado[] = {5, 4, 3, 2, 1};
  for(int i = 0; i < n; i++){
    assert(dados[i] == esperado[i]);
  }
  printf("[passou] test_ordenar_decrescente_ordenado\n");
  }

  // Testa a ordenação de um vetor com apenas um elemento
void test_ordenar_decrescente_um_elemento(){
  double dados[] = {5};
  int n = 1;
  ordenar_decrescente(dados, n);
  assert(dados[0] == 5);
  printf("[passou] test_ordenar_decrescente_um_elemento \n");
  }
//Testa a ordenação de um vetor com elementos com valores negativos
void test_ordenar_decrescente_negativos(){
    double dados[] = {-3.5, -5.8, -10, -150, 0, 7.7};
    int n = 6;
    ordenar_decrescente(dados, n);

    double esperado[] = {7.7, 0, -3.5, -5.8, -10, -150};
    for(int i = 0; i < n; i++){
    assert(dados[i] == esperado[i]);
    }
    printf("[passou] test_ordenar_decrescente_negativos \n");
  }

void test_ranking_basico(){
  double dados[] = {5, 6, 9, 12, 1, 0};
  int n = 6;
  int erro;
  int *pos = ranking(dados, n, &erro);
  
  assert(erro == ESTAT_OK);

  int esperado[] = {3, 4, 5, 6, 2, 1};
  for(int i = 0; i < n; i++){
    assert(pos[i] == esperado[i]);
  }
  free(pos);
  printf("[passou] test_ranking_basico \n");
}

void test_ranking_empate(){
  double dados[] = {1, 20, 20};
  int n = 3;
  int erro;
  int *pos = ranking(dados, n, &erro);
  
  assert(erro == ESTAT_OK);

  int esperado[] = {1, 2, 2};
  for(int i = 0; i < n; i++){
    assert(pos[i] == esperado[i]);
  }
  free(pos);
  printf("[passou] test_ranking_empate \n");
}

void test_ranking_um_elemento(){
  double dados[] = {5};
  int n = 1;
  int erro;
  int *pos = ranking(dados, n, &erro);
  
  assert(erro == ESTAT_OK);

  int esperado[] = {1};
  for(int i = 0; i < n; i++){
    assert(pos[i] == esperado[i]);
  }
  free(pos);
  printf("[passou] test_ranking_um_elemento \n");
}
void test_ranking_negativos(){
  double dados[] = {-3.5, -4.5, 10.1, -25, 0};
  int n = 5;
  int erro;
  int *pos = ranking(dados, n, &erro);
  
  assert(erro == ESTAT_OK);

  int esperado[] = {3, 2, 5, 1, 4};
  for(int i = 0; i < n; i++){
    assert(pos[i] == esperado[i]);
  }
  free(pos);
  printf("[passou] test_ranking_negativos \n");
}
void test_ranking_erro_n_invalido(){
  double dados[] = {5};
  int n = -5;
  int erro;
  int *pos = ranking(dados, n, &erro);
  assert(erro == ESTAT_ERRO_N_INVALIDO);

  free(pos);
  printf("[passou] test_ranking_erro_n_invalido \n");
}
int main() {
    test_ordenar_crescente_basico();
    test_ordenar_crescente_ordenado();
    test_ordenar_crescente_um_elemento();
    test_ordenar_crescente_negativos();

    test_ordenar_decrescente_basico();
    test_ordenar_decrescente_ordenado();
    test_ordenar_decrescente_um_elemento();
    test_ordenar_decrescente_negativos();

    test_ranking_basico();
    test_ranking_empate();
    test_ranking_um_elemento();
    test_ranking_negativos();
    test_ranking_erro_n_invalido();
    printf("Todos os testes de ranking passaram!\n");
    return 0;
  }
