/*
 * Personnage.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef PERSONNAGE_HPP_
#define PERSONNAGE_HPP_

#include "string"
#include "Statistique.hpp"
#include "Classe.hpp"
#include "Race.hpp"
#include "Item.hpp"
#include "ZoneDeDeplacement.hpp"

class Personnage {
private :
	Statistique statistique;
	std::string nom;
	ClasseHeroique classeHeroique;
	ClasseParagon classeParagon;
	ClasseDivine classeDivine;
	Race race;
	bool estFemme;
	Item inventaire[5];
	Arme armeEquiper;
	ZoneDeDeplacement zoneDeDeplacement;
	ZoneAction zoneAction;
	Technique technique[5];

	void modificateurRace();
	void modificateurClasse();
	void equiperPremierArme();
public :

	void attaquer(Personnage &cible);
	void seFaireAttaquer(int degat, Personnage &attaquant);
	void setArmeEquiper(Arme a);
	Personnage(Statistique s, std::string n, ClasseHeroique c, Race r, bool estFemme, Item i[5], ZoneDeDeplacement zdd, ZoneAction za, Technique t[5]);
	Personnage(Statistique s, std::string n, ClasseHeroique c, Race r, bool estFemme);
	Classe getClasse();
	bool getEstFemme();
	Item getInventaire();
	Arme getArmeEquiper();
	std::string getNom();
	Race getRace();
	Statistique getStatistique();
	Technique getTechnique();
	ZoneAction getZoneAction();
	ZoneDeDeplacement getZoneDeDeplacement();
};



#endif /* PERSONNAGE_HPP_ */
