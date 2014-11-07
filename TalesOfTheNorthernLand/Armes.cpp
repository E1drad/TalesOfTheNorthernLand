/*
 * Armes.cpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Armes.hpp"

//class Arme : public Item

	Arme::Arme(std::string nomArme, int type, int puissance, int precision, int critique, bool estMagique){
		Item::Item(nomArme);
		this->critique = critique;
		this->type = type;
		//this->nomItem = nomArme;
		this->precision = precision;
		this->puissance = puissance;
		this->estMagique = estMagique;
	}

	Arme::~Arme(){

	}

	int Arme::getDegat(){
		return this->puissance;
	}

	int Arme::getPrecision(){
		return this->precision;
	}

	int Arme::getCritique(){
		return this->critique;
	}

	bool Arme::getEstMagique(){
		return this->estMagique;
	}
	void doNothing(){}

