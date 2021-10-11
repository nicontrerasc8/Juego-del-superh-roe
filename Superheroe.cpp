#include "Superheroe.h"

Superheroe::Superheroe()
{
	x = 49;
	y = 25;
	w = 1;
	h = 2;
	dx = 1;
	dy = 0;
}

Superheroe::~Superheroe()
{
}

void Superheroe::Imprimir()
{
	Console::SetCursorPosition(x, y); cout << char(64);
	Console::SetCursorPosition(x, y + 1); cout << char(197);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Superheroe::Mover(int WindowWidth, int WindowHeight)
{
	Borrar();
	if (x + dx < 1 || x + dx + w > WindowWidth) dx = dx * -1;
	if (y + dy < 1 || y + dy + h > WindowHeight) dy = dy * -1;
	x = dx + x;
	y = dy + y;
	Imprimir();
}

void Superheroe::CambiarDireccion(int Cambio)
{
	if (Cambio == 1) {
		dx = -1;
		dy = 0;
	}
	if (Cambio == 2) {
		dx = 0;
		dy = -1;
	}
	if (Cambio == 3) {
		dx = 0;
		dy = 1;
	}
	if (Cambio == 4) {
		dx = 1;
		dy = 0;
	}
}
