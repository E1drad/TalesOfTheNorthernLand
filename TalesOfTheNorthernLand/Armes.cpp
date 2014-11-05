/*
 * Armes.cpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Armes.hpp"

//class Arme : public Item

	Arme::Arme(std::string nomArme, int type, int puissance, int precision, int critique, bool estMagique){
		this->critique = critique;
		this->type = type;
		this->nomItem = nomArme;
		this->precision = precision;
		this->puissance = puissance;
		this->estMagique = estMagique;
	}

	int getDegat(){
		return this->puissance;
	}

	int getPrecision(){
		return this->precision;
	}

	int getCritique(){
		return this->critique;
	}

	bool getEstMagique(){
		return this->estMagique;
	}

