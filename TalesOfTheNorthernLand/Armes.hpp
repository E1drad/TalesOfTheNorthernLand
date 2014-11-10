/*
 * Arme.hpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef ARME_HPP_
#define ARME_HPP_

#include <string>
#include "Item.hpp"

class Arme : public Item {
private:
	int type; //epee 0 / lance 2 / hache 4 / sort 6 / arc 8 / heal 10(elle inflige des degat negatif)
	int puissance;
	int precision;
	int critique;
	bool estMagique;
public:
	Arme(std::string nomArme, int type, int puissance, int precision, int critique, bool estMagique);
	~Arme();
	int getType();
	int getDegat();
	int getPrecision();
	int getCritique();
	bool getEstMagique();
	void doNothing();

};

#endif /* ARME_HPP_ */
