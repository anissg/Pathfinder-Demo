#include "AlgoRechercheGreedy.h"

void AlgoRechercheGreedy::Recherche()
{
	//créer une file d'attente prioritaire. 
	//Les nœuds avec le plus bas coût H sont positionnés à l'avant.
	IndexedPriorityQLow<double> pq(m_Couts_H, m_Graphe.NombreNoeuds());

	//mettre le noeud de depart dans la file
	pq.insert(m_iDepart);

	//continuer à chercher tant qu'il y a des Aretes dans la file
	while(!pq.empty())
	{
		//obtenir le noeud avec le plus bas coût de la file
		int PlusProcheNoeud = pq.Pop();

		//choisir un noeud de la frontiere
		m_ArbreChemins[PlusProcheNoeud] = m_RechercheFrontiere[PlusProcheNoeud];

		//si la cible a été trouvée la méthode peut retourner true
		if (PlusProcheNoeud == m_iArrivee) 
			return;

		//examiner les noeuds attachés
		Graphe::ConstAreteIterator ConstEdgeItr(m_Graphe, PlusProcheNoeud);

		for (const Arete* pE=ConstEdgeItr.begin();!ConstEdgeItr.end();pE=ConstEdgeItr.next())
		{
			//calculer le coût heuristique de ce nœud à la cible (H)                       
			double Cout_H = Heuristique_Euclid::Calculer(m_Graphe, m_iArrivee, pE->dest); 

			//Si le nœud n'a pas été ajouté à la frontière, l'ajouter et mettre à jour le coût H
			if (m_RechercheFrontiere[pE->dest] == NULL)
			{
				m_Couts_H[pE->dest] = Cout_H;

				pq.insert(pE->dest);

				m_RechercheFrontiere[pE->dest] = pE;
			}

			//si le noeud est déjà sur la frontière, mais le coût pour arriver ici est inferieur à 
			//ce qui a été trouvé auparavant, alors mettre à jour le nœud les coûts et les frontières
			else if ((Cout_H < m_Couts_H[pE->dest]) && (m_ArbreChemins[pE->dest]==NULL))
			{
				m_Couts_H[pE->dest] = Cout_H;

				pq.ChangePriority(pE->dest);

				m_RechercheFrontiere[pE->dest] = pE;
			}
		}
	}
}

std::list<int> AlgoRechercheGreedy::Chemin()const 
{
	std::list<int> chemin;

	//reourner un chemin vide si aucun chemin n'a été trouvé
	if (m_iArrivee < 0)  
		return chemin;    

	int nd = m_iArrivee;

	chemin.push_front(nd);

	while ((nd != m_iDepart) && (m_ArbreChemins[nd] != 0))
	{
		nd = m_ArbreChemins[nd]->deb;

		chemin.push_front(nd);
	}

	return chemin;
}