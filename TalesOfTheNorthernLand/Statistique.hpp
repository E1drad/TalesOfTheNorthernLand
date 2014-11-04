/*
 * Statistique.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef STATISTIQUE_HPP_
#define STATISTIQUE_HPP_

#include <vector>
#include "Armes.hpp"

class Statistique{
private:
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

public:

	Statistique(std::vector<int> s);
	void updateStatistique();
	std::vector<int> getStatistique();
	std::vector<int>  getStatistiqueDerive();
	int updateDegat(Arme arme);
	int updatePrecision(Arme arme);
	int updateCritique(Arme arme);
	void prendreDegat(int degat, Personnage p);
	void modStat(int stat, int modificateur);
};
#endif /* STATISTIQUE_HPP_ */
