#pragma once
#include<vector>

template<class T>
class IndexedPriorityQLow
{
private:

	std::vector<T>& m_vecCouts_F;

	std::vector<int> m_IndexNoeud;

	std::vector<int> m_IndexNoeudInverse;

	int m_iTaille, m_iTailleMax;

	void Permute(int a, int b)
	{
		int temp = m_IndexNoeud[a]; 
		m_IndexNoeud[a] = m_IndexNoeud[b]; 
		m_IndexNoeud[b] = temp;

		m_IndexNoeudInverse[m_IndexNoeud[a]] = a; 
		m_IndexNoeudInverse[m_IndexNoeud[b]] = b;
	}

	void ReorganiserOrdreCroissant(int nd)
	{
		//deplacer vers l'avant jusqu'à ce que le tas soit trié
		while ( (nd>1) && (m_vecCouts_F[m_IndexNoeud[nd/2]] > m_vecCouts_F[m_IndexNoeud[nd]]) )
		{      
			Permute(nd/2, nd);
			nd /= 2;
		}
	}

	void ReorganiserOrdreDecroissant(int nd, int TailleTas)
	{
		while (2*nd <= TailleTas)
		{
			int child = 2 * nd;

			if ((child < TailleTas) && (m_vecCouts_F[m_IndexNoeud[child]] > m_vecCouts_F[m_IndexNoeud[child+1]]))
			{
				++child;
			}

			if (m_vecCouts_F[m_IndexNoeud[nd]] > m_vecCouts_F[m_IndexNoeud[child]])
			{
				Permute(child, nd);

				nd = child;
			}
			else
			{
				break;
			}
		}
	}


public:
  
	IndexedPriorityQLow(std::vector<T>& cles,int TailleMax):m_vecCouts_F(cles),
		m_iTailleMax(TailleMax),m_iTaille(0)
	{
		m_IndexNoeud.assign(TailleMax+1,0);
		m_IndexNoeudInverse.assign(TailleMax+1,0);
	}

	bool empty()const
	{
		return (m_iTaille==0);
	}

	//les éléments ajoutés dans la file sont toujours mis à la fin.
	//il faut donc trier la file.
	void insert(const int idx)
	{
		m_iTaille++;

		m_IndexNoeud[m_iTaille] = idx;

		m_IndexNoeudInverse[idx] = m_iTaille;

		ReorganiserOrdreCroissant(m_iTaille);
	}

	//pour obtenir l'item min le premier élément est échangé avec le plus bas
	//ensuite le tas est réorganisé à partir du haut vers le bas.
	int Pop()
	{
		Permute(1, m_iTaille);

		ReorganiserOrdreDecroissant(1, m_iTaille-1);

		return m_IndexNoeud[m_iTaille--];
	}

	void ChangePriority(const int idx)
	{
		ReorganiserOrdreCroissant(m_IndexNoeudInverse[idx]);
	}
};