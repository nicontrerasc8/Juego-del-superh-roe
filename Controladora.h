#pragma once
#include "Superheroe.h"
#include "EstrellasYMeteoritos.h"
class Controladora
{
private:
	Superheroe* ObjSuper;
	EstrellasYMeteoritos* ArrObjetos;
	time_t TiempoInsertarMeteoritos;
	time_t TiempoDeGracia;
	int VidasSuper, EstrellasRecolectadas, EstrellasDestruidas;
public:
	Controladora();
	~Controladora();
	void MoverJuego(int WindowWidth, int WindowHeight);
	void CambiarDireccionSuperheroe(char tecla);
	void InsertarEstrellas();
	void InsertarMeteoritos();
	void ColisionSuperHeroe();
	void ColisionEstrellaMeteorito();
	int RetornarCantidadDeEstrellas();
	int RetornarVidas();
	int RetornarEstrellasRecolectadas();
	int RetornarEstrellasDestruidas();
};

