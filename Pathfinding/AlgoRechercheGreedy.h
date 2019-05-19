#pragma once
#include"Graphe.h"
#include<vector>
#include"PriorityQueue.h"
#include"Heuristique.h"

class AlgoRechercheGreedy
{
public:
	private:

	const Graphe& m_Graphe;

	//Contient le coût de l'heuristique euclidienne.
	std::vector<double> m_Couts_H;

	std::vector<const Arete*> m_ArbreChemins;
	std::vector<const Arete*> m_RechercheFrontiere;

	int m_iDepart;
	int m_iArrivee;

	//Greedy algorithme
	void Recherche();

public:

	AlgoRechercheGreedy(Graphe &graphe,int depart,int arrivee):
	  m_Graphe(graphe),m_ArbreChemins(graphe.NombreNoeuds()),
		  m_RechercheFrontiere(graphe.NombreNoeuds()),
		  m_Couts_H(graphe.NombreNoeuds(), 0.0),
		  m_iDepart(depart),m_iArrivee(arrivee)
	{
		Recherche();
	}
 
	std::vector<const Arete*> ArbreRecherche()const
	{
		return m_ArbreChemins;
	}

	std::list<int> Chemin()const;

	double CoutChemin()const
	{
		return m_Couts_H[m_iArrivee];
	}
};