/*
 * GenerateurPersonnage.hpp
 *
 *  Created on: 25 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Personnage.hpp"
#include "Instancieur.hpp"
#include <chrono>
#include <thread>

class GenerateurPersonnage {
private:

public:
	GenerateurPersonnage();
	~GenerateurPersonnage();
	Personnage generePersonnage(Instancieur instancieur);
	Personnage generePersonnage(Instancieur instancieur, Personnage *perso);
};
