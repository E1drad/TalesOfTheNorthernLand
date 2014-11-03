/*
 * Statistique.cpp
 *
 *  Created on: 1 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Statistique.hpp"

class Statistique {
private:

	/*
	 * int pointDexp;		0 | int pointDeVie;		1
	 * int pointDeVieMax;	2 | int force;			3
	 * int intelligence;	4 | int dexterite;		5
	 * int agilite;			6 | int chance;			7
	 * int armure;			8 | int sagesse;		9
	 * int attaqueBrute		10|	int defenseBrute	11
	*/
	//vector de taille 12
	std::vector<int> statistique;
	std::vector<int> statistiqueReel;
	std::vector<int> statistiqueTemporaire;

	/*
	 * 	int degat;			0 |	int precision;		1
	 * 	int esquive;		2 |	int critique;		3
	 */
	//vector de taille 4
	std::vector<int> statistiqueDerive;

	/*
	 * 	int epee;			0 |	int niveauEpee;		 1
	 * 	int lance;			2 | int niveauLance;	 3
	 * 	int hache;			4 | int niveauHache;	 5
	 * 	int sort;			6 | int niveauSort;		 7
	 * 	int arc;			8 | int niveauArc;		 9
	 * 	int heal;			10| int niveauHeal;		 11
	 */
	//vector de taille 12
	std::vector<int> statistiqueArme;

	//soit un total de 48 int

	void statistiqueArmeAtZero(){
		for(int i = 0; i < 10; i++){
			this->statistiqueArme.at(i) = 0;
		}
	}

public:

	//stat AVEC bonus temporaire AVEC stat arme
	Statistique(std::vector<int> sR, std::vector<int> sT, std::vector<int> sA)
	: statistiqueReel(sR), statistiqueTemporaire(sT), statistiqueTemporaire(sA){
		this->statistique = new Vector<int>();
		this->statistiqueDerive = new Vector<int>();
		this->updateStatistique();//va initialiser statistique
	}

	//SI (bTemp) ALORS stat AVEC bonus temporaire SANS stat arme SINON stat SANS bonus temporaire AVEC stat arme
	Statistique(std::vector<int> sR, std::vector<int> sA, bool bonusTemp)
	: statistiqueReel(sR),statistiqueTemporaire(sA){
		if(bonusTemp){
			this->statistique = new Vector<int>();
			this->statistiqueDerive = new Vector<int>();
			this->statistiqueArme = new Vector<int>();
			this->updateStatistique();//va initialiser statistique
			this->statistiqueArmeAtZero();
		}else{
			this->statistiqueReel = sR;
			this->statistique = new Vector<int>();
			this->statistiqueTemporaire = new Vector<int>();
			this->statistiqueDerive = new Vector<int>();
			this->resetBonus();//va initialiser statistiqueTemporaire
			this->updateStatistique();//va initialiser statistique
			this->statistiqueArme = sA;
		}
	}

	//stat SANS bonus temporaire SANS stat arme
	Statistique(std::vector<int> sR)
	: statistiqueReel(sR){
		this->statistique = new Vector<int>();
		this->statistiqueTemporaire = new Vector<int>();
		this->statistiqueDerive = new Vector<int>();
		this->statistiqueArme = new Vector<int>();
		this->resetBonus();//va initialiser statistiqueTemporaire
		this->updateStatistique();//va initialiser statistique
		this->statistiqueArmeAtZero();
	}

	void updateStatistique(){
		for(int i = 0; i < this->statistique.size; i++){
			this->statistique.at(i) = this->statistiqueReel.at(i) + this->statistiqueTemporaire.at(i);
		}
		this->updateCritique();
		this->updateDegat();
		this->updatePrecision();
	}

	void resetBonus(){
		for(int i = 0; i < this->statistiqueTemporaire.size; i++){
			this->statistiqueTemporaire.at(i) = 0;
		}
	}

	std::vector<int> getStatistique(){
		this->updateStatistique();
		return this->statistique;
	}

	std::vector<int> getStatistiqueTemporaire(){
		this->updateStatistique();
		return this->statistiqueTemporaire;
	}

	std::vector<int> getStatistiqueReel(){
		this->updateStatistique();
		return this->statistiqueReel;
	}

	std::vector getStatistiqueDerive(){
		this->updateStatistique();
		return this->statistiqueDerive;
	}

	void modStatistiqueReel(int mod, int statModifier){//pour lvl up
		this->statistiqueReel.at(statModifier) = this->statistiqueReel.at(statModifier) + mod;
		this->updateStatistique();
	}

	void modStatistiqueTemporaire(int mod, int statModifier){// pour potion de buff
		this->statistiqueTemporaire.at(statModifier) = this->statistiqueTemporaire.at(statModifier) + mod;
		this->updateStatistique();
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

	void prendreDegat(int degat){
		if(degat >= 0){
			//ternaire : degat superieur a zero apres app de la DefBrute ? SI oui ALORS degat reduit SINON degat = 0
			degat = (degat - this->statistique.at(11) >0) ? degat - this->statistique.at(11) : 0;
			if(this->statistiqueTemporaire.at(1) == 0){
				this->statistiqueReel.at(1) = this->statistiqueReel.at(1) - degat;
			}else if(this->statistiqueTemporaire.at(1) >= degat ){
				this->statistiqueTemporaire.at(1) = this->statistiqueTemporaire.at(1) - degat;
			}else{//pvTemp !=0 et degat > pvTemp ie pvTemp = 0 et pv = pv -(degat-pvTemp)
				degat = degat - this->statistiqueTemporaire.at(1);
				this->statistiqueTemporaire.at(1) = 0;
				this->statistiqueReel.at(1) = this->statistiqueReel.at(1) - degat;
			}
		}else{//si degat negatif c'est un heal.
			//ternaire : SI pv + pvGagnerParHeal > pvMax ALORS pvMax SINON pv +pvGagnerParHeal
			this->statistiqueReel.at(1) = (this->statistiqueReel.at(1) - degat > this->statistiqueReel.at(2)) ? this->statistiqueReel.at(2) : this->statistiqueReel.at(1) - degat;
		}
		this->updateStatistique();
	}

};
