#include "StdAfx.h"
#include "AlgoRechercheAEtoile.h"

void AlgoRechercheAEtoile::Recherche()
{
	//cr�er une file d'attente prioritaire. 
	//Les n�uds avec le plus bas co�t global F (G + H) sont positionn�s � l'avant.
	IndexedPriorityQLow<double> pq(m_Couts_F, m_Graphe.NombreNoeuds());

	//mettre le noeud de depart dans la file
	pq.insert(m_iDepart);

	//continuer � chercher tant qu'il y a des Aretes dans la file
	while(!pq.empty())
	{
		//obtenir le noeud avec le plus bas co�t de la file
		int PlusProcheNoeud = pq.Pop();

		//choisir un noeud de la frontiere
		m_ArbreChemins[PlusProcheNoeud] = m_RechercheFrontiere[PlusProcheNoeud];

		//si la cible a �t� trouv�e la m�thode peut retourner true
		if (PlusProcheNoeud == m_iArrivee) 
			return;

		//examiner les noeuds attach�s
		Graphe::ConstAreteIterator ConstEdgeItr(m_Graphe, PlusProcheNoeud);

		for (const Arete* pE=ConstEdgeItr.begin();!ConstEdgeItr.end();pE=ConstEdgeItr.next())
		{
			//calculer le co�t heuristique de ce n�ud � la cible (H)                       
			double Cout_H = Heuristique_Euclid::Calculer(m_Graphe, m_iArrivee, pE->dest); 

			//calculer le co�t � ce n�ud de la source (G)
			double Cout_G = m_Couts_G[PlusProcheNoeud] + pE->cout;

			//Si le n�ud n'a pas �t� ajout� � la fronti�re, l'ajouter et mettre � jour les co�ts G et F
			if (m_RechercheFrontiere[pE->dest] == NULL)
			{
				m_Couts_F[pE->dest] = Cout_G + Cout_H;
				m_Couts_G[pE->dest] = Cout_G;

				pq.insert(pE->dest);

				m_RechercheFrontiere[pE->dest] = pE;
			}

			//si le noeud est d�j� sur la fronti�re, mais le co�t pour arriver ici est inferieur � 
			//ce qui a �t� trouv� auparavant, alors mettre � jour le n�ud les co�ts et les fronti�res
			else if ((Cout_G < m_Couts_G[pE->dest]) && (m_ArbreChemins[pE->dest]==NULL))
			{
				m_Couts_F[pE->dest] = Cout_G + Cout_H;
				m_Couts_G[pE->dest] = Cout_G;

				pq.ChangePriority(pE->dest);

				m_RechercheFrontiere[pE->dest] = pE;
			}
		}
	}
}

std::list<int> AlgoRechercheAEtoile::Chemin()const 
{
	std::list<int> chemin;

	//reourner un chemin vide si aucun chemin n'a �t� trouv�
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