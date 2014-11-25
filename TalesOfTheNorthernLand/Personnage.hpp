/*
 * Personnage.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef PERSONNAGE_HPP_
#define PERSONNAGE_HPP_

#include <string>
//#include "Statistique.hpp"
#include "Classe.hpp"
#include "Race.hpp"
#include "Item.hpp"
#include "Armes.hpp"
 #include "Afficheur.hpp"
//#include "ZoneDeDeplacement.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <cstdlib>
#include "Posture.hpp"
//#include <unistd.h>
//unsigned int microseconds = 1500;
//usleep(microseconds);
#include <chrono>
#include <thread>

class Personnage {
private :

	int niveau;
	int argent;
	std::string nom;
	Classe* classeHeroique;
	Classe* classeParangon;
	Classe* classeDivine;
	Classe* classeActuelle;
	Race* race;
	bool estFemme;
	Arme* armeEquiper;
	Posture* posture;
	/* int pointDexp;		0 | int pointDeVie;		1
	 * int pointDeVieMax;	2 | int force;			3
	 * int intelligence;	4 | int dexterite;		5
	 * int agilite;			6 | int chance;			7
	 * int armure;			8 | int sagesse;		9
	 */
	std::vector<int> statistique;

	/* int degat;		0 |	int precision;		1
	 * int esquive;		2 |	int critique;		3
	 * int attaquant	4 | int	defenseur		5
	 * int soigneur		6 | int	tacticien		7
	 */
	std::vector<int> statistiqueDerive;

	void modificateurRace();
	void modificateurClasse(Classe* classe);
	void modificateurClasseDecheance(Classe* classe);
	void whaitForKey();

public :

	Personnage(std::vector<int> s, std::string n, ClasseHeroique* c, Race* r, bool estFemme, int niveau);
	~Personnage();
	void actionCombat(Personnage *cible);
	void combatAutomatique(Personnage *cible);
	void changePosture();
	bool seSoigner();
	void setArmeEquiper(Arme* a);
	void setClasseActuelle(Classe* classe);
	void setClasseParangon(Classe* classe);
	void setClasseDivine(Classe* classe);
	void monterNiveau();
	int updateDegat();
	int updatePrecision();
	int updateCritique();
	int updateEsquive();
	void updateNiveau();
	void updatePV();
	void prendreDegat(int degat);
	void attaquer(Personnage *cible);
	void mourant();
	void modStat(int stat, int modificateur);
	Race* getRace();
	std::string getNom();
	Classe* getClasseActuelle();
	bool getEstFemme();
	void updateStatistique();
	std::vector<int> getStatistique();
	std::vector<int> getStatistiqueDerive();
	Classe* getClasseHeroique();
	Classe* getClasseParangon();
	Classe* getClasseDivine();
	void afficherStat();
	void promotion(Classe* classe);
	void decheance();
	int critique(int degat, Personnage *cible);
	bool estMort();
	bool modArgent(int argent);
	int getArgent();
	Arme* getArmeActuelle();

};



#endif /* PERSONNAGE_HPP_ */
