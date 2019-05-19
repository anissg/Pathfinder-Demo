#include "StdAfx.h"
#include "AlgoRechercheLargeur.h"

bool AlgoRechercheLargeur::Recherche()
{
	//creer une file d'Aretes
	std::queue<const Arete*> file;

	//creer une Arete dummy et la mettre dans la file afin qu'on puisse rentrer dans la boucle
	Arete Dummy(m_iDepart, m_iDepart, 0);
	file.push(&Dummy);

	m_Visit�s[m_iDepart] = visit�;

	//continuer � chercher tant qu'il y a des Aretes dans la file
	while (!file.empty())
	{
		//recuperer l'Arete suivante et l'effacer de la file
		const Arete* Suivant = file.front();
		file.pop();

		//noter le parent du n�ud sur lequel pointe cette ar�te
		m_Chemin[Suivant->dest] = Suivant->deb;

		//construire l'arbre de parcours
		if (Suivant != &Dummy)
		{
			m_ArbreParcours.push_back(Suivant);
		}

		//si la cible a �t� trouv�e la m�thode peut retourner true
		if (Suivant->dest == m_iArrivee)
		{
			return true;
		}

		//mettre les noeuds a visiter dans la file (ne pas prendre les noeuds deja visit�s)
		Graphe::ConstAreteIterator ConstAreteItr(m_Graphe, Suivant->dest);

		for(const Arete* pArr = ConstAreteItr.begin();!ConstAreteItr.end();pArr=ConstAreteItr.next())
		{
			if (m_Visit�s[pArr->dest] == non_visit�)
			{
				file.push(pArr);
				//marquer le noeud visit�
				m_Visit�s[pArr->dest] = visit�;
			}
		}
	}

	//pas de chemin
	return false;
}


std::list<int> AlgoRechercheLargeur::Chemin()const 
{
	std::list<int> chemin;

	//reourner un chemin vide si aucun chemin n'a �t� trouv�
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