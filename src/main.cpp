#include <iostream>
#include "tela.h"
#include "conjuntos.h"

using namespace std;

int main() {
L1:
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    tela("Conjuntos TP1");
    centralizar("Um Conjunto é uma coleção de elementos.Onde a ordem como estao organizados não importa.", 6);
    centralizar("Alem disso nao ha elementos repetidos ", 7);
    centralizar("Insira dois Conjuntos para explorar as propriedades e operaçoes",9);
    int tamanhoA, tamanhoB,tamanhoC=0,tamanhoD=0,tamanhoE=0,tamanhoF=0,tamanhoG=0,tamanhoH=0, tamanhoI = 0;
    centralizar("Tamanho A:[  ]                                           ", 10);
    centralizar("Elementos de A:                                          ", 11);
    centralizar("Tamanho B:[  ]                                           ", 13);
    centralizar("Elementos de B:                                          ", 14);

    gotoxy(43, 13);
    std::cin >> tamanhoA;
    int vetA[tamanhoA];
    gotoxy(48, 14);
    lerConjunto(vetA, tamanhoA);

    gotoxy(43, 16);
    std::cin >> tamanhoB;
    int vetB[tamanhoB];
    gotoxy(48, 17);
    lerConjunto(vetB, tamanhoB);

    gotoxy(32, 19);
    imprimirConjunto(vetA, tamanhoA, "A ");
    gotoxy(32, 20);
    imprimirConjunto(vetB, tamanhoB, "B ");

    showOptions("1 - União            2 - Intersecção      7 - identicos?      10 - Subcadeia Crescente em A",
                "3 - Diferença A e B  4 - Diferença B e A  8 - Amplitude de A  11 - Subcadeia Decrescente em B",
                "5 - A subconj de B?  6 - B subconj de A?  9 - Amplitude de B  12 - Subcadeia Intercalados");
    unsigned short selected;
    int vetC[tamanhoC] = {};
    int vetD[tamanhoD] = {};
    int vetE[tamanhoE] = {};
    int vetF[tamanhoF] = {};
    int vetG[tamanhoG] = {};
    int vetH[tamanhoH] = {};
    int vetI[tamanhoI] = {};

    uniao(vetA, tamanhoA, vetB, tamanhoB, vetC, &tamanhoC);
    inter(vetA, tamanhoA, vetB, tamanhoB, vetD, &tamanhoD);
    dif(vetA, tamanhoA, vetB, tamanhoB, vetE, &tamanhoE);
    dif(vetB, tamanhoB, vetA, tamanhoA, vetF, &tamanhoF);
    subcadeia(vetA, tamanhoA, vetG, &tamanhoG);
    subcadeia(vetB, tamanhoB, vetH, &tamanhoH, '>');
    intercalando(vetA, tamanhoA, vetB, tamanhoB, vetI, &tamanhoI);
    while(true) {
        gotoxy(38,28);
        std::cin >> selected;
        switch (selected) {
            case 0:
                goto L1;
                break;
            case 1:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                imprimirConjunto(vetC, tamanhoC, "União A e B ");
                break;
            case 2:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                imprimirConjunto(vetD, tamanhoD, "Intersecção A e B ");
                break;
            case 3:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                imprimirConjunto(vetE, tamanhoE, "Diferença A e B ");
                break;
            case 4:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                imprimirConjunto(vetF, tamanhoF, "Diferença B e A ");
                break;
            case 5:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                std::cout << "B "
                << (subconjunto(vetA, tamanhoA, vetB, tamanhoB)? "" : "não ")
                << "é subconjunto de A";
                break;
            case 6:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                std::cout << "A "
                << (subconjunto(vetB, tamanhoB, vetA, tamanhoA)? "" : "não ")
                << "é subconjunto de B";
                break;
            case 7:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                std::cout << "Conjuntos "
                << (identicos(vetB, tamanhoB, vetA, tamanhoA)? "" : "não ")
                << "são identicos.";
                break;
            case 8:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                std::cout << "Amplitude de A =" << amplitude(vetA, tamanhoA);
                break;
            case 9:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                std::cout << "Amplitude de B = " << amplitude(vetB, tamanhoB);
                break;
            case 10:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                imprimirConjunto(vetG, tamanhoG, "Maior subcadeia crescente em A ");
                break;
            case 11:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                imprimirConjunto(vetH, tamanhoH, "Maior subcadeia decrescente em B ");
                break;
            case 12:
                gotoxy(37, 22);
                drawH(80,' ');
                gotoxy(37, 22);
                imprimirConjunto(vetI, tamanhoI, "Intercalando de forma crescente ");
            default:
                break;
        }
        gotoxy(38,28);
        drawH(2,' ');
    }
}
