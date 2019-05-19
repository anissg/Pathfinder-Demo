#include "AlgoRechercheBidirectionnelle.h"


bool AlgoRechercheBidirectionnelle::Recherche()
{

	std::queue<const Arete*> file_dep;
	std::queue<const Arete*> file_arr;

	
	Arete Dummy_dep(m_iDepart, m_iDepart, 0);
	file_dep.push(&Dummy_dep);

	m_Visit�s[m_iDepart] = visit�_dep;

	Arete Dummy_arr(m_iArrivee, m_iArrivee, 0);
	file_arr.push(&Dummy_arr);

	m_Visit�s[m_iArrivee] = visit�_arr;

	while (!file_dep.empty() && !file_arr.empty())
	{
		const Arete* Suivant_dep = file_dep.front();
		file_dep.pop();

		Graphe::ConstAreteIterator ConstAreteItr1(m_Graphe, Suivant_dep->dest);

		for(const Arete* pArr = ConstAreteItr1.begin();!ConstAreteItr1.end();pArr=ConstAreteItr1.next())
		{
			
			if (m_Visit�s[pArr->dest] == non_visit�)
			{
				m_ArbreParcours.push_back(pArr);
				m_Chemin_dep[pArr->dest] = pArr->deb;
				file_dep.push(pArr);
				
				m_Visit�s[pArr->dest] = visit�_dep;
			}
			else if(m_Visit�s[pArr->dest] == visit�_arr)
			{
				m_ArbreParcours.push_back(pArr);
				m_Chemin_dep[pArr->dest] = pArr->deb;

				for(std::vector<const Arete*>::iterator itt = m_ArbreParcours.begin();itt != m_ArbreParcours.end();itt++)
					if((*itt)->dest == pArr->dest)
					{
						m_IndexCommun_arr = (*itt)->deb;
						break;
					}
				m_IndexCommun_dep = pArr->dest;
				return true;
			}
		}
		
		//////////////////////////////////////////////////////////////////////////////////////////////////
			
		const Arete* Suivant_arr = file_arr.front();
		file_arr.pop();

		Graphe::ConstAreteIterator ConstAreteItr2(m_Graphe, Suivant_arr->dest);

		for(const Arete* pArr = ConstAreteItr2.begin();!ConstAreteItr2.end();pArr=ConstAreteItr2.next())
		{
			
			if (m_Visit�s[pArr->dest] == non_visit�)
			{	
				m_ArbreParcours.push_back(pArr);
				m_Chemin_arr[pArr->dest] = pArr->deb;
				file_arr.push(pArr);
				
				m_Visit�s[pArr->dest] = visit�_arr;
			}
			else if(m_Visit�s[pArr->dest] == visit�_dep)
			{
				m_ArbreParcours.push_back(pArr);
				m_Chemin_arr[pArr->dest] = pArr->deb;

				for(std::vector<const Arete*>::iterator itt = m_ArbreParcours.begin();itt != m_ArbreParcours.end();itt++)
					if((*itt)->dest == pArr->dest)
					{
						m_IndexCommun_dep = (*itt)->deb;
						break;
					}
				
				m_IndexCommun_arr = pArr->dest;
				return true;
			}
		}
	}

	//pas de chemin
	return false;
}


std::list<int> AlgoRechercheBidirectionnelle::Chemin()const 
{
	std::list<int> chemin;

	//reourner un chemin vide si aucun chemin n'a �t� trouv�
	if (!m_Trouve || m_iArrivee<0) return chemin;

	//reconstruire le chemin de l�ar�te commune vers le d�part en ins�rant les n�uds
	//au d�but de la liste chemin
	int nd = m_IndexCommun_dep;

	chemin.push_front(nd);

	while (nd != m_iDepart)
	{
		nd = m_Chemin_dep[nd];
		chemin.push_front(nd);
	}

	//reconstruire le chemin de l�ar�te commune vers l�arriv�e en ins�rant les n�uds
	//� la fin de la liste chemin
	nd = m_IndexCommun_arr;
	
	chemin.push_back(nd);

	while (nd != m_iArrivee)
	{
		nd = m_Chemin_arr[nd];
		chemin.push_back(nd);
	}

	return chemin;
}
