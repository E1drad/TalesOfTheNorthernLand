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

	std::vector<int> statistique;
	std::vector<int> statistiqueReel;
	std::vector<int> statistiqueTemporaire;
	std::vector<int> statistiqueDerive;
	std::vector<int> statistiqueArme;

	void statistiqueArmeAtZero();

public:

	Statistique(std::vector<int> sR, std::vector<int> sT, std::vector<int> sA);
	Statistique(std::vector<int> sR, std::vector<int> sA, bool bonusTemp);
	Statistique(std::vector<int> sR);
	void updateStatistique();
	void resetBonus();
	std::vector<int> getStatistique();
	std::vector<int> getStatistiqueTemporaire();
	std::vector<int> getStatistiqueReel();
	std::vector<int> getStatistiqueDerive();
	void modStatistiqueReel(int mod, int statModifier);
	void modStatistiqueTemporaire(int mod, int statModifier);
	int updateDegat(Arme arme);
	int updatePrecision(Arme arme);
	int updateCritique(Arme arme);
	void prendreDegat(int degat);

};
#endif /* STATISTIQUE_HPP_ */
