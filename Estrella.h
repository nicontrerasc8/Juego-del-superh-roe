#pragma once
#include "Figura.h"
class Estrella : public Figura 
{
public:
	Estrella();
	~Estrella();
	void Mover(int WindowWidth, int WindowHeight);
	void Imprimir();
};

