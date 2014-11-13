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
	std::string Race::getNomRace(){
		return this->nomRace;
	}
	std::string Race::getmodificateurStatistiqueString(){
		std::string s;
		s = "";
		for(unsigned int i = 0; i < this->modificateurStatistique.size(); ++i ){
			s = s + " " + std::to_string(this->modificateurStatistique.at(i));
		}
		return s;
	}

