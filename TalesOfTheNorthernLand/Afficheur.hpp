/*
 * Afficheur.hpp
 *
 *  Created on: 19 nov. 2014
 *      Author: Charles BEGAUDEAU
 */


#ifndef AFFICHEUR_HPP_
#define AFFICHEUR_HPP_

#include <vector>
#include <string>
#include "Personnage.hpp"
#include "Marchand.hpp"

class Afficheur {
private :

public :
	Afficheur();
	~Afficheur();
	void afficherPersos(Personnage *perso1, Personnage *perso2);
	void afficherPerso(Personnage *perso1);
	//void afficherMenu();
	//void afficherMagasin();
	//int controleurEntrer();

};

#endif /* AFFICHEUR_HPP_ */
