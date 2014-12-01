/*
 * Armes.cpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Armes.hpp"

//class Arme : public Item

 	/**
 	*\brief Le constructeur de l'arme.
 	*	Constructeur de l'arme instanciant toutes
 	*	ses caractéristiques.	
 	*
 	*	\param nomArme Le nom de l'arme.
 	*	\param type ID du type de l'arme.
 	*	\param puissance La puissance de l'arme.
 	*	\param precision La precision de l'arme.
 	*	\param critique Son pourcentage de critique.
 	*	\param estMagique Si oui ou non elle est magique.
 	*	\param prix Le prix de base de l'arme.
 	*/
	Arme::Arme(std::string nomArme, int type, int puissance, int precision, int critique, bool estMagique, int prix): Item::Item(nomArme){
		this->critique = critique;
		this->type = type;
		this->precision = precision;
		this->puissance = puissance;
		this->estMagique = estMagique;
		this->prix = prix;
	}

	/**
 	*\brief Le destructeur de l'arme.
 	*/
	Arme::~Arme(){
		std::cout << "Arme is being deleted " << std::endl;
	}

	/**
 	*\brief Le getter du type.
 	*/
	int Arme::getType(){
		return this->type;
	}

	/**
 	*\brief Le getter de la puissance.
 	*/
	int Arme::getDegat(){
		return this->puissance;
	}

	/**
 	*\brief Le getter de la precision.
 	*/
	int Arme::getPrecision(){
		return this->precision;
	}

	/**
 	*\brief Le getter du pourcentage de critique.
 	*/
	int Arme::getCritique(){
		return this->critique;
	}

	/**
 	*\brief Le getter de l'atribut magique ou non.
 	*/
	bool Arme::getEstMagique(){
		return this->estMagique;
	}

	/**
 	*\brief Le getter du prix de l'arme.
 	*/
	int Arme::getPrix(){
		return this->prix;
	}


	/**
 	*\brief Procédure d'afficahge de l'arme.
 	*/
	void Arme::afficher(){
		std::string mag;
		mag = (this->estMagique)?" Oui" : "Non" ;
		std::cout << "NOM " << this->nomItem << " TYPE " << this->type << " DEGAT " << this->puissance
				<< " PRE " << this->precision << " CRIT " << this->critique << " MAG? "
				<< mag << " Prix "	<< this->prix << std::endl;
	}


	/**
 	*\brief Modificateur du nom de l'arme.
 	*	recoit un atribut en paramètre et le met à la
 	*	suite du nom de l'arme.
 	*
 	*	\param s Le mot à metre à la suite de l'arme.
 	*/
	void Arme::modNomItem(std::string s){
		this->nomItem = this->nomItem + s;
	}

	/**
 	*\brief Modificateur de la puissance de l'arme.
 	*	\param a La puissance à concaténer.
 	*/
	void Arme::modDegat(int a){
		this->puissance = this->puissance + a;
	}

	/**
 	*\brief Modificateur de la precision de l'arme.
 	*	\param a La precision à concaténer.
 	*/
	void Arme::modPrecision(int a){
		this->precision = this->precision + a;
	}

	/**
 	*\brief Modificateur du pourcentage de critique de l'arme.
 	*	\param a Le pourcentage de critique à concaténer.
 	*/
	void Arme::modCritique(int a){
		this->critique = this->critique + a;
	}



//class Epee : public Arme
	/**
 	*\brief Construit une arme de type 0.
 	*/
	Epee::Epee(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix):
			Arme::Arme(nomArme, 0, puissance, precision, critique, estMagique, prix){

	}

	Epee::~Epee(){

	}

//class Lance : public Arme
	/**
 	*\brief Construit une arme de type 1.
 	*/
	Lance::Lance(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix):
					Arme::Arme(nomArme, 1, puissance, precision, critique, estMagique, prix){

	}

	Lance::~Lance(){

	}


//class Sort : public Arme
	/**
 	*\brief Construit une arme de type 2.
 	*/
	Sort::Sort(std::string nomArme, int puissance, int precision, int critique, bool estMagique, int prix):
					Arme::Arme(nomArme, 2, puissance, precision, critique, estMagique, prix){

	}

	Sort::~Sort(){

	}

//class Decorator : public Arme
	/**
 	*\brief Constructeur du décorator copiant la valeur de l'arme en entrée.
 	*	\param arme l'arme à décorer.
 	*/
	Decorator::Decorator(Arme* arme):
			Arme::Arme(arme->getNomItem(), arme->getType(), arme->getDegat(), arme->getPrecision(), arme->getCritique(), arme->getEstMagique(), arme->getPrix()){
		this->arme = arme;
	}

	Decorator::~Decorator(){

	}


//class AmeliorationDegat : public Decorator
	/**
 	*\brief Décorateur de dégats modifiant les dégâts de l'arme.
 	*	\param arme l'arme à décorer.
 	*/
	AmeliorationDegat::AmeliorationDegat(Arme* arme): Decorator::Decorator(arme){
		this->modDegat(1);
		//this->nomItem = this->arme->nomItem + " de puissance";
		this->modNomItem(" de puissance");
		this->afficher();
	}

	AmeliorationDegat::~AmeliorationDegat(){

	}

//class AmeliorationPrecision : public Decorator
	/**
 	*\brief Décorateur de precision modifiant la precision de l'arme.
 	*	\param arme l'arme à décorer.
 	*/
	AmeliorationPrecision::AmeliorationPrecision(Arme* arme): Decorator::Decorator(arme){
		this->modPrecision( 5);
		//this->nomItem = this->arme->nomItem + " de prescision";
		this->modNomItem( " de precision");
		this->afficher();
	}
	AmeliorationPrecision::~AmeliorationPrecision(){

	}

//class AmeliorationCritique : public Decorator
	/**
 	*\brief Décorateur de critique modifiant le pourcentage critique de l'arme.
 	*	\param arme l'arme à décorer.
 	*/
	AmeliorationCritique::AmeliorationCritique(Arme* arme): Decorator::Decorator(arme){
		this->modCritique(3);
		//this->nomItem = this->arme->nomItem + " de fureur";
		this->modNomItem(" de critique");
		this->afficher();
	}

	AmeliorationCritique::~AmeliorationCritique(){

	}


