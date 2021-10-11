#pragma once
#include "Estrella.h"
#include "Meteorito.h"
class EstrellasYMeteoritos
{
private:
	Figura** ArrObjetos;
	int* N;
public:
	EstrellasYMeteoritos();
	~EstrellasYMeteoritos();
	void Insertar30Estrellas();
	void InsertarMeteorito();
	void MoverArreglo(int WindowWidth, int WindowHeight);
	void EliminarEnIndice(int i);
	int GetN();
	Figura* RetornarObjeto(int i);
};

