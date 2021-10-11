#include "EstrellasYMeteoritos.h"

EstrellasYMeteoritos::EstrellasYMeteoritos()
{
    N = new int;
    *N = 30;
}

EstrellasYMeteoritos::~EstrellasYMeteoritos()
{
    for (int i = 0; i < *N; i++)
        delete ArrObjetos[i];
    delete ArrObjetos;
}

void EstrellasYMeteoritos::Insertar30Estrellas()
{
    Figura** aux = new Figura * [*N];
    for (int i = 0; i < *N; i++)
        aux[i] = new Estrella();
    ArrObjetos = aux;
}

void EstrellasYMeteoritos::InsertarMeteorito()
{
    Figura** aux = new Figura * [*N + 1];
    for (int i = 0; i < *N; i++)
        aux[i] = ArrObjetos[i];
    aux[*N] = new Meteorito();
    *N = *N + 1;
    ArrObjetos = aux;
}

void EstrellasYMeteoritos::MoverArreglo(int WindowWidth, int WindowHeight)
{
    for (int i = 0; i < *N; i++)
    {
        if (ArrObjetos[i]->RetornarTipo() == 1) {
            ((Estrella*)ArrObjetos[i])->Mover(WindowWidth, WindowHeight);
        }
        if (ArrObjetos[i]->RetornarTipo() == 2) {
            ((Meteorito*)ArrObjetos[i])->Mover(WindowWidth, WindowHeight);
        }
    }
}

void EstrellasYMeteoritos::EliminarEnIndice(int indice)
{
    Figura** aux = new Figura * [*N + 1];
    for (int i = 0; i < indice; i++)
        aux[i] = ArrObjetos[i];
    for (int i = indice; i < *N; i++)
        aux[i] = ArrObjetos[i + 1];
    *N = *N - 1;
    ArrObjetos = aux;
}

int EstrellasYMeteoritos::GetN()
{
    return *N;
}

Figura* EstrellasYMeteoritos::RetornarObjeto(int i)
{
    return ArrObjetos[i];
}
