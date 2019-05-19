#include "StdAfx.h"
#include "AlgoRechercheLargeur.h"

bool AlgoRechercheLargeur::Recherche()
{
	//creer une file d'Aretes
	std::queue<const Arete*> file;

	//creer une Arete dummy et la mettre dans la file afin qu'on puisse rentrer dans la boucle
	Arete Dummy(m_iDepart, m_iDepart, 0);
	file.push(&Dummy);

	m_Visités[m_iDepart] = visité;

	//continuer à chercher tant qu'il y a des Aretes dans la file
	while (!file.empty())
	{
		//recuperer l'Arete suivante et l'effacer de la file
		const Arete* Suivant = file.front();
		file.pop();

		//noter le parent du nœud sur lequel pointe cette arête
		m_Chemin[Suivant->dest] = Suivant->deb;

		//construire l'arbre de parcours
		if (Suivant != &Dummy)
		{
			m_ArbreParcours.push_back(Suivant);
		}

		//si la cible a été trouvée la méthode peut retourner true
		if (Suivant->dest == m_iArrivee)
		{
			return true;
		}

		//mettre les noeuds a visiter dans la file (ne pas prendre les noeuds deja visités)
		Graphe::ConstAreteIterator ConstAreteItr(m_Graphe, Suivant->dest);

		for(const Arete* pArr = ConstAreteItr.begin();!ConstAreteItr.end();pArr=ConstAreteItr.next())
		{
			if (m_Visités[pArr->dest] == non_visité)
			{
				file.push(pArr);
				//marquer le noeud visité
				m_Visités[pArr->dest] = visité;
			}
		}
	}

	//pas de chemin
	return false;
}


std::list<int> AlgoRechercheLargeur::Chemin()const 
{
	std::list<int> chemin;

	//reourner un chemin vide si aucun chemin n'a été trouvé
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