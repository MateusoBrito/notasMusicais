#include <stdio.h>
#include <stdlib.h>
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

int shiftAnd(int *Texto, int n, int *Padrao, int m){
    unsigned long long mascara[256] = {0};

    if(mascara == NULL){
        return 0;
    }

    for (int j = 0; j < m; j++) {
        mascara[Padrao[j]] |= (1ULL << j); // Atualiza o bit correspondente à posição j no padrão
    }


    printf("Máscaras criadas:\n");
    for (int c = 0; c < 256; c++) {
        if (mascara[c] != 0) { // Apenas exibe as máscaras relevantes
            printf("mascara[%d] = ", c);
            for (int i = m - 1; i >= 0; i--) { // Mostra em binário
                printf("%d", (mascara[c] & (1ULL << i)) ? 1 : 0);
            }
            printf("\n");
        }
    }
    return 1;
}