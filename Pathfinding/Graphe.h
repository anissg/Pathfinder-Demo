#pragma once
#include"Noeud.h"
#include"Arete.h"
#include"Cellule.h"
#include<vector>
#include<list>



class Graphe
{

public:
	
	typedef std::vector<Noeud>         VecteurNoeud;
	typedef std::list<Arete>           ListeArete;
	typedef std::vector<ListeArete>    VecteurListearete;

	
	//l'index du noeud prochain à ajouter
	int m_IndexNoeudProchain;
	
	VecteurNoeud        Noeuds;
	VecteurListearete   Aretes;


	Graphe(void);
	~Graphe(void);

	//methodes pour la grille
	void GenererGrapheGrille(Grille terrain,int nb_col,int nb_lig);
	void AjouterVoisinageNoeudGrille(int x,int y,int nb_col,int nb_lig);
	bool VoisinageValide(int x,int y,int nb_col,int nb_lig); 
	void MajGraphe(int x,int y,int nb_col,int nb_lig,bool effacer);

	//methodes pour le graphe
	bool areteUnique(int a, int dest)const;
	void ElimaneraretesInvalides();

	const Noeud& GetNoeud(int index)const;
	Noeud& GetNoeud(int index);

	const Arete& Getarete(int a, int dest)const;
	Arete& Getarete(int a, int dest);

	int AjouterNoeud(Noeud noeud);
	void ModifierNoeud(int Index);
	void EffacerNoeud(int Index);

	void Ajouterarete(Arete Arete);
	void Effacerarete(int a, int dest);
	void Coutarete(int a, int dest, double cout);

	int NombreNoeuds()const{return Noeuds.size();}
	int   NombreNoeudsActive()const
	{
		int count = 0;

		for (int i=0; i<Noeuds.size(); i++) 
			if (Noeuds[i].Index != -1) 
				count++;

		return count;
	}

	int Nombrearetes()const
	{
		int nba = 0;

		for (VecteurListearete::const_iterator ArrCur = Aretes.begin();ArrCur != Aretes.end();ArrCur++)
		{
			nba += ArrCur->size();
		}

		return nba;
	}

	bool Vide()const
	{
		return Noeuds.empty();
	}

	bool NoeudPresent(int nd)const;

	bool aretePresente(int a, int dest)const;

	void Vider()
	{
		m_IndexNoeudProchain = 0; 
		Noeuds.clear(); 
		Aretes.clear();
	}

	void Videraretes()
	{
		for (VecteurListearete::iterator it = Aretes.begin(); it != Aretes.end(); it++)
		{
			it->clear();
		}
	}

	//Classe utilisée pour itterer sur tous les Aretes connectées à un noeud spécifique.
	class ConstAreteIterator
	{
	private:                                                                
		ListeArete::const_iterator ArrCur;
		const Graphe& G;
		const int IndexNoeud;
	public:

		ConstAreteIterator(const Graphe& graphe,int noeud): G(graphe),IndexNoeud(noeud)
		{
			ArrCur = G.Aretes[IndexNoeud].begin();
		}

		const Arete*  begin()
		{        
			ArrCur = G.Aretes[IndexNoeud].begin();
			return &(*ArrCur);
		}

		const Arete*  next()
		{
			++ArrCur;

			if(ArrCur != G.Aretes[IndexNoeud].end())
				return &(*ArrCur);

			return nullptr;
		}

		//retourne true si nous sommes à la fin de la liste des noeuds
		bool end()
		{
			return (ArrCur == G.Aretes[IndexNoeud].end());
		}
	};

	friend class ConstAreteIterator;
};
