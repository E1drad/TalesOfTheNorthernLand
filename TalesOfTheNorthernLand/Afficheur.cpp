/*
 * Afficheur.cpp
 *
 *  Created on: 19 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Afficheur.hpp"


	/**
 	 * \brief Constructeur
 	 */
	Afficheur::Afficheur(){

	}

	/**
	 * \brief Destructeur
	 */
	Afficheur::~Afficheur(){

	}

	/**
	 * \brief afficher les statistiques de deux personnages
	 * \details On limite la taille des noms de classe et de perso a 7 pour eviter un derp de l'affichage
	 * \param Personnage* perso1 le perso afficher a gauche
	 * \param Personnage* perso2 le perso afficher a droite
	 */
	void Afficheur::afficherPersos(Personnage *perso1,Personnage *perso2){
		std::system("clear");
		int i = 0;
		int j = 0;
		if(perso1->getClasseActuelle()->getNomClasse().length() > 7){
			i = 7;
		}else{
			i= perso1->getClasseActuelle()->getNomClasse().length();
		}
		if(perso1->getNom().length() > 7){
			j = 7;
		}else{
			j= perso1->getNom().length();
		}
		std::cout << perso1->getNom().substr(0,j) << "\t <<  Nom  >> \t"<< perso2->getNom() << std::endl;
		std::cout << perso1->getClasseActuelle()->getNomClasse().substr(0,i) << "\t << Classe>> \t"<< perso2->getClasseActuelle()->getNomClasse() << std::endl;
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

	/**
	 * \brief afficher le statistique d'un personnage
	 * \details On limite la taille des noms de classe et de perso a 7 pour eviter un derp de l'affichage
	 * \param Personnage* perso1 le perso a afficher
	 */
	void Afficheur::afficherPerso(Personnage *perso1){
		//std::system("clear");
		int i = 0;
		int j = 0;
		if(perso1->getClasseActuelle()->getNomClasse().length() > 7){
			i = 7;
		}else{
			i= perso1->getClasseActuelle()->getNomClasse().length();
		}
		if(perso1->getNom().length() > 7){
			j = 7;
		}else{
			j= perso1->getNom().length();
		}
		std::cout << perso1->getNom().substr(0,j) << "\t <<  Nom  >> "<< std::endl;
		std::cout << perso1->getClasseActuelle()->getNomClasse().substr(0,i) << "\t << Classe>> " << std::endl;
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

