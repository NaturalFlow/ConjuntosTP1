#ifndef CONJUNTOS_H_INCLUDED
#define CONJUNTOS_H_INCLUDED

#include <iostream>
#include <string>

void lerConjunto(int* conjunto, int qtdElementos);
void imprimirConjunto(int* conjunto, int qtdElementos, std::string nome = "");
void uniao(int* A, int qtdA, int* B, int qtdB, int* AUB, int* qtdAUB);
void inter(int* A, int qtdA, int* B, int qtdB, int* AinterB, int* qtdAinterB);
void dif(int* A, int qtdA, int* B, int qtdB, int* AdifB, int* qtdAdifB);
bool subconjunto(int* A, int qtdA, int* B, int qtdB);
bool identicos(int* A, int qtdA, int* B, int qtdB);
int amplitude(int* conjunto, int tamanhoConjunto);
void subcadeia(int* conjunto, int tamanhoConj, int* subconj, int* tamanhoSub,char regra = '<');
void intercalando(int* A, int qtdA, int* B, int qtdB, int* conjunto, int* tamanho);
#endif // CONJUNTOS_H_INCLUDED
