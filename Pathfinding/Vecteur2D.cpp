#include "Vecteur2D.h"

Vecteur2D::Vecteur2D(void):x(0),y(0)
{
}

Vecteur2D::Vecteur2D(int x, int y):x(x),y(y)
{
}

Vecteur2D::Vecteur2D(const Vecteur2D &v):x(v.x),y(v.y)
{
}
