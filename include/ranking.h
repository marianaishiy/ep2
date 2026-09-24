#ifndef RANKING_H
#define RANKING_H
#include "erros.h"
/**
 * @brief Ordena um vetor de valores numéricos em ordem crescente
 * @param dados[] Vetor de double a ser ordenado.
 * @param n quantidade de elementos no vetor.
 * @note Esta função não realiza validação de erros. Assume-se que o chamador garanta n > 0 e um vetor válido*
 * */
void ordenar_crescente(double dados[], int n);


/**
 * @brief Ordena um vetor de valores numéricos em ordem decrescente
 * @param dados[] Vetor de double a ser ordenado.
 * @param n quantidade de elementos no vetor.
 * @note Esta função não realiza validação de erros. Assume-se que o chamador garanta n > 0 e um vetor válido*
 * */
void ordenar_decrescente(double dados[], int n);

/**
 * @brief Ranqueia os elementos do vetor 
 * @param dados[] Vetor de double a ser ranqueado.
 * @param n quantidade de elementos no vetor.
 * @param erro Ponteiro para onde onde o código de erro será escrito. Escreve ESTAT_OK se for sucesso
 * @note *erro = ESTAT_ERRO_N_INVALIDO se n<=1 e ESTAT_ERRO_PARAMETRO_INVALIDO caso o malloc falhe*
 * @note Quem chamar a função é responsável por liberar a memória alocada com free()
 * */
int* ranking(double dados[], int n, int *erro);

#endif
