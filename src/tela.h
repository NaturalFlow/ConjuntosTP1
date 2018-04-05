#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

#include <iostream>
#include <string>
#include "windows.h"

auto gotoxy(int x, int y)->void;
auto drawH(int n, char simbolo)->void;
auto centralizar(std::string texto, int linha)->void;
auto mensagemDeErro(std::string texto)->void;
auto showOptions(std::string texto1, std::string texto2, std::string texto3)->void;
auto tela(std::string titulo)->void;

#endif // TELA_H_INCLUDED
