/*
 * Afficheur.cpp
 *
 *  Created on: 19 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Afficheur.hpp"



	Afficheur::Afficheur(){

	}

	Afficheur::~Afficheur(){

	}

	void Afficheur::afficherPersos(Personnage *perso1,Personnage *perso2){
		std::system("clear");
		std::cout << perso1->getNom() << "\t <<  Nom  >> \t"<< perso2->getNom() << std::endl;
		std::cout << perso1->getStatistique().at(1) << "\t <<  PV   >> \t" << perso2->getStatistique().at(1) << std::endl;
		std::cout << perso1->getStatistique().at(2) << "\t << PVMAX >> \t" << perso2->getStatistique().at(2) << std::endl;
		std::cout << perso1->getStatistique().at(3) << "\t <<  FOR  >> \t" << perso2->getStatistique().at(3) << std::endl;
		std::cout << perso1->getStatistique().at(4) << "\t <<  INT  >> \t" << perso2->getStatistique().at(4) << std::endl;
		std::cout << perso1->getStatistique().at(5) << "\t <<  DEX  >> \t" << perso2->getStatistique().at(5) << std::endl;
		std::cout << perso1->getStatistique().at(6) << "\t <<  AGI  >> \t" << perso2->getStatistique().at(6) << std::endl;
		std::cout << perso1->getStatistique().at(7) << "\t <<  CHA  >> \t" << perso2->getStatistique().at(7) << std::endl;
		std::cout << perso1->getStatistique().at(8) << "\t <<  ARM  >> \t" << perso2->getStatistique().at(8) << std::endl;
		std::cout << perso1->getStatistique().at(9) << "\t <<  SAG  >> \t" << perso2->getStatistique().at(9) << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(0) << "\t <<  DEG  >> \t" << perso2->getStatistiqueDerive().at(0) << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(1) << "\t <<  PRE  >> \t" << perso2->getStatistiqueDerive().at(1) << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(2) << "\t <<  ESQ  >> \t" << perso2->getStatistiqueDerive().at(2) << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(3) << "\t <<  CRIT >> \t" << perso2->getStatistiqueDerive().at(3) << std::endl;
	}

	void Afficheur::afficherPerso(Personnage *perso1){
		std::system("clear");
		std::cout << perso1->getNom() << "\t <<  Nom  >> "<< std::endl;
		std::cout << perso1->getStatistique().at(1) << "\t <<  PV   >> " << std::endl;
		std::cout << perso1->getStatistique().at(2) << "\t << PVMAX >> " << std::endl;
		std::cout << perso1->getStatistique().at(3) << "\t <<  FOR  >> " << std::endl;
		std::cout << perso1->getStatistique().at(4) << "\t <<  INT  >> " << std::endl;
		std::cout << perso1->getStatistique().at(5) << "\t <<  DEX  >> " << std::endl;
		std::cout << perso1->getStatistique().at(6) << "\t <<  AGI  >> " << std::endl;
		std::cout << perso1->getStatistique().at(7) << "\t <<  CHA  >> " << std::endl;
		std::cout << perso1->getStatistique().at(8) << "\t <<  ARM  >> " << std::endl;
		std::cout << perso1->getStatistique().at(9) << "\t <<  SAG  >> " << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(0) << "\t <<  DEG  >> " << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(1) << "\t <<  PRE  >> " << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(2) << "\t <<  ESQ  >> " << std::endl;
		std::cout << perso1->getStatistiqueDerive().at(3) << "\t <<  CRIT >> " << std::endl;
	}

