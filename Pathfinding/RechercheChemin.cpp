#include "RechercheChemin.h"



RechercheChemin::RechercheChemin(void)
{
	m_pGraphe = NULL;
	algorithme_selectionné = TypeAlgo::AucunAlgo;
}

void RechercheChemin::CreerTerrain(int largeur, int hauteur)
{
	_nb_colonnes = largeur;
	_nb_lignes = hauteur;

	float x = 800 / _nb_colonnes;
	float y = 600 / _nb_lignes;
	
	//taille de la cellule
	_espacement = static_cast<int>(x < y ? x : y);
	
	//decalage si nb_col et nb_li n'ont pas le ratio 8/6
	x_decal = (800 - _espacement*_nb_colonnes)/2;
	y_decal = (600 - _espacement*_nb_lignes)/2;

	

	//initialisation des cellules du terrain
	_terrain.clear();
	for(int i=0;i<hauteur;i++)
		for(int j=0;j<largeur;j++)
			_terrain.push_back(Cellule(
				x_decal + j * _espacement + 1 + _espacement/2,
				y_decal + i * _espacement + 1 + _espacement/2,
				x_decal + j * _espacement + 1,
				y_decal + i * _espacement + 1,
				_espacement - 2,
				_espacement - 2));

	//reinitialisation du graphe de recherche
	if(m_pGraphe!=NULL) delete m_pGraphe;
	m_pGraphe = new Graphe();
	m_pGraphe->GenererGrapheGrille(_terrain,_nb_colonnes,_nb_lignes);
	
	//reinitialiser le chemin
	_chemin.clear();

	//reinitialiser le depart et l'arrivée
	index_depart = 0;
	_terrain[index_depart].Type=TypeCellule::Depart;
	index_arrivee = largeur * hauteur - 1;
	_terrain[index_arrivee].Type=TypeCellule::Arrivee;
}

void RechercheChemin::ModifierPosition(int x, int y, TypeCellule type)
{
	//modifier le terrain
	_terrain[y*_nb_colonnes+x].Type = type;
	//modifier le graphe terrain
	switch(type)
	{
	case TypeCellule::Aucun:
		m_pGraphe->MajGraphe(x,y,_nb_colonnes,_nb_lignes,false);
		break;
	case TypeCellule::Obstacle:
		m_pGraphe->MajGraphe(x,y,_nb_colonnes,_nb_lignes,true);
		break;
	}
	//mise à jour algo
	MajAlgorithme();
}

bool RechercheChemin::CellVide(int x, int y)
{
	return _terrain[y*_nb_colonnes+x].Type == TypeCellule::Aucun;
}

void RechercheChemin::EffacerChemin()
{
	_chemin.clear();
	_ArbreRecherche.clear();
}

void RechercheChemin::MajAlgorithme()
{
	switch(algorithme_selectionné)
	{
	case TypeAlgo::AucunAlgo:
		EffacerChemin();
		break;
	case TypeAlgo::AStar:
		RechercheCheminAStar();
		break;
	case TypeAlgo::Largeur:
		RechercheCheminLargeur();
		break;
	case TypeAlgo::Profondeur:
		RechercheCheminProfondeur();
		break;
	case TypeAlgo::Greedy:
		RechercheCheminGreedy();
		break;
	case TypeAlgo::Bidirectionnelle:
		RechercheCheminBidirectionnelle();
		break;
	}
}

void RechercheChemin::ModifierAlgorithme(TypeAlgo type)
{
	algorithme_selectionné = type;
	MajAlgorithme();
}

void RechercheChemin::RechercheCheminProfondeur()
{
	_chemin.clear();
	_ArbreRecherche.clear();

	//timer de precision pour mesurer le temps de clacul
	PrecisionTimer timer; 
	
	timer.Start();
	//effectuer la recherche
	AlgoRechercheProfondeur ARP(*m_pGraphe, index_depart, index_arrivee);
 
	TpsCalc = timer.TimeElapsed();

	//recuperer le chemin si il existe
	if (ARP.Trouve())
	{
		_chemin = ARP.Chemin();
	}

	_ArbreRecherche = ARP.ArbreRecherche();
}

void RechercheChemin::RechercheCheminLargeur()
{
	_chemin.clear();
	_ArbreRecherche.clear();

	//timer de precision pour mesurer le temps de calcul
	PrecisionTimer timer; 
	
	timer.Start();
	//effectuer la recherche
	AlgoRechercheLargeur ARL(*m_pGraphe, index_depart, index_arrivee);
 
	TpsCalc = timer.TimeElapsed();

	//recuperer le chemin si il existe
	if (ARL.Trouve())
	{
		_chemin = ARL.Chemin();
	}

	_ArbreRecherche = ARL.ArbreRecherche();	
}

void RechercheChemin::RechercheCheminAStar()
{
	//timer de precision pour mesurer le temps de calcul
	PrecisionTimer timer; 
	timer.Start();

	//effectuer la recherche
	AlgoRechercheAEtoile AEtoile(*m_pGraphe, index_depart, index_arrivee);
 
	TpsCalc = timer.TimeElapsed();

	_chemin = AEtoile.Chemin();

	_ArbreRecherche = AEtoile.ArbreRecherche();

	CoutChemin = AEtoile.CoutChemin();
}

void RechercheChemin::RechercheCheminGreedy()
{
	//timer de precision pour mesurer le temps de calcul
	PrecisionTimer timer; 
	timer.Start();

	//effectuer la recherche
	AlgoRechercheGreedy ARG(*m_pGraphe, index_depart, index_arrivee);
 
	TpsCalc = timer.TimeElapsed();

	_chemin = ARG.Chemin();

	_ArbreRecherche = ARG.ArbreRecherche();

	CoutChemin = ARG.CoutChemin();
}

void RechercheChemin::RechercheCheminBidirectionnelle()
{
	_chemin.clear();
	_ArbreRecherche.clear();

	//timer de precision pour mesurer le temps de calcul
	PrecisionTimer timer; 
	
	timer.Start();
	//effectuer la recherche
	AlgoRechercheBidirectionnelle ARB(*m_pGraphe, index_depart, index_arrivee);
 
	TpsCalc = timer.TimeElapsed();

	//recuperer le chemin si il existe
	if (ARB.Trouve())
	{
		_chemin = ARB.Chemin();
	}

	_ArbreRecherche = ARB.ArbreRecherche();	
}