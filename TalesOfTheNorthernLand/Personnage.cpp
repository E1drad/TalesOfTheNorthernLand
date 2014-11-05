/*
 * Personnage.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Personnage.hpp"
	/* int pointDexp;		0 | int pointDeVie;		1
	 * int pointDeVieMax;	2 | int force;			3
	 * int intelligence;	4 | int dexterite;		5
	 * int agilite;			6 | int chance;			7
	 * int armure;			8 | int sagesse;		9
	 *///statistique

	/* int degat;		0 |	int precision;		1
	 * int esquive;		2 |	int critique;		3
	 *///statistiqueDerive

	void modificateurRace(){
		for(int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) + this->race.getmodificateurStatistique().at(i);
		}
	}
	void modificateurClasse(){
		for(int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) + this->classe.getmodificateurStatistique().at(i);
		}
	}


	Personnage::Personnage(std::vector<int> s, std::string n, ClasseHeroique c, Race r, bool estFemme)
	: nom(n), classeHeroique(c), race(r), estFemme(estFemme), statistique(s){
		this->classeParagon = null;
		this->classeDivine = null;
		this->modificateurRace();
		this->modificateurClasse();
		this->updateStatistique();
		this->armeEquiper = null;
	}

	void attaquer(Personnage &cible){
		int jetDe;
		this->updateStatistique();
		cible.updateStatistique();
		jetDe = rand() % 100 + 1;// entre 1 et 100
		if(jetDe <= this->statistiqueDerive.at(1) - cible.getStatistiqueDerive().at(2)){
			cible.prendreDegat(this->statistiqueDerive.at(0));
		}
	}
	void setArmeEquiper(Arme a){//TODO need update controle classe
		this->armeEquiper = a;
	}

	int updateDegat(){
		int valeur;
		if(this->armeEquiper == null){//rien ie 0
			valeur = 0;
		}else if(this->armeEquiper.estMagique()){//intelligence + degat
			valeur = this->statistique.at(4) + this->armeEquiper.getDegat() + this->statistique.at(10);
		}else{//force + degat
			valeur = this->statistique.at(3) + this->armeEquiper.getDegat() + this->statistique.at(10);
		}
		return valeur;
	}

	int updatePrecision(){
		int valeur = 2*this->statistique.at(5);
		if(!this->armeEquiper == null){//si diff de null
			valeur = 2*this->statistique.at(5) + this->armeEquiper.getPrecision();
		}
		return valeur;
	}

	int updateCritique(){
		int valeur = 2*this->statistique.at(7);
		if(!this->armeEquiper == null){//si diff de null
			valeur = 2*this->statistique.at(7) + this->armeEquiper.getCritique();
		}
		return valeur;
	}

	void prendreDegat(int degat){
		if(degat >= 0){
			this->modStat(1, degat);
			cout << this->nom << " a perdu " << degat << "point de vie." << endl;
			if(this->statistique.at(1) <= 0){
				this->estMort();
			}
		}
	}

	void estMort(){
		cout << this->nom << " est mort tragique !" << endl;
		//TODO need update!
	}

	void modStat(int stat, int modificateur);

	Race getRace(){
		return this->race;
	}

	std::string getNom(){
		return this->nom;
	}

	Classe getClasseActuelle(){
		Classe c;
		if( !(this->classeDivine == null) ){
			c = this->classeDivine;
		}else if( !(this->classeParagon == null) ){
			c = this->classeParagon;
		}else{
			c = this->classeHeroique;
		}
		return c;
	}

	bool getEstFemme(){
		return this->estFemme;
	}

	void updateStatistique(){
		this->updateCritique();
		this->updateDegat();
		this->updatePrecision();
		this->statistiqueDerive.at(2) = this->statistique.at(6) * 2;
	}

	std::vector<int> getStatistique(){
		return this->statistique;
	}

	std::vector<int>  getStatistiqueDerive(){
		return this->statistiqueDerive;
	}
