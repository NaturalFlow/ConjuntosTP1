#include "tela.h"

using namespace std;

const int HEIGHT = 30;
const int WIDTH = 120;
const int LEFT_PADDING = 3;
const int RIGHT_PADDING = 3;
const int TOP_PADDING = 3;

auto gotoxy(int x, int y)->void {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
    //printf("%c[%d;%df",0x1B,y,x);
}
auto drawH(int n, char simbolo)->void {
	for (int i = 0; i < n; i++) {
		cout << simbolo;
	}
}
auto centralizar(string texto, int linha)->void {
    gotoxy((WIDTH/2)-(texto.length()/2),TOP_PADDING+linha);
    cout << texto;
}
auto mensagemDeErro(string texto)->void {
    gotoxy(LEFT_PADDING+11,TOP_PADDING+HEIGHT);
    cout << texto;
}
auto showOptions(string texto1, string texto2, string texto3)->void {
    gotoxy(17,TOP_PADDING+21);
    cout << texto1;
    gotoxy(17,TOP_PADDING+22);
    cout << texto2;
    gotoxy(17,TOP_PADDING+23);
    cout << texto3;
    gotoxy(30,TOP_PADDING+25);
    cout << "Opçao: [  ] 0 - Trocar os conjuntos A e B";
    gotoxy(38,TOP_PADDING+25);
}
auto tela(string titulo)->void {
	//Horizontal  Parte Superior
	gotoxy(LEFT_PADDING,TOP_PADDING);
	drawH(WIDTH-LEFT_PADDING-RIGHT_PADDING+1, '=');
    //Titulo
    centralizar(titulo, 2);
	//Vertical
	gotoxy(LEFT_PADDING,TOP_PADDING+2);
	for(int i = 0; i < HEIGHT; i++) {
		gotoxy(LEFT_PADDING, TOP_PADDING+2+i);
		cout << '=';
		if(i == 2)
            drawH(WIDTH-LEFT_PADDING-RIGHT_PADDING-2, '=');
		//else if (i == 22)
            //drawH(WIDTH-LEFT_PADDING-RIGHT_PADDING-2, '=');
		else if (i == 27)
            drawH(WIDTH-LEFT_PADDING-RIGHT_PADDING-2, '=');
        else if (i == 28)
            cout << "Mensagem: ";
	}
	for(int i = 0; i < HEIGHT; i++) {
		gotoxy(WIDTH-RIGHT_PADDING, TOP_PADDING+2+i);
		cout << '=';
	}
	//Horizontal Parte Inferior
	gotoxy(LEFT_PADDING, TOP_PADDING+HEIGHT+1);
	drawH(WIDTH-LEFT_PADDING-RIGHT_PADDING, '=');
}
