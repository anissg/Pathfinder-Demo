// Tp IA 01.cpp�: fichier projet principal.

#include "stdafx.h"
#include "MainFrm.h"

using namespace Pathfinding;
using namespace System;

[STAThreadAttribute]
int main(cli::array<System::String ^> ^args)
{
	// Activation des effets visuels de Windows�XP avant la cr�ation de tout contr�le
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Cr�er la fen�tre principale et l'ex�cuter
	Application::Run(gcnew MainFrm());
	return 0;
}
