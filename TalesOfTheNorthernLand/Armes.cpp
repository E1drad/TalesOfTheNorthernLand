/*
 * Armes.cpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Item.cpp"
#include "Armes.hpp"
#include "Personnage.cpp"

class Arme : public Item {
private:
	int type; //epee 0 / lance 2 / hache 4 / sort 6 / arc 8 / heal 10(elle inflige des degat negatif)
	int puissance;
	int precision;
	int critique;
	bool estMagique;
public:

	Arme(std::string nomArme, int type, int puissance, int precision, int critique, bool estMagique){
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

};
