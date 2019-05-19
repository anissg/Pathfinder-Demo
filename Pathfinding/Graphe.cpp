#include "StdAfx.h"
#include "Graphe.h"

Graphe::Graphe(void):m_IndexNoeudProchain(0)
{
}

Graphe::~Graphe(void)
{
}

void Graphe::GenererGrapheGrille(Grille terrain,int nb_col,int nb_lig)
{
	Noeuds.clear();
	Aretes.clear();
	m_IndexNoeudProchain = 0;

	for(Grille::iterator cel = terrain.begin();cel!=terrain.end();cel++)
	{
		AjouterNoeud(Noeud(
				m_IndexNoeudProchain,
				Vecteur2D(cel->Centre_X,cel->Centre_Y)));
	}
	
	for (int i=0; i<nb_lig; i++)
		for (int j=0; j<nb_col; j++)
			AjouterVoisinageNoeudGrille(j, i, nb_col, nb_lig);

}

void Graphe::AjouterVoisinageNoeudGrille(int x, int y,int nb_col,int nb_lig)
{
	for (int i=-1; i<2; ++i)
	{
		for (int j=-1; j<2; ++j)
		{
			if(((i==0) && (j==0))||(i!=0 && j!=0)) 
				continue;

			int noeudX = x+j;
			int noeudY = y+i;

			if (VoisinageValide(noeudX, noeudY, nb_col, nb_lig))
			{
				Vecteur2D PosNoeud = Noeuds[y*nb_col+x].position;
				Vecteur2D PosVoisin = Noeuds[noeudY*nb_col+noeudX].position;

				double dist = PosNoeud.Distance(PosVoisin);

				Arete Arr1(
					y*nb_col+x, 
					noeudY*nb_col+noeudX,
					dist);
				Ajouterarete(Arr1);
			}
		}
	}
}

bool Graphe::VoisinageValide(int x,int y,int nb_col,int nb_lig)
{
	return !((x < 0) || (x >= nb_col) || (y < 0) || (y >= nb_lig));
}

void Graphe::MajGraphe(int x,int y,int nb_col,int nb_lig, bool effacer)
{
	if(effacer)
		EffacerNoeud(y*nb_col+x);
	else
		if(!NoeudPresent(y*nb_col+x))
		{
			ModifierNoeud(y*nb_col+x);
			AjouterVoisinageNoeudGrille(x,y,nb_col,nb_lig);
		}
}

bool Graphe::NoeudPresent(int nd)const
{
	if ( (Noeuds[nd].Index == -1) || (nd >= Noeuds.size()))
    {
		return false;
    }
    else 
		return true;
}

bool Graphe::aretePresente(int deb, int dest)const
{
	if (NoeudPresent(deb) && NoeudPresent(dest))
    {
		for (ListeArete::const_iterator ArrCur = Aretes[deb].begin();ArrCur != Aretes[deb].end();ArrCur++)
        {
          if (ArrCur->dest == dest) 
			  return true;
        }

        return false;
    }
    else 
		return false;
}

const Noeud& Graphe::GetNoeud(int idx)const
{
	return Noeuds[idx];
}

Noeud& Graphe::GetNoeud(int idx)
{
	return Noeuds[idx];
}

const Arete& Graphe::Getarete(int deb, int dest)const
{
	for (ListeArete::const_iterator ArrCur = Aretes[deb].begin();ArrCur != Aretes[deb].end();ArrCur++)
	{
		if (ArrCur->dest == dest) 
			return *ArrCur;
	}
}

Arete& Graphe::Getarete(int deb, int dest)
{
	for (ListeArete::iterator ArrCur = Aretes[deb].begin();ArrCur != Aretes[deb].end();ArrCur++)
	{
		if (ArrCur->dest == dest) 
			return *ArrCur;
	}
}

void Graphe::Ajouterarete(Arete arr)
{
	if ( (Noeuds[arr.dest].Index != -1) && (Noeuds[arr.deb].Index != -1))
	{
		if (areteUnique(arr.deb, arr.dest))
		{
			Aretes[arr.deb].push_back(arr);
		}
		if (areteUnique(arr.dest, arr.deb))
		{
			Arete Narr = arr;

			Narr.dest = arr.deb;
			Narr.deb = arr.dest;

			Aretes[arr.dest].push_back(Narr);
		}
  }
}

void Graphe::ModifierNoeud(int Index)
{
	Noeuds[Index].Index = Index;
}

void Graphe::Effacerarete(int deb, int dest)
{
	ListeArete::iterator ArrCur;
  
	for (ArrCur = Aretes[dest].begin(); ArrCur != Aretes[dest].end();ArrCur++)
	{
		if (ArrCur->dest == deb)
		{
			Aretes[dest].erase(ArrCur);
			break;
		}
	}
	for (ArrCur = Aretes[deb].begin();ArrCur != Aretes[deb].end();ArrCur++)
	{
		if (ArrCur->dest == dest)
		{
			Aretes[dest].erase(ArrCur);
			break;
		}
	}
}

int Graphe::AjouterNoeud(Noeud noeud)
{
	if (noeud.Index < (int)Noeuds.size())
	{
		Noeuds[noeud.Index] = noeud;
		
		return m_IndexNoeudProchain;
	}
	else
	{
		Noeuds.push_back(noeud);
		Aretes.push_back(ListeArete());

		return m_IndexNoeudProchain++;
	}
}

void Graphe::ElimaneraretesInvalides()
{
	for (VecteurListearete::iterator ListeareteCur = Aretes.begin(); ListeareteCur != Aretes.end(); ListeareteCur++)
	{
		for (ListeArete::iterator ArrCur = (*ListeareteCur).begin(); ArrCur != (*ListeareteCur).end(); ++ArrCur)
		{
			if (Noeuds[ArrCur->dest].Index == -1 || Noeuds[ArrCur->deb].Index == -1)
			{
				ArrCur = (*ListeareteCur).erase(ArrCur);
			}
		}
	}
}

void Graphe::EffacerNoeud(int noeud)                                   
{
	Noeuds[noeud].Index = -1;

	for (ListeArete::iterator ArrCur = Aretes[noeud].begin();ArrCur != Aretes[noeud].end(); ArrCur++)
    {
		for (ListeArete::iterator Acur = Aretes[ArrCur->dest].begin();Acur != Aretes[ArrCur->dest].end();Acur++)
		{
			if (Acur->dest == noeud)
			{
				Acur = Aretes[ArrCur->dest].erase(Acur);

				break;
			}
		}
    }
    Aretes[noeud].clear();
}

void Graphe::Coutarete(int deb, int dest, double cout)
{
	for (ListeArete::iterator ArrCur = Aretes[deb].begin();ArrCur != Aretes[deb].end();ArrCur++)
	{
		if (ArrCur->dest == dest)
		{
			ArrCur->cout = cout;
			break;
		}
	}
}

bool Graphe::areteUnique(int deb, int dest) const
{
	for (ListeArete::const_iterator ArrCur = Aretes[deb].begin();ArrCur != Aretes[deb].end();ArrCur++)
	{
		if (ArrCur->dest == dest)
		{
			return false;
		}
	}

	return true;
}

