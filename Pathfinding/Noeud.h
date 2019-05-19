#pragma once
#include"Vecteur2D.h"

struct Noeud
{
	int Index;
	Vecteur2D position;

	Noeud(void);
	Noeud(int index,Vecteur2D position);
	~Noeud(void);
};
