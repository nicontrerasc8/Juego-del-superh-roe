#include "Controladora.h"

Controladora::Controladora()
{
	VidasSuper = 5;
	EstrellasRecolectadas = 0;
	EstrellasDestruidas = 0;
	ObjSuper = new Superheroe();
	ArrObjetos = new EstrellasYMeteoritos();
	TiempoInsertarMeteoritos = time(0);
	TiempoDeGracia = time(0);
}

Controladora::~Controladora()
{
	delete ObjSuper;
}

void Controladora::MoverJuego(int WindowWidth, int WindowHeight)
{
	if (VidasSuper > 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	if(VidasSuper <= 3 && VidasSuper > 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	if(VidasSuper == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	ObjSuper->Mover(WindowWidth, WindowHeight);
	ArrObjetos->MoverArreglo(WindowWidth, WindowHeight);
	ColisionSuperHeroe();
	ColisionEstrellaMeteorito();
}

void Controladora::CambiarDireccionSuperheroe(char tecla)
{
	if (tecla == '75' || tecla == 75) ObjSuper->CambiarDireccion(1);
	if (tecla == '72' || tecla == 72) ObjSuper->CambiarDireccion(2);
	if (tecla == '80' || tecla == 80) ObjSuper->CambiarDireccion(3);
	if (tecla == '77' || tecla == 77) ObjSuper->CambiarDireccion(4);
}

void Controladora::InsertarEstrellas()
{
	ArrObjetos->Insertar30Estrellas();
}

void Controladora::InsertarMeteoritos()
{
	if (difftime(time(0), TiempoInsertarMeteoritos) > 2) {
		ArrObjetos->InsertarMeteorito();
		TiempoInsertarMeteoritos = time(0);
	}
}

void Controladora::ColisionSuperHeroe()
{
	System::Drawing::Rectangle r1;
	r1.X = ObjSuper->retornar_x();
	r1.Y = ObjSuper->retornar_y();
	r1.Width = ObjSuper->retornar_w();
	r1.Height = ObjSuper->retornar_h();
	for (int i = 0; i < ArrObjetos->GetN(); i++)
	{
		System::Drawing::Rectangle r2;
		r2.X = ArrObjetos->RetornarObjeto(i)->retornar_x();
		r2.Y = ArrObjetos->RetornarObjeto(i)->retornar_y();
		r2.Width = ArrObjetos->RetornarObjeto(i)->retornar_w();
		r2.Height = ArrObjetos->RetornarObjeto(i)->retornar_h();
		if (r1.IntersectsWith(r2)) {
			if (ArrObjetos->RetornarObjeto(i)->RetornarTipo() == 1) {
				++EstrellasRecolectadas;
				ArrObjetos->RetornarObjeto(i)->Borrar();
				ArrObjetos->EliminarEnIndice(i);
			}	
			else if (ArrObjetos->RetornarObjeto(i)->RetornarTipo() == 2 &&
				difftime(time(0), TiempoDeGracia) > 1) {
				--VidasSuper;
				TiempoDeGracia = time(0);
			}
		}
	}
}

void Controladora::ColisionEstrellaMeteorito()
{
	for (int k = 0; k < ArrObjetos->GetN(); k++)
	{
		System::Drawing::Rectangle r1;
		r1.X = ArrObjetos->RetornarObjeto(k)->retornar_x();
		r1.Y = ArrObjetos->RetornarObjeto(k)->retornar_y();
		r1.Width = ArrObjetos->RetornarObjeto(k)->retornar_w();
		r1.Height = ArrObjetos->RetornarObjeto(k)->retornar_h();
		for (int i = 0; i < ArrObjetos->GetN(); i++)
		{
			System::Drawing::Rectangle r2;
			r2.X = ArrObjetos->RetornarObjeto(i)->retornar_x();
			r2.Y = ArrObjetos->RetornarObjeto(i)->retornar_y();
			r2.Width = ArrObjetos->RetornarObjeto(i)->retornar_w();
			r2.Height = ArrObjetos->RetornarObjeto(i)->retornar_h();
			if (r1.IntersectsWith(r2) && ArrObjetos->RetornarObjeto(k)->RetornarTipo() == 1 && ArrObjetos->RetornarObjeto(i)->RetornarTipo() == 2) {
					++EstrellasDestruidas;
					ArrObjetos->RetornarObjeto(k)->Borrar();
					ArrObjetos->EliminarEnIndice(k);
			}
		}
	}
}

int Controladora::RetornarCantidadDeEstrellas()
{
	int c = 0;
	for (int i = 0; i < ArrObjetos->GetN(); i++)
	{
		if (ArrObjetos->RetornarObjeto(i)->RetornarTipo() == 1) ++c;
	}
	return c;
}

int Controladora::RetornarVidas()
{
	return VidasSuper;
}

int Controladora::RetornarEstrellasRecolectadas()
{
	return EstrellasRecolectadas;
}

int Controladora::RetornarEstrellasDestruidas()
{
	return EstrellasDestruidas;
}
