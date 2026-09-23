#ifndef DISPERSAO_H
#define DISPERSAO_H

#include "erros.h"
/**
 * @brief Função que calcula a variância de um vetor de dados 
 * @param data Vetor com os valores numéricos
 * @param n Quantidade de valores numéricos
 * @param erro Ponteiro para onde o códiog de será escrito
 *              Escreve ESTAT_OK se for sucesso
 * @return Retorna o valor da variância dos dados, ou
 *         retorna 0.0 em caso de erro
 * @note *erro = ESTAT_ERRO_N_INVALIDO se n<=1
 */
double variancia(double data[], int n, int*erro);

/**
 * @brief Função que calcula o desvio padrão de um vetor de dados
 * @param data Vetor com os valores numéricos
 * @param n Quantidade de valores numéricos 
 *@param erro Ponteiro para onde o códiog de será escrito
 *              Escreve ESTAT_OK se for sucesso
 * @return Retorna o valor do desvio padrão dos dados, ou
 *         retorna 0.0 em caso de erro
 * @note *erro = ESTAT_ERRO_N_INVALIDO se n<=1
 * @note a função chama a função da variância para calcular o desvio padrão 
 */
double desvio_padrao(double data[], int n, int *erro);

/**
 * @brief Função que calcula a amplitude de um vetor de dados 
 * @param data Vetor com os valores numéricos
 * @param n Quantidade de valores numéricos 
 *@param erro Ponteiro para onde o códiog de será escrito
 *              Escreve ESTAT_OK se for sucesso
 * @return Retorna o valor da amplitude dos dados, ou
 *         retorna 0.0 em caso de erro
 * @note *erro = ESTAT_ERRO_N_INVALIDO se n<=1
 */
double amplitude(double data[], int n, int *erro);
#endif