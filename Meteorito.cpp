#include "Meteorito.h"

Meteorito::Meteorito()
{
	Tipo = 2;
	x = rand() % 80 + 2;
	y = rand() % 35 + 1;
	w = 4;
	h = 2;
	int Randomic = rand() % 3;
	if (Randomic == 0) {
		dx = 1;
		dy = 1;
	}
	if (Randomic == 1) {
		dx = 0;
		dy = 1;
	}
	if (Randomic == 2) {
		dx = 1;
		dy = 0;
	}
}

Meteorito::~Meteorito()
{
}

void Meteorito::Imprimir()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Console::SetCursorPosition(x, y);   cout << "(--)";
	Console::SetCursorPosition(x, y+1);   cout << "(--)";
}

void Meteorito::Mover(int WindowWidth, int WindowHeight)
{
	Borrar();
	if (x + dx < 1 || x + dx + w > WindowWidth) dx = dx * -1;
	x = dx + x;
	if (y + dy < 1 || y + dy + h > WindowHeight) dy = dy * -1;
	y = dy + y;
	Imprimir();
}
