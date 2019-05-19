#include "StdAfx.h"
#include "AlgoRechercheProfondeur.h"

bool AlgoRechercheProfondeur::Recherche()
{
	//creer une pile d'Aretes
	std::stack<const Arete*> pile;

	//creer une Arete dummy et la mettre dans la pile afin qu'on puisse rentrer dans la boucle
	Arete Dummy(m_iDepart, m_iDepart, 0);
	pile.push(&Dummy);

	//continuer à chercher tant qu'il y a des Aretes dans la pile
	while (!pile.empty())
	{
		//recuperer l'Arete suivante et l'effacer de la pile
		const Arete* Suivant = pile.top();
		pile.pop();

		//noter le parent du nœud sur lequel pointe cette arête
		m_Chemin[Suivant->dest] = Suivant->deb;

		//construire l'arbre de parcours
		if (Suivant != &Dummy)
		{
			m_ArbreParcours.push_back(Suivant);
		}

		//marquer le noeud visité
		m_Visités[Suivant->dest] = visité;

		//si la cible a été trouvée la méthode peut retourner true
		if (Suivant->dest == m_iArrivee)
		{
			return true;
		}

		//mettre les noeuds a visiter dans la pile (ne pas prendre les noeuds deja visités)
		Graphe::ConstAreteIterator ConstAreteItr(m_Graphe, Suivant->dest);

		for(const Arete* pArr = ConstAreteItr.begin(); !ConstAreteItr.end(); pArr=ConstAreteItr.next())
		{
			if (m_Visités[pArr->dest] == non_visité)
			{
				pile.push(pArr);
			}
		}
	}

	//pas de chemin
	return false;
}


std::list<int> AlgoRechercheProfondeur::Chemin()const 
{
	std::list<int> chemin;

	//retourner un chemin vide si aucun chemin n'a été trouvé
	if (!m_Trouve || m_iArrivee<0) return chemin;

	int nd = m_iArrivee;

	chemin.push_front(nd);

	while (nd != m_iDepart)
	{
		nd = m_Chemin[nd];
		chemin.push_front(nd);
	}

	return chemin;
}