#pragma once
#include"Graphe.h"
#include<vector>
#include<stack>

class AlgoRechercheProfondeur
{
	enum {visité, non_visité, sans_parent};

	const Graphe& m_Graphe;

	std::vector<int> m_Visités;

	// contient l'itinéraire emprunté à la cible. Étant donné un indice de nœud, la valeur
	// à cet index on trouve le parent du nœud.
	std::vector<int> m_Chemin;

	std::vector<const Arete*>  m_ArbreParcours;

	int m_iDepart;
    int m_iArrivee;
	bool m_Trouve;

	bool Recherche();

public:

	AlgoRechercheProfondeur(const Graphe& graphe,int depart,int arrivee):
	  m_Graphe(graphe), m_iDepart(depart), m_iArrivee(arrivee), m_Trouve(false),
		  m_Visités(m_Graphe.NombreNoeuds(), non_visité),
		  m_Chemin(m_Graphe.NombreNoeuds(), sans_parent)
	{ 
		m_Trouve = Recherche(); 
	}

	std::vector<const Arete*> ArbreRecherche()const
	{
		return m_ArbreParcours;
	}

	bool Trouve()const
	{
		return m_Trouve;
	}

	std::list<int> Chemin()const;  
};
