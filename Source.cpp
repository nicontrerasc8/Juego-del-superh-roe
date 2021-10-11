#include "Controladora.h"


int main() {
	const int W = 100;
	const int H = 50;
	Controladora* Juego = new Controladora();
	Console::SetWindowSize(W, H);
	Console::CursorVisible = false;

	Juego->InsertarEstrellas();

	while (Juego->RetornarVidas() > 0 && Juego->RetornarCantidadDeEstrellas() > 0)
	{
		if (kbhit()) {
			char t = getch();
			Juego->CambiarDireccionSuperheroe(t);
			flushall();
		}
		Juego->MoverJuego(W, H);
		Juego->InsertarMeteoritos();
		_sleep(50);
	}
	Console::Clear();
	Console::SetCursorPosition(10, 10);
	cout << "La cantidad de estrellas recolectadas: " << Juego->RetornarEstrellasRecolectadas();
	Console::SetCursorPosition(10, 11);
	cout << "La cantidad de estrellas destruidas por los meteoritos es de: " << Juego->RetornarEstrellasDestruidas();
	_sleep(10000);
	getch();
	return 0;
	delete Juego;
}