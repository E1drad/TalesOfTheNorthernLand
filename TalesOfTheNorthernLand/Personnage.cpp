/*
 * Personnage.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Personnage.hpp"

class Personnage {
private :

	void modificateurRace(){
		for(int i = 0; i< this->statistique.getStatistique().size; i++){
			this->statistique.modStatistiqueReel(this->race.getmodificateurStatistique().at(i),i);
		}
	}

	void modificateurClasse(){
		for(int i = 0; i< this->statistique.getStatistique().size; i++){
			this->statistique.modStatistiqueReel(this->classe.getmodificateurStatistique().at(i),i);
		}
	}
	//TODO need udpate
	void equiperPremierArme(){
		int i = 0;
		Item item;
		Arme a = null;
		while(a == null && i < this->inventaire.size){
			item = this->inventaire.at(i);
			if(typeid(item)==typeid(a)){
				a = item;
			}
			i++;
		}
	}

public :


	void attaquer(Personnage &cible){
		this->statistique.updateStatistique();
		cible.getStatistique().getStatistique();
	}

	void seFaireAttaquer(int degat, Personnage &attaquant){
		this->statistique.updateStatistique();
		attaquant.getStatistique().getStatistique();
	}

	void setArmeEquiper(Arme a){
		this->armeEquiper = a;
	}

	Personnage::Personnage(Statistique s, std::string n, ClasseHeroique c, Race r, bool estFemme, Item i[5], Technique t[5])
	: statistique(s), nom(n),classeHeroique(c), race(r), estFemme(estFemme), inventaire(i), technique(t){
		this->armeEquiper = null;
		this->classeDivine = null;
		this->classeParagon = null;
		this->zoneDeDeplacement = null;
		this->zoneAction = null;
		this->equiperPremierArme();
	}

	Personnage::Personnage(Statistique s, std::string n, ClasseHeroique c, Race r, bool estFemme)
	: statistique(s), nom(n),classeHeroique(c), race(r), estFemme(estFemme){
		this->armeEquiper = null;
		this->inventaire = null;
		this->classeDivine = null;
		this->classeParagon = null;
		this->zoneDeDeplacement = null;
		this->zoneAction = null;
		this->technique = null;
		this->equiperPremierArme();
	}



	ClasseHeroique Personnage::getClasseHeroique() {
		return this->classe;
	}

	ClasseParagon Personnage::getClasseParagon() {
		return this->classe;
	}

	ClasseDivine Personnage::getClasseDivine() {
		return this->classe;
	}

	bool Personnage::getEstFemme() {
		return this->estFemme;
	}

	Item Personnage::getInventaire() {
		return this->inventaire;
	}

	Arme Personnage::getArmeEquiper() {
		return this->armeEquiper;
	}

	std::string Personnage::getNom() {
		return this->nom;
	}

	Race Personnage::getRace() {
		return this->race;
	}

	Statistique Personnage::getStatistique() {
		return this->statistique;
	}

	Technique Personnage::getTechnique() {
		return this->technique;
	}

	ZoneAction Personnage::getZoneAction() {
		return zoneAction;
	}

	ZoneDeDeplacement Personnage::getZoneDeDeplacement() {
		return this->zoneDeDeplacement;
	}


	/* sert a rien enfin je crois que sa sert a rien.
	Classe getClasse();
	bool getEstFemme();
	Item getInventaire();
	string getNom();
	Race getRace();
	Statistique getStatistique();
	Technique getTechnique();
	ZoneAction getZoneAction();
	ZoneDeDeplacement getZoneDeDeplacement();
	*/
};
