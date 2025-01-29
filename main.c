#include <stdio.h>
#include <stdlib.h>
#include "entradaSaida.h"
#include "logica.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Use ./tp3 <entrada.txt> <algoritmo>\n");
        return 0;
    }

    char *arquivoEntrada = argv[1];
    int algoritmo = atoi(argv[2]);

    FILE *f = fopen(arquivoEntrada, "r");

    int M, T;
    while(fscanf(f, "%d %d", &M, &T) == 2 && (M != 0 && T != 0)){
        int *texto = leituraEntrada(f, &M);
        int *padrao = leituraEntrada(f, &T);
        //shiftAnd(musica,M, trecho,T);
        int resultado = buscaKMP(texto, M, padrao, T);
        int resultado2 = BMH(texto, M, padrao, T);
        if(resultado != -1){
            printf("S %d\n", resultado);
        }
        else{
            printf("N\n");
        }
        if(resultado2 != -1){
            printf("S %d\n", resultado2);
        }
        else{
            printf("N\n");
        }
        
        free(texto);
        free(padrao);
    }

    fclose(f);

    return 0;
}