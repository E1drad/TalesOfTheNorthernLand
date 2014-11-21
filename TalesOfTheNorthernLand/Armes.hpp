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
protected:
	int type; //epee 0 / lance 1 / sort 2
	int puissance;
	int precision;
	int critique;
	bool estMagique;
	int prix;
public:
	Arme(std::string nomArme, int type, int puissance, int precision, int critique, bool estMagique, int prix);
	virtual ~Arme() = 0;
	int getType();
	int getDegat();
	int getPrecision();
	int getCritique();
	int getPrix();
	bool getEstMagique();
	void afficher();
	void modNomItem(std::string s);
	void modDegat(int a);
	void modPrecision(int a);
	void modCritique(int a);
};

class Epee : public Arme{
public:
	Epee(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix);
	~Epee();
};

class Lance : public Arme{
public:
	Lance(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix);
	~Lance();
};

class Sort : public Arme{
public:
	Sort(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix);
	~Sort();
};

class Decorator : public Arme {
protected:
	Arme* arme;
public:
	Decorator(Arme* arme);
	virtual ~Decorator() = 0;
};

class AmeliorationDegat : public Decorator {
public:
	AmeliorationDegat(Arme* arme);
	~AmeliorationDegat();
};

class AmeliorationPrecision : public Decorator {
public:
	AmeliorationPrecision(Arme* arme);
	~AmeliorationPrecision();
};

class AmeliorationCritique : public Decorator {
public:
	AmeliorationCritique(Arme* arme);
	~AmeliorationCritique();
};

#endif /* ARME_HPP_ */
