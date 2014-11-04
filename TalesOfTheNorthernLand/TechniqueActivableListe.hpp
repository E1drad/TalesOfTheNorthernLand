/*
 * TechniqueActivableListe.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef TECHNIQUEACTIVABLELISTE_HPP_
#define TECHNIQUEACTIVABLELISTE_HPP_

#include "Technique.hpp"

class ValseDesLames : TechniqueActitivableAttaque {
	//8 attaques avec degat*0.33
};

class ExaltationMagie : TechniqueActitivableAttaque {
	//ignore (25 + Attaquant.int/2) % de la sagesse de la cible
};

class DrainDeVie : TechniqueActitivableAttaque {
	// (25 + Attaquant.(Dex || For)/2) % de vol de vie;
};

class Ballestra : TechniqueActitivableAttaque {
	// 1 + Math.floor(Dex/10) attaques * 0.25
};

class BouclierDivin : TechniqueActitivableDefense {
	// (Dex+Cha/10) % de chance d'annuler 50% des degats (+ neutralise ExaltationMagie ?)
};


#endif /* TECHNIQUEACTIVABLELISTE_HPP_ */
