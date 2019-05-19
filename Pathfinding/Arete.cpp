#include "StdAfx.h"
#include "Arete.h"

Arete::Arete(void)
{
}

Arete::Arete(int deb,int dest):deb(deb),dest(dest),cout(1.0)
{
}

Arete::Arete(int deb,int dest,double cout):deb(deb),dest(dest),cout(cout)
{
}

Arete::~Arete(void)
{
}

bool Arete::operator ==(const Arete& a)
{
	return (this->deb == a.deb && 
		this->dest == a.dest &&
		this->cout == a.cout);
}

bool Arete::operator !=(const Arete& a)
{
	return !(*this == a);
}