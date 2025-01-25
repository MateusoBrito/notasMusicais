#include <stdio.h>
#include "entradaSaida.h"
#include <string.h>
#include <stdlib.h>

int *leituraEntrada(FILE *arquivo, int *tamanho){
    int *notas = (int*)malloc(*tamanho * sizeof(int));
    
    for(int i=0; i < *tamanho; i++){
        char nota[5];
        fscanf(arquivo, "%s", nota);

        if (strcmp(nota, "A") == 0) notas[i] = A;
        else if (strcmp(nota, "A#") == 0) notas[i] = As;
        else if (strcmp(nota, "Bb") == 0) notas[i] = Bb;
        else if (strcmp(nota, "B") == 0) notas[i] = B;
        else if (strcmp(nota, "Cb") == 0) notas[i] = Cb;
        else if (strcmp(nota, "C") == 0) notas[i] = C;
        else if (strcmp(nota, "C#") == 0) notas[i] = Cs;
        else if (strcmp(nota, "Db") == 0) notas[i] = Db;
        else if (strcmp(nota, "D") == 0) notas[i] = D;
        else if (strcmp(nota, "D#") == 0) notas[i] = Ds;
        else if (strcmp(nota, "Eb") == 0) notas[i] = Eb;
        else if (strcmp(nota, "E") == 0) notas[i] = E;
        else if (strcmp(nota, "Fb") == 0) notas[i] = Fb;
        else if (strcmp(nota, "F") == 0) notas[i] = F;
        else if (strcmp(nota, "F#") == 0) notas[i] = Fs;
        else if (strcmp(nota, "Gb") == 0) notas[i] = Gb;
        else if (strcmp(nota, "G") == 0) notas[i] = G;
        else if (strcmp(nota, "G#") == 0) notas[i] = Gs;
        else if (strcmp(nota, "Ab") == 0) notas[i] = Ab;
        else {
            free(notas);
            printf("Nota invalida.\n");
            return NULL;
        }
    }
    return notas;
}