#pragma once
#include "Figura.h"
class Superheroe : public Figura
{
public:
	Superheroe();
	~Superheroe();
	void Imprimir();
	void Mover(int WindowWidth, int WindowHeight);
	void CambiarDireccion(int Cambio);
};

