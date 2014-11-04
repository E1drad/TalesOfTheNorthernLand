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



