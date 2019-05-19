// Tp IA 01.cpp : fichier projet principal.

#include "stdafx.h"
#include "MainFrm.h"

using namespace Pathfinding;
using namespace System;

[STAThreadAttribute]
int main(cli::array<System::String ^> ^args)
{
	// Activation des effets visuels de Windows XP avant la création de tout contrôle
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Créer la fenêtre principale et l'exécuter
	Application::Run(gcnew MainFrm());
	return 0;
}
