#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logica.h"
#include "entradaSaida.h"

int calculoDiferenca(int t, int p){
    int diferenca = t-p;
    if(diferenca<0){
        diferenca += 12;
    }
    return diferenca;
}

void converterParaIntervalos(int *texto, int n, int *intervalos){
    for(int i=0; i<n-1; i++){
        intervalos[i] = calculoDiferenca(texto[i+1], texto[i]);
    }
}

void forcaBruta(int *Texto, int n, int *Padrao, int m){
    int i,j,k = 0;
    
    for(i=0; i<n-m+1; i++){
        k=i;
        j=0;

        int diferenca = calculoDiferenca(Texto[k],Padrao[j]);
   
        while(calculoDiferenca(Texto[k],Padrao[j]) == diferenca){
            j++;
            k++;
        }

        if(j==m){
            printf("Casamento na posicao: %d", i);
        }
    }

    return;
}

#define MAX 12

int shiftAnd(int *Texto, int n, int *Padrao, int m){
    int *intervalosTexto = (int*)malloc(sizeof(int) * (n - 1));
    int *intervalosPadrao = (int*)malloc(sizeof(int) * (m - 1));
    if (!intervalosTexto || !intervalosPadrao) return -1; 

    converterParaIntervalos(Texto, n, intervalosTexto);
    converterParaIntervalos(Padrao, m, intervalosPadrao);

    int *mascara = (int*)malloc((MAX)*sizeof(int));

    if(mascara == NULL) return 0;
    

    for(int i=0;i<MAX;i++)
        mascara[i] = 0;
    
    //m-1 no for pois agora a comparação é sobre os intervalos
    //(1 << (m - 2 - i)) = 1(onde vao colocar o 1) << ((m-1 dos intervalos) - 1 - i são os zeros)
    for(int i=0;i<m-1;i++)
        mascara[intervalosPadrao[i]-1] |=  (1 << (m - 2 - i));
    

    /*
    for (int i = 0; i < MAX; i++) {
        if(mascara[i]!=0){
            printf("mascara[%d]: ", i);
            for (int bit = m-2; bit >= 0; bit--) {
                printf("%d", (mascara[i] >> bit) & 1);
            }
            printf("\n");
        }
    }
    */

    unsigned int R = 0;

    for(int i=0;i<n-1;i++){
        R = ((R>>1) | (1 << (m-2))) & mascara[intervalosTexto[i]-1];
        if(R==1){
            printf("casamento encontrado na pos %d\n", i-m+2);
        }
    }

    free(intervalosPadrao);
    free(intervalosTexto);
    free(mascara);

    return 1;
}

int *funcaoPrefixoKMP(int *padrao, int m){
    int *tabelaLPS = (int*)malloc(sizeof(int)*m);
    if(!tabelaLPS) return NULL;
    // A tabela LPS indica o maior prefixo que também é um sufixo

    int j=0, i=1;
    tabelaLPS[0] = 0;

    for(i=1; i<m; i++){
        while(j>0 && padrao[j] != padrao[i]){
            j = tabelaLPS[j-1]; // Volta para o último maior prefixo válido
        }
        if(padrao[i] == padrao[j]){
            j++;
        }
        tabelaLPS[i] = j; // Define o valor para a posição atual
    }
    return tabelaLPS; // Vetor com cada posição que gera um prefixo para cada posição do padrão
}

int buscaKMP(int *texto, int n, int *padrao, int m){
    int *intervalosTexto = (int*)malloc(sizeof(int) * (n - 1));
    int *intervalosPadrao = (int*)malloc(sizeof(int) * (m - 1));
    if (!intervalosTexto || !intervalosPadrao) return -1; 

    converterParaIntervalos(texto, n, intervalosTexto);
    converterParaIntervalos(padrao, m, intervalosPadrao);

    int *tabelaLPS = funcaoPrefixoKMP(intervalosPadrao, m-1);
    if(!tabelaLPS) return -1;

    int k=0;
    for(int i=0; i<n-1; i++){
        while(k>0 && intervalosPadrao[k] != intervalosTexto[i]){
            k = tabelaLPS[k-1]; // Volta para o último prefixo válido
        }
        if(intervalosTexto[i] == intervalosPadrao[k]){
            k++;
        }
        if(k == (m-1)){ // Casamento encontrado
            free(intervalosPadrao);
            free(intervalosTexto);
            free(tabelaLPS);
            return i-(m-2);
        }
    }
    free(intervalosPadrao);
    free(intervalosTexto);
    free(tabelaLPS);
    return -1; // Padrão não encontrado
}

#define MAXTAMALFABETO 256

int BMH(int *texto, int n, int *padrao, int m){
    if(m <= 1 || n < m) return -1;

    int tamTexto = n-1;
    int tamPadrao = m-1;

    int *intervalosTexto = (int*)malloc(sizeof(int) * tamTexto);
    int *intervalosPadrao = (int*)malloc(sizeof(int) * tamPadrao);
    if (!intervalosTexto || !intervalosPadrao) return -1;

    converterParaIntervalos(texto, n, intervalosTexto);
    converterParaIntervalos(padrao, m, intervalosPadrao);

    int i, j, k;
    int d[MAXTAMALFABETO];

    for(j=0; j<MAXTAMALFABETO; j++){
        d[j] = tamPadrao; // inicia todos os deslocamentos como m
    }

    for(j=0; j<tamPadrao-1; j++){
        d[intervalosPadrao[j]] = tamPadrao-1-j;
    }

    i = tamPadrao-1;
    while(i<tamTexto){
        k = i;
        j = tamPadrao-1;
        while(k>=0 && intervalosTexto[k] == intervalosPadrao[j] && j>=0){
            k--;
            j--;
        }
        if(j<0){
            free(intervalosPadrao);
            free(intervalosTexto);
            return k+1; //casamento encontrado
        }
        if(intervalosTexto[i] < MAXTAMALFABETO) {
            i += d[intervalosTexto[i]];
        }else{
            i += tamPadrao;
        }
    }
    free(intervalosPadrao);
    free(intervalosTexto);
    return -1; //casamento nao encontrado
}