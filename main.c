#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Use ./tp3 <entrada.txt> <algoritmo>\n");
        return 0;
    }

    char *arquivoEntrada = argv[1];
    int algoritmo = atoi(argv[2]);

    //printf("%s, %d\n", argv[1], algoritmo);

    return 0;
}