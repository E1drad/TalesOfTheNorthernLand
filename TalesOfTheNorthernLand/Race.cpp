/*
 * Race.cpp
 *
 *  Created on: 8 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Race.hpp"

	Race::Race(std::string nR, std::vector<int> mS){
		this->nomRace = nR;
		this->modificateurStatistique = mS;
	}

	Race::~Race(){

	}
	std::vector<int> Race::getmodificateurStatistique(){
		return this->modificateurStatistique;
	}
