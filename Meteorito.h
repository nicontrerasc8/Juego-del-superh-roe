#pragma once
#include "Figura.h"
class Meteorito : public Figura
{
public:
	Meteorito();
	~Meteorito();
	void Imprimir();
	void Mover(int WindowWidth, int WindowHeight);
};

