#pragma once
#include"Graphe.h"
#include"Vecteur2D.h"

class Heuristique_Euclid 
{
public:

	static double Calculer(const Graphe& G, int nd1, int nd2)
	{
		return Vec2DDistance(G.GetNoeud(nd1).position, G.GetNoeud(nd2).position);
	}
};