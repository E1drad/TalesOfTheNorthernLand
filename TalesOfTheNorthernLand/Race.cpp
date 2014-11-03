/*
 * Race.cpp
 *
 *  Created on: 8 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Race.hpp"
class Race{

private :
	std::string nomRace;
	std::vector<int> modificateurStatistique;
public :

	Race::Race(std::string nR, std::vector<int> mS){
		this->nomRace = nR;
		this->modificateurStatistique = mS;
	}

	std::vector<int> Race::getmodificateurStatistique(){
		return this->modificateurStatistique;
	}
};