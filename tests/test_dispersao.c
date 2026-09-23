#include <stdio.h>
#include <math.h>
#include "dispersao.h"
int total_testes=0;
int total_testes_passou=0;
//função que verifica se o resultado esperado pelo teste é aproximadamente o mesmo para o obtido
void verifica_teste(const char *nome_teste, double res_esperado, double res_obtido){
    total_testes++;
    if(fabs(res_esperado-res_obtido)<0.0001){
        printf("[passou] %s\n",nome_teste);
        total_testes_passou++;
    }
    else{
        printf("[falhou] %s - esperado: %f, obtido: %f\n", nome_teste, res_esperado, res_obtido);
    }
}//testa a função variância por meio de calculo e chama verifica_teste
    void teste_variancia_normal(){
        double data[]={2.0,3.0,4.0,1.0};
        int n=4;
        int erro;
        double res = variancia(data,n,&erro);
        verifica_teste("variancia_normal",1.25,res);
    }//testa a função desvio_padrao por meio de calculo e chama verifica_teste
    void teste_desviopadrao_normal(){
        double data[]={2,3,1};
        int n=3;
        int erro;

        double res=desvio_padrao(data,n,&erro);
        verifica_teste("desviopadrao_normal",0.8165,res);
    }//testa a função amplitude por meio de calculo e chama verifica_teste
    void teste_amplitude_normal(){
        double data[]={1,3,2};
        int n=3;
        int erro;

        double res=amplitude(data,n,&erro);
        verifica_teste("amplitude_normal",2,res);
    }//função que verifica se o erro é o mesmo que o erro esperado pelos testes
    void verifica_erro(const char *nome_teste,  int erro_esp, int erro_obt){
        total_testes++;
        if(erro_esp==erro_obt){
            printf("[passou] %s\n",nome_teste);
            total_testes_passou++;
        }else{
            printf("[falhou] %s - esperado codigo: %d, obtido codigo: %d\n", nome_teste, erro_esp, erro_obt);
        }
    }//testa o erro de que o n<=1 da variância
    void teste_variancia_erro_n_invalido(){
        double data[]={5};
        int n=1;
        int erro;
        variancia(data,n,&erro);
        verifica_erro("variancia_erro_n_invalido",ESTAT_ERRO_N_INVALIDO,erro);
    }//testa o erro de que o n<=1 do desvio padrão
     void teste_desviopadrao_erro_n_invalido(){
        double data[]={5};
        int n=1;
        int erro;
        desvio_padrao(data,n,&erro);
        verifica_erro("desviopadrao_erro_n_invalido",ESTAT_ERRO_N_INVALIDO,erro);
    }//testa o erro de que o n<=1 da amplitude
    void teste_amplitude_n_invalido(){
        double data[]={5};
        int n=1;
        int erro;
        amplitude(data,n,&erro);
        verifica_erro("amplitude_n_invalido",ESTAT_ERRO_N_INVALIDO,erro);
    }

int main() {
    teste_variancia_normal();
    teste_desviopadrao_normal();
    teste_amplitude_normal();
    teste_variancia_erro_n_invalido();
    teste_desviopadrao_erro_n_invalido();
    teste_amplitude_n_invalido();


    printf("\nResumo: %d/%d testes passaram\n", total_testes_passou, total_testes);

    if (total_testes_passou == total_testes) {
    return 0;
} else {
        return 1;
}
}
