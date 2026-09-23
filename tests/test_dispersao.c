#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "dispersao.h"

// Compara dois double com tolerancia (evita erro de arredondamento)
int aproximadamente_igual(double a, double b) {
    return fabs(a - b) < 0.0001;
}

// Testa o calculo da variancia com um conjunto de dados valido
void teste_variancia_normal(){
    double data[] = {2.0, 3.0, 4.0, 1.0};
    int n = 4;
    int erro;

    double res = variancia(data, n, &erro);

    assert(erro == ESTAT_OK);
    assert(aproximadamente_igual(res, 1.25));

    printf("[passou] teste_variancia_normal\n");
}

// Testa se variancia() retorna o codigo de erro correto quando n <= 1
void teste_variancia_erro_n_invalido(){
    double data[] = {5};
    int n = 1;
    int erro;

    variancia(data, n, &erro);

    assert(erro == ESTAT_ERRO_N_INVALIDO);

    printf("[passou] teste_variancia_erro_n_invalido\n");
}

// Testa o calculo do desvio padrao com um conjunto de dados valido
void teste_desviopadrao_normal(){
    double data[] = {2, 3, 1};
    int n = 3;
    int erro;

    double res = desvio_padrao(data, n, &erro);

    assert(erro == ESTAT_OK);
    assert(aproximadamente_igual(res, 0.816497));

    printf("[passou] teste_desviopadrao_normal\n");
}

// Testa se desvio_padrao() retorna o codigo de erro correto quando n <= 1
void teste_desviopadrao_erro_n_invalido(){
    double data[] = {5};
    int n = 1;
    int erro;

    desvio_padrao(data, n, &erro);

    assert(erro == ESTAT_ERRO_N_INVALIDO);

    printf("[passou] teste_desviopadrao_erro_n_invalido\n");
}

// Testa o calculo da amplitude com um conjunto de dados valido
void teste_amplitude_normal(){
    double data[] = {1, 3, 2};
    int n = 3;
    int erro;

    double res = amplitude(data, n, &erro);

    assert(erro == ESTAT_OK);
    assert(aproximadamente_igual(res, 2.0));

    printf("[passou] teste_amplitude_normal\n");
}

// Testa se amplitude() retorna o codigo de erro correto quando n <= 1
void teste_amplitude_erro_n_invalido(){
    double data[] = {5};
    int n = 1;
    int erro;

    amplitude(data, n, &erro);

    assert(erro == ESTAT_ERRO_N_INVALIDO);

    printf("[passou] teste_amplitude_erro_n_invalido\n");
}

int main() {
    teste_variancia_normal();
    teste_variancia_erro_n_invalido();
    teste_desviopadrao_normal();
    teste_desviopadrao_erro_n_invalido();
    teste_amplitude_normal();
    teste_amplitude_erro_n_invalido();

    printf("\nTodos os testes de dispersao passaram!\n");
    return 0;
}