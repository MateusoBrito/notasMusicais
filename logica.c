#include <stdio.h>
#include "logica.h"

int calculoDiferenca(int t, int p){
    int diferenca = t-p;
    if((p+diferenca)>12){
        diferenca = t-(12+p);
    }
    return diferenca;
}

void forcaBruta(int *Texto, int n, int *Padrao, int m){
    int i,j,k = 0;
    
    for(i=0; i<n-m; i++){
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