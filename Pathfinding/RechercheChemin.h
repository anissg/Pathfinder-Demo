#pragma once
#include"TypeCellule.h"
#include"TypeAlgo.h"
#include"Cellule.h"
#include<vector>
#include<list>
#include"graphe.h"
#include"PrecisionTimer.h"
#include"AlgoRechercheLargeur.h"
#include"AlgoRechercheProfondeur.h"
#include"AlgoRechercheAEtoile.h"
#include"AlgoRechercheGreedy.h"
#include"AlgoRechercheBidirectionnelle.h"
#include"Vecteur2D.h"

using namespace std;

class RechercheChemin
{	
public:

	Grille _terrain;
	int _nb_lignes;
	int _nb_colonnes;
	int _espacement;
	int x_decal;
	int y_decal;

	int index_depart;
	int index_arrivee;

	list<int> _chemin;
	list<Vecteur2D> _chemin_lisse;
	
	vector<const Arete*> _ArbreRecherche;
	
	double TpsCalc;

	double CoutChemin;

	Graphe* m_pGraphe;

	TypeAlgo algorithme_selectionné;

	RechercheChemin();
	void CreerTerrain(int largeur, int hauteur);
	void ModifierPosition(int x,int y,TypeCellule type);
	bool CellVide(int x, int y);
	
	void EffacerChemin();

	void MajAlgorithme();
	void ModifierAlgorithme(TypeAlgo type);

	//les algorithmes
	void RechercheCheminProfondeur();
	void RechercheCheminLargeur();
	void RechercheCheminAStar();
	void RechercheCheminGreedy();
	void RechercheCheminBidirectionnelle();

	void LissageBSpline()
	{
		if(!_chemin.empty())
		{
			Vecteur2D* cheminTab = new Vecteur2D[_chemin.size()];

			int i = 0;
			for(std::list<int>::iterator itt = _chemin.begin();itt!=_chemin.end();itt++)
			{
				cheminTab[i] = Vecteur2D(_terrain[*(itt)].Centre_X,_terrain[*(itt)].Centre_Y);
				i++;
			}

			_chemin_lisse.push_back(Vecteur2D(_terrain[_chemin.front()].Centre_X, _terrain[_chemin.front()].Centre_Y));

			int size = _chemin.size() - 3;
			for(int i = 0; i <=  size; i++)
			{
				for(float u = 0.0f; u<=1.0f; u += 0.2f)
				{
					_chemin_lisse.push_back( BSplineQuad(u, cheminTab[i], cheminTab[i+1], cheminTab[i+2]) );
				}
			}

			_chemin_lisse.push_back( Vecteur2D(_terrain[_chemin.back()].Centre_X, _terrain[_chemin.back()].Centre_Y));
		}
	}

	Vecteur2D BSplineQuad(float u, Vecteur2D a, Vecteur2D b, Vecteur2D c)
	{
		Vecteur2D p0(a);
		Vecteur2D p1(b);
		Vecteur2D p2(c);

		return (p0 * (1.0f - 2.0f*u + pow(u,2.0f)) + p1 * (1.0f + 2.0f*u - 2.0f*pow(u,2.0f) )+ p2 * (pow(u,2.0f) ) )/2.0f;
	}

	void LissageCatmullRom()
	{
		if(!_chemin.empty())
		{
			Vecteur2D* cheminTab = new Vecteur2D[_chemin.size()+2];

			cheminTab[0] = Vecteur2D(_terrain[_chemin.front()].Centre_X,_terrain[_chemin.front()].Centre_Y);
			cheminTab[_chemin.size()+1] = Vecteur2D(_terrain[_chemin.back()].Centre_X,_terrain[_chemin.back()].Centre_Y);

			int i = 1;
			for(std::list<int>::iterator itt = _chemin.begin();itt!=_chemin.end();itt++)
			{
				cheminTab[i] = Vecteur2D(_terrain[*(itt)].Centre_X,_terrain[*(itt)].Centre_Y);
				i++;
			}

			int size = _chemin.size() - 2;
			for(int i = 0; i <=  size; i++)
			{
				for(float u = 0.0f; u<=1.0f; u += 0.2f)
				{
					_chemin_lisse.push_back( CatmullRom(u, cheminTab[i], cheminTab[i+1], cheminTab[i+2], cheminTab[i+3]) );
				}
			}
		}
	}

	Vecteur2D CatmullRom(float u, Vecteur2D a, Vecteur2D b, Vecteur2D c, Vecteur2D d)
	{
		Vecteur2D p0(a);
		Vecteur2D p1(b);
		Vecteur2D p2(c);
		Vecteur2D p3(d);

		return (p0 * (- u + 2.0f*pow(u,2.0f) - pow(u,3)) + p1 * (2.0f - 5.0f*pow(u, 2.0f) + 3.0f*pow(u,3.0f))+ 
			p2 * (u + 4.0f*pow(u,2.0f) - 3.0f*pow(u,3.0f)) + p3 * (-pow(u,2.0f) + pow(u,3.0f))) * 0.5f;
	}


};