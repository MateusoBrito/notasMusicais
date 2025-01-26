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
    int *mascara = (int*)malloc((MAX+1)*sizeof(int));

    if(mascara == NULL){
        return 0;
    }
    
    for(int i=0;i<MAX+1;i++)
        mascara[i] = 0;
    
    //constroi a mascara de bits para cada caractere do padrap
    for(int i=0;i<m;i++){
        mascara[Padrao[i]] |=  (1 << (m - 1 - i));
    }

    for(int i=0; i<MAX; i++){
        if(mascara[i]!=0){
            printf("mascara[%d] = %d", i, mascara[i]);
            printf("\n");
        }
    }

    unsigned int R = 0;

    for(int i=0;i<n;i++){
        R = ((R>>1) | (1 << (m-1))) & mascara[Texto[i]];
        if(R==1){
            printf("casamento encontrado na pos %d\n", i-m+1);
        }
    }

    free(mascara);

    return 1;
}