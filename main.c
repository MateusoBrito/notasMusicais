#include <stdio.h>
#include <stdlib.h>
#include "entradaSaida.h"
#include "logica.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Use ./tp3 entrada.txt numero_do_algoritmo\n");
        return 0;
    }

    char *arquivoEntrada = argv[1];
    int algoritmo = atoi(argv[2]);

    FILE *f = fopen(arquivoEntrada, "r");

    int M, T;
    while(fscanf(f, "%d %d", &M, &T) == 2 && (M != 0 && T != 0)){
        int *texto = leituraEntrada(f, &M);
        int *padrao = leituraEntrada(f, &T);
        int resultado;

        switch(algoritmo){
            case 1:
                resultado = forcaBruta(texto, M, padrao, T);
                break;
            case 2:
                resultado = buscaKMP(texto, M, padrao, T);
                break;
            case 3:
                resultado = BMH(texto, M, padrao, T);
                break;
            case 4:
                shiftAnd(texto, M, padrao, T);
                break;
            default:
                printf("Algoritmo invalido. Escolha entre 1 e 4.\n");
                break;
        }
        
        if(resultado != -1){
           printf("S %d\n", resultado);
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