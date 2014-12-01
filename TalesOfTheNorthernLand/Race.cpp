/*
 * Race.cpp
 *
 *  Created on: 8 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Race.hpp"

	/**
 	 * \brief Constructeur de Race
 	 * \param nR std::string Le nom de la race.
 	 * \param mS std::vector<int> Le vector de stat de la race
 	 */
	Race::Race(std::string nR, std::vector<int> mS){
		this->nomRace = nR;
		this->modificateurStatistique = mS;
	}
	/**
	 * \brief Destructeur de Race
	 */
	Race::~Race(){
		std::cout << "Race is being deleted " << std::endl;
	}

	/**
	 * \brief	getter du vector<sting> de modificateur de stat de la Race
	 * \return 	std::vector<sting> de modificateur de stat de la Race
	 */
	std::vector<int> Race::getmodificateurStatistique(){
		return this->modificateurStatistique;
	}

	/**
	 * \brief	getter du nom de la Race
	 * \return 	std::string le nom de la race
	 */
	std::string Race::getNomRace(){
		return this->nomRace;
	}

	/**
	 * \brief	retour le vector<sting> de modificateur de stat de la Race sous la forme d'une string
	 * \return 	std::sting le vector<sting> de modificateur de stat de la Race en string
	 */
	std::string Race::getmodificateurStatistiqueString(){
		std::string s;
		s = "";
		for(unsigned int i = 0; i < this->modificateurStatistique.size(); ++i ){
			s = s + " " + std::to_string(this->modificateurStatistique.at(i));
		}
		return s;
	}

