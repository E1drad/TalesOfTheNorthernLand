/*
 * Personnage.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef PERSONNAGE_HPP_
#define PERSONNAGE_HPP_

#include <string>
//#include "Statistique.hpp"
#include "Classe.hpp"
#include "Race.hpp"
#include "Item.hpp"
#include "Armes.hpp"
//#include "ZoneDeDeplacement.hpp"
#include <vector>
#include <iostream>

class Personnage {
private :

	std::string nom;
	ClasseHeroique classeHeroique;
	ClasseParagon classeParagon;
	ClasseDivine classeDivine;
	Race race;
	bool estFemme;
	Arme armeEquiper;
	/* int pointDexp;		0 | int pointDeVie;		1
	 * int pointDeVieMax;	2 | int force;			3
	 * int intelligence;	4 | int dexterite;		5
	 * int agilite;			6 | int chance;			7
	 * int armure;			8 | int sagesse;		9
	 */
	std::vector<int> statistique;

	/* int degat;		0 |	int precision;		1
	 * int esquive;		2 |	int critique;		3
	 */
	std::vector<int> statistiqueDerive;

	/* TODO finir le personnage de base puis ajouter UN PAR UN les elements suivants
	 * Statistique statistique;
	 * Item inventaire[5];
	 * ZoneDeDeplacement zoneDeDeplacement;
	 * ZoneAction zoneAction;
	 * Technique technique[5];
	 */

	void modificateurRace();
	void modificateurClasse();
	//void equiperPremierArme();

public :

	Personnage(std::vector<int> s, std::string n, ClasseHeroique c, Race r, bool estFemme);
	void attaquer(Personnage &cible);
	void seFaireAttaquer(int degat, Personnage &attaquant);
	void setArmeEquiper(Arme a);
	Race getRace();
	std::string getNom();
	Classe getClasseActuelle();
	bool getEstFemme();

	void updateStatistique();
	std::vector<int> getStatistique();
	std::vector<int>  getStatistiqueDerive();
	int updateDegat();
	int updatePrecision();
	int updateCritique();
	void modStat(int stat, int modificateur);
	void estMort(); // TODO need update
	/*
	 * Item getInventaire();
	 * Arme getArmeEquiper();
	 * Technique getTechnique();
	 * ZoneAction getZoneAction();
	 * ZoneDeDeplacement getZoneDeDeplacement();
	 */
};



#endif /* PERSONNAGE_HPP_ */
