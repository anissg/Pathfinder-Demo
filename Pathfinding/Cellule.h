#pragma once
#include"TypeCellule.h"
#include<vector>



struct Cellule
{
	TypeCellule Type;
	int Centre_X;
	int Centre_Y;
	int X;
	int Y;
	int Largeur;
	int Hauteur;


	Cellule(void);
	Cellule(int Centre_X,int Centre_Y,int X,int Y,int Largeur,int Hauteur);
	~Cellule(void);
};


typedef std::vector<Cellule> Grille;