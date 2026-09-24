#include "ranking.h"
#include <stdio.h>
#include <stdlib.h>
static void troca(double a[], int i, int j){
  double temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

static int partition_crescente(double a[], int lo, int hi) {
  int i = lo;
  int j = hi + 1;
  double v = a[lo];
  while(1){
    while(a[++i] < v) if (i == hi) break;
    while(v < a[--j]) if (j == lo) break;
    if(i >=j) break;
    troca(a, i, j);
  }
  troca(a, lo, j);
  return j;
} 

static void ordena_rec_crescente(double a[], int lo, int hi){
  if(hi <= lo) return;
  int j = partition_crescente(a, lo, hi);
  ordena_rec_crescente(a, lo, j-1);
  ordena_rec_crescente(a, j+1, hi);
}

void ordenar_crescente(double dados[], int n){
    ordena_rec_crescente(dados, 0, n-1);
}

static int partition_decrescente(double a[], int lo, int hi){
  int i = lo;
  int j = hi + 1;
  double v = a[lo];
  while(1){
    while(a[++i] > v) if (i == hi) break;
    while(v > a[--j]) if (j == lo) break;
    if(i >=j) break;
    troca(a, i, j);
  }
  troca(a, lo, j);
  return j;
} 

static void ordena_rec_decrescente(double a[], int lo, int hi){
  if(hi <= lo) return;
  int j = partition_decrescente(a, lo, hi);
  ordena_rec_decrescente(a, lo, j-1);
  ordena_rec_decrescente(a, j+1, hi);
}

void ordenar_decrescente(double dados[], int n){
  ordena_rec_decrescente(dados, 0, n-1);
}

int* ranking(double dados[], int n, int *erro){
  if(n <= 0){
    *erro=ESTAT_ERRO_N_INVALIDO;
    return NULL;
  }
  
  int *pos = malloc(n * sizeof(int));
  if(pos == NULL){
    *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
    return NULL;
  }

  for(int i = 0; i < n; i++){
    int cont = 1;
    for(int j = 0; j < n; j++){
      if(dados[j] < dados[i]){
       cont++;
    }
  }
  pos[i] = cont;
}
  *erro = ESTAT_OK;
  return pos;
}
