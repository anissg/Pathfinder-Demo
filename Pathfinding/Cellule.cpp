#include "Cellule.h"

Cellule::Cellule(void)
{

}

Cellule::Cellule(int Centre_X,int Centre_Y,int X,int Y,int Largeur,int Hauteur)
{
	this->Centre_X = Centre_X;
	this->Centre_Y = Centre_Y;
	this->X = X;
	this->Y = Y;
	this->Largeur = Largeur;
	this->Hauteur = Hauteur;
	this->Type = TypeCellule::Aucun;
}

Cellule::~Cellule(void)
{
}
