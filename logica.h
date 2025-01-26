#ifndef LOGICA_H
#define LOGICA_H

int calculoDiferenca(int t, int p);
void converterParaIntervalos(int *texto, int n, int *intervalos);
void forcaBruta(int *Texto, int n, int *Padrao, int m);
int shiftAnd(int *Texto, int n, int *Padrao, int m);
int *funcaoPrefixoKMP(int *padrao, int m);
int buscaKMP(int *texto, int n, int *padrao, int m);


#endif