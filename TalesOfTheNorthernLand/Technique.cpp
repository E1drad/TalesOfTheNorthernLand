/*
 * Technique.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Technique.hpp"

	Technique::Technique(std::string nomT){
		this->nomTechnique = nomT;
	}

	std::string Technique::getNomTechnique(){
		return nomTechnique;
	}

	Technique::~Technique(){
		std::cout << "Technique is being delete " << std::endl;
	}


/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

	TechniqueStatistique::TechniqueStatistique(std::string nomT, int s):Technique::Technique(nomT){
		this->statToUp = s;
	}

	TechniqueStatistique::~TechniqueStatistique(){
		std::cout << "TechniqueStatistique is being delete " << std::endl;

	}

	int TechniqueStatistique::getStatToUp(){
		return this->statToUp;
	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/




/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

