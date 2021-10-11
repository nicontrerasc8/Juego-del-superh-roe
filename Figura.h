#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
using namespace System;
class Figura
{
protected:
	int x, y, w, h, dx, dy, Tipo;
public:
	Figura();
	~Figura();
	int RetornarDX();
	int retornar_x();
	int retornar_y();
	int retornar_w();
	int retornar_h();
	void Borrar();
	int RetornarTipo();
};