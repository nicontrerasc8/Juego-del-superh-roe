#include "Estrella.h"

Estrella::Estrella()
{
	Tipo = 1;
	x = rand() % 80 + 2;
	y = rand() % 35 + 1;
	w = 1;
	h = 1;
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

Estrella::~Estrella()
{
}

void Estrella::Mover(int WindowWidth, int WindowHeight)
{
	Borrar();
	if (x + dx < 1 || x + dx + w > WindowWidth) dx = dx * -1;
	x = dx + x;
	if (y + dy < 1 || y + dy + h > WindowHeight) dy = dy * -1;
	y = dy + y;
	Imprimir();
}

void Estrella::Imprimir()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	Console::SetCursorPosition(x, y);   cout << "*";
}
