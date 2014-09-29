/*
 * Personnage.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: E123313L
 */

class Personnage {
private :
	Statistique statistique;
	String nom;
	Classe classe;
	Race race;
	bool estFemme;
	Item inventaire[5];
	ZoneDeDeplacement zoneDeDeplacement;
	ZoneAction zoneAction;
	Technique technique[5];

public :




	Classe Personnage::getClasse() const {
		return classe;
	}

	bool Personnage::getEstFemme() const {
		return estFemme;
	}

	Item Personnage::getInventaire() const {
		return inventaire;
	}

	String Personnage::getNom() const {
		return nom;
	}

	Race Personnage::getRace() const {
		return race;
	}

	Statistique Personnage::getStatistique() const {
		return statistique;
	}

	Technique Personnage::getTechnique() const {
		return technique;
	}

	ZoneAction Personnage::getZoneAction() const {
		return zoneAction;
	}

	ZoneDeDeplacement Personnage::getZoneDeDeplacement() const {
		return zoneDeDeplacement;
	}

	Classe getClasse() const;
	bool getEstFemme() const;
	Item getInventaire() const;
	String getNom() const;
	Race getRace() const;
	Statistique getStatistique() const;
	Technique getTechnique() const;
	ZoneAction getZoneAction() const;
	ZoneDeDeplacement getZoneDeDeplacement() const;
};
