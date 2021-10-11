#include "Figura.h"

Figura::Figura()
{
}

Figura::~Figura()
{
}


int Figura::RetornarDX()
{
    return dx;
}

int Figura::retornar_x()
{
    return x;
}

int Figura::retornar_y()
{
    return y;
}

int Figura::retornar_w()
{
    return w;
}

int Figura::retornar_h()
{
    return h;
}

void Figura::Borrar()
{
    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++)
        {
            Console::SetCursorPosition(i, j);
            cout << ' ';
        }
}

int Figura::RetornarTipo()
{
    return Tipo;
}

