#pragma once
#include"Graphe.h"
#include<vector>
#include<queue>

class AlgoRechercheBidirectionnelle
{
	enum {visité_dep,visité_arr, non_visité, sans_parent=-1};

	const Graphe& m_Graphe;

	std::vector<int> m_Visités;

	
	std::vector<int> m_Chemin_dep;
	std::vector<int> m_Chemin_arr;

	std::vector<const Arete*>  m_ArbreParcours;

	int m_iDepart;
    int m_iArrivee;
	int m_IndexCommun_dep;
	int m_IndexCommun_arr;
	bool m_Trouve;

	bool Recherche();

public:

	AlgoRechercheBidirectionnelle(const Graphe& graphe,int depart,int arrivee):
	  m_Graphe(graphe), m_iDepart(depart), m_iArrivee(arrivee), m_Trouve(false),
		  m_Visités(m_Graphe.NombreNoeuds(), non_visité),
		  m_IndexCommun_dep(0),m_IndexCommun_arr(0),
		  m_Chemin_dep(m_Graphe.NombreNoeuds(), sans_parent),
		  m_Chemin_arr(m_Graphe.NombreNoeuds(), sans_parent)
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