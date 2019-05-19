#pragma once
#include"Graphe.h"
#include<vector>
#include"PriorityQueue.h"
#include"Heuristique.h"

class AlgoRechercheAEtoile
{
private:

	const Graphe& m_Graphe;

	//Contient le coût cumulatif G(n) jusque'au nœud n
	std::vector<double> m_Couts_G; 

	//Contient le coût en ajoutant m_Couts_G[n] à l'heuristique cout de n au noeud ciblé.
	std::vector<double> m_Couts_F;

	std::vector<const Arete*> m_ArbreChemins;
	std::vector<const Arete*> m_RechercheFrontiere;

	int m_iDepart;
	int m_iArrivee;

	//A* algorithme
	void Recherche();

public:

	AlgoRechercheAEtoile(Graphe &graphe,int depart,int arrivee):
	  m_Graphe(graphe),m_ArbreChemins(graphe.NombreNoeuds()),
		  m_RechercheFrontiere(graphe.NombreNoeuds()),m_Couts_G(graphe.NombreNoeuds(), 0.0),
		  m_Couts_F(graphe.NombreNoeuds(), 0.0),m_iDepart(depart),m_iArrivee(arrivee)
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
		return m_Couts_G[m_iArrivee];
	}
};
