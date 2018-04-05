#include "conjuntos.h"

void lerConjunto(int* conjunto, int qtdElementos) {
    for(unsigned int i = 0; i < qtdElementos; i++) {
        std::cin >> conjunto[i];
    }
}
void imprimirConjunto(int* conjunto, int qtdElementos, std::string nome) {
    std::cout << nome << '{';
    for(unsigned int i = 0; i < qtdElementos; i++) {
        std::cout << conjunto[i] << (i == qtdElementos-1 ? "}\n" : ", ");
    }
}
void uniao(int* A, int qtdA, int* B, int qtdB, int* AUB, int* qtdAUB) {
    *qtdAUB = qtdA;
    for(unsigned int i = 0; i < qtdA; i++) {
        AUB[i] = A[i];
    }
    for(unsigned int i = 0; i < qtdB; i++) {
        bool encontrado = false;
        for(unsigned int j = 0; j < *qtdAUB; j++) {
            if(B[i] == AUB[j]) {
                encontrado = true;
            }
        }
        if(encontrado == false) {
            int index = *qtdAUB;
            AUB[index] = B[i];
            *qtdAUB += 1;
        }
    }
}
void inter(int* A, int qtdA, int* B, int qtdB, int* AinterB, int* qtdAinterB) {
    int index = 0;
    for(unsigned int i = 0; i < qtdA; i++) {
        for(unsigned int j = 0; j < qtdB; j++) {
            if(A[i] == B[j]) {
                AinterB[index] = A[i];
                *qtdAinterB += 1;
                index++;
            }
        }
    }
}
void dif(int* A, int qtdA, int* B, int qtdB, int* AdifB, int* qtdAdifB) {
    for(unsigned int i = 0; i < qtdA; i++) {
        bool encontrado = false;
        for(unsigned int j = 0; j < qtdB; j++) {
            if(A[i] == B[j]) {
                encontrado = true;
            }
        }
        if(!encontrado) {
            int index = *qtdAdifB;
            AdifB[index] = A[i];
            *qtdAdifB += 1;
        }
    }
}
bool subconjunto(int* A, int qtdA, int* B, int qtdB) {
    int index = 0;
    unsigned int k = 0;
    for(unsigned int i = 0; (i < qtdA && k != qtdB) ; i++) {
        for(unsigned int j = 0; j < qtdB; j++) {
            if(A[i] == B[j]) {
                k++;
            }
        }
    }
    return k == qtdB;
}
bool identicos(int* A, int qtdA, int* B, int qtdB) {
    if(qtdA != qtdB) {
        return false;
    }
    unsigned int k = 0;
    for(unsigned int i = 0; i < qtdA; i++) {
        for(unsigned int j = 0; j < qtdB; j++) {
            if(A[i] == B[j]) {
                k++;
            }
        }
    }
    return k == qtdA;
}
int amplitude(int* conjunto,int tamanhoConjunto) {
    int maior,menor;
    maior = menor = conjunto[0];

    for(unsigned int i = 0; i < tamanhoConjunto; i++) {
        if(conjunto[i] > maior) {
            maior = conjunto[i];
        }else if(conjunto[i] < menor) {
            menor = conjunto[i];
        }
    }
    return maior-menor;
}
void subcadeia(int* conjunto, int tamanhoConj, int* subconj, int* tamanhoSub,char regra) {
    unsigned int indexMaiorSeq = 0,maiorSeq =0,indexSeqAtual = 0,SeqAtual = 0;
    if(regra == '>') {
        for(unsigned int i = 0; i < tamanhoConj-1; i++) {
            if(conjunto[i] > conjunto[i+1]) {
                indexSeqAtual = conjunto[i+1];
                SeqAtual++;
                if(SeqAtual > maiorSeq) {
                    maiorSeq = SeqAtual;
                    indexMaiorSeq = indexSeqAtual;
                }
            }
        }
    }
    else {
        for(unsigned int i = 0; i < tamanhoConj-1; i++) {
            if(conjunto[i] < conjunto[i+1]) {
                indexSeqAtual = conjunto[i+1];
                SeqAtual++;
                if(SeqAtual > maiorSeq) {
                    maiorSeq = SeqAtual;
                    indexMaiorSeq = indexSeqAtual;
                }
            }
        }
    }
    for(unsigned int k = 0,i = indexMaiorSeq - maiorSeq;k < maiorSeq; i++,k++) {
        subconj[k] = conjunto[i];
        *tamanhoSub += 1;
    }
}
void intercalando(int* A, int qtdA, int* B, int qtdB, int* conjunto, int* tamanho) {
    unsigned int maiorTamanho = qtdA > qtdB ? qtdA : qtdB;
    unsigned int menorTamanho = qtdA > qtdB ? qtdB : qtdA;
    int* maiorConjunto= qtdA > qtdB ? A : B;
    for(unsigned int i = 0; i < menorTamanho; i++) {
        if(A[i] < B[i]) {
            *tamanho += 2;
            conjunto[i] = A[i];
            conjunto[i+1] = B[i];
        }else {
            *tamanho += 2;
            conjunto[i] = B[i];
            conjunto[i+1] = A[i];
        }
    }
    for(unsigned int k = *tamanho,i = 0; i < maiorTamanho - menorTamanho; k++, i++) {
        conjunto[k] = maiorConjunto[menorTamanho+i];
    }
}
