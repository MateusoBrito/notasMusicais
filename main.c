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
        int *musica = leituraEntrada(f, &M);
        int *trecho = leituraEntrada(f, &T);

        //for(int i = 0; i < M; i++){
        //    printf("%d ", musica[i]);
        //}
        printf("\n");

        //for(int i = 0; i < T; i++){
        //    printf("%d ", trecho[i]);
        //}
        //printf("\n");

        //forcaBruta(musica,M,trecho,T);   
        shiftAnd(musica,M, trecho,T);

        free(musica);
        free(trecho);
    }

    fclose(f);

    return 0;
}