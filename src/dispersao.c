#include <math.h>
#include "dispersao.h"

double variancia(double data[], int n, int *erro){
    //trata erro caso o numero de dados seja negativo, por meio de parametro
    if(n<=1){
        *erro=ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }
    //calcula rapidamente a média sem precisar chamar função do modulo tendencia central
    double soma=0.0;
    for (int i=0;i<n;i++){
        soma+=data[i];
    }
    double media= soma/n;
    double med_quadrado= media*media;
    double s_quadra=0.0;
    for (int i=0;i<n;i++){
        s_quadra+=(data[i]*data[i]);
    }
    *erro=ESTAT_OK;
    return (s_quadra/n)-med_quadrado;// utiliza a fórmula alternatica de variância
}
double desvio_padrao(double data[], int n, int *erro){
    double vari = variancia(data, n, erro);//chama a função variância, pois dp=sqrt(variância)
    if (*erro != ESTAT_OK) {
        return 0.0;
    }
    return sqrt(vari);
}
double amplitude(double data[], int n, int *erro){
    if(n<=1){
        *erro=ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }
    double maior=data[0];
    double menor=data[0];
    for (int i=1;i<n;i++){
        if (data[i]>maior){
            maior=data[i];
        }else if(data[i]<menor){
            menor=data[i];
        }
    }
    return maior-menor;
}

