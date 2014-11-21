/*
 * Statistique.cpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Statistique.hpp"

	/* int pointDexp;		0 | int pointDeVie;		1
	 * int pointDeVieMax;	2 | int force;			3
	 * int intelligence;	4 | int dexterite;		5
	 * int agilite;			6 | int chance;			7
	 * int armure;			8 | int sagesse;		9
	 *///std::vector<int> statistique;

	/* int degat;		0 |	int precision;		1
	 * int esquive;		2 |	int critique;		3
	 *///std::vector<int> statistiqueDerive;

	Statistique::Statistique(std::vector<int> s): statistique(s){
		this->updateStatistique();//va initialiser statistiqueDerivé
	}

	void updateStatistique(){
		this->updateCritique();
		this->updateDegat();
		this->updatePrecision();
	}

	std::vector<int> getStatistique(){
		this->updateStatistique();
		return this->statistique;
	}

	std::vector<int> getStatistiqueDerive(){
		this->updateStatistique();
		return this->statistiqueDerive;
	}

	int updateDegat(Arme arme){
		int valeur;
		if(arme == null){//rien ie 0
			valeur = 0;
		}else if(arme.estMagique()){//intelligence + degat
			valeur = this->statistique.at(4) + arme.getDegat() + this->statistique.at(10);
		}else{//force + degat
			valeur = this->statistique.at(3) + arme.getDegat() + this->statistique.at(10);
		}
		return valeur;
	}

	int updatePrecision(Arme arme){
		int valeur = 2*this->statistique.at(5);
		if(!arme == null){//si diff de null
			valeur = 2*this->statistique.at(5) + arme.getPrecision();
		}
		return valeur;
	}

	int updateCritique(Arme arme){
		int valeur = 2*this->statistique.at(7);
		if(!arme == null){//si diff de null
			valeur = 2*this->statistique.at(7) + arme.getCritique();
		}
		return valeur;
	}

	void prendreDegat(int degat, Personnage p){
		if(degat >= 0){
			this->modStat(1, degat);
			cout << p.getNom() << " a perdu " << degat << "point de vie." << endl;
			if(this->statistique.at(1) <= 0){
				p.mort();
			}
		}
	}

	void modStat(int stat, int modificateur){
		this->statistique.at(stat) = this->statistique.at(stat) + modificateur;
		this->updateStatistique();
	}

