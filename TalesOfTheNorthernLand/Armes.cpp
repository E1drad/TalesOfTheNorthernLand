/*
 * Armes.cpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Armes.hpp"

//class Arme : public Item

	Arme::Arme(std::string nomArme, int type, int puissance, int precision, int critique, bool estMagique, int prix): Item::Item(nomArme){
		this->critique = critique;
		this->type = type;
		this->precision = precision;
		this->puissance = puissance;
		this->estMagique = estMagique;
		this->prix = prix;
	}

	Arme::~Arme(){
		std::cout << "Arme is being deleted " << std::endl;
	}

	int Arme::getType(){
		return this->type;
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

	int Arme::getPrix(){
		return this->prix;
	}

	void Arme::afficher(){
		std::string mag;
		mag = (this->estMagique)?" Oui" : "Non" ;
		std::cout << "NOM " << this->nomItem << " TYPE " << this->type << " DEGAT " << this->puissance
				<< " PRE " << this->precision << " CRIT " << this->critique << " MAG? "
				<< mag << " Prix "	<< this->prix << std::endl;
	}


	void Arme::modNomItem(std::string s){
		this->nomItem = this->nomItem + s;
	}


	void Arme::modDegat(int a){
		this->puissance = this->puissance + a;
	}

	void Arme::modPrecision(int a){
		this->precision = this->precision + a;
	}

	void Arme::modCritique(int a){
		this->critique = this->critique + a;
	}



//class Epee : public Arme
	Epee::Epee(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix):
			Arme::Arme(nomArme, 0, puissance, precision, critique, estMagique, prix){

	}

	Epee::~Epee(){

	}

//class Lance : public Arme
	Lance::Lance(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix):
					Arme::Arme(nomArme, 1, puissance, precision, critique, estMagique, prix){

	}

	Lance::~Lance(){

	}


//class Sort : public Arme
	Sort::Sort(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix):
					Arme::Arme(nomArme, 2, puissance, precision, critique, estMagique, prix){

	}

	Sort::~Sort(){

	}

//class Decorator : public Arme
	Decorator::Decorator(Arme* arme):
			Arme::Arme(arme->getNomItem(), arme->getType(), arme->getDegat(), arme->getPrecision(), arme->getCritique(), arme->getEstMagique(), arme->getPrix()){
		this->arme = arme;
	}

	Decorator::~Decorator(){

	}


//class AmeliorationDegat : public Decorator
	AmeliorationDegat::AmeliorationDegat(Arme* arme): Decorator::Decorator(arme){
		this->modDegat(1);
		//this->nomItem = this->arme->nomItem + " de puissance";
		this->modNomItem(" de puissance");
		this->afficher();
	}

	AmeliorationDegat::~AmeliorationDegat(){

	}

//class AmeliorationPrecision : public Decorator
	AmeliorationPrecision::AmeliorationPrecision(Arme* arme): Decorator::Decorator(arme){
		this->modPrecision( 5);
		//this->nomItem = this->arme->nomItem + " de prescision";
		this->modNomItem( " de precision");
		this->afficher();
	}
	AmeliorationPrecision::~AmeliorationPrecision(){

	}

//class AmeliorationCritique : public Decorator

	AmeliorationCritique::AmeliorationCritique(Arme* arme): Decorator::Decorator(arme){
		this->modCritique(3);
		//this->nomItem = this->arme->nomItem + " de fureur";
		this->modNomItem(" de critique");
		this->afficher();
	}

	AmeliorationCritique::~AmeliorationCritique(){

	}


