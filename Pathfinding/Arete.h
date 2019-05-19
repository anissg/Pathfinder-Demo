#pragma once

struct Arete
{
	int deb;
	int dest;
	double cout;

	Arete(void);
	Arete(int deb,int dest);
	Arete(int deb,int dest,double cout);
	~Arete(void);

	bool operator == (const Arete& a);
	bool operator != (const Arete& a);
};
