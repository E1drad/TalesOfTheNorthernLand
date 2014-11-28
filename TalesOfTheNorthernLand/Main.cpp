/*
 * Main.cpp
 *
 *  Created on: 26 sept. 2014
 *      Author: BEGAUDEAU Charles
 */
#include "Technique.hpp"
#include "Classe.hpp"
#include "Race.hpp"
#include "Personnage.hpp"
#include "Armes.hpp"
#include "Item.hpp"
#include "Branche.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "Posture.hpp"
#include <cstdlib>
#include <iostream>
#include "Afficheur.hpp"
#include "Instancieur.hpp"
//#include <ctime> ancien methode
//srand(time(0));//ancien methode !

//#include <random>//nouvelle methode !
//std::random_device rd;//nouvelle methode !
//std::mt19937 rng(rd());//nouvelle methode !
//rng();//nouvelle methode !

/**************************************************PROTOTYPE**************************************************/
void waitForKey();
void test(Personnage *persoJoueur, Instancieur* instancieur, Afficheur* afficheur);
void vectorAdd10Int(std::vector<int> &Vec, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void combat(Personnage *persoJoueur, Personnage *persoIA);
void testState(Personnage *persoJoueur, Instancieur* instancieur, Afficheur* afficheur);
/**************************************************PROTOTYPE**************************************************/


int main(void){
	Afficheur afficheur;
	Instancieur* instancieur = new Instancieur();
	Marchand* marchand1 = new Marchand(instancieur->getArmes());
	Marchand* marchand2 = new Marchand(instancieur->getArmes());
	Marchand* marchand3 = new Marchand(instancieur->getArmes());

	std::vector<int> stat;
	vectorAdd10Int(stat,0,40,40,6,6,7,7,7,9,9);

	Personnage lucina(stat, std::string("Lucina"), instancieur->getClasseH("Pretresse"),  instancieur->getRace("elfe"), true, 1);
	afficheur.afficherPerso(&lucina);
	lucina.setArmeEquiper(instancieur->getArme("Graviter"));
	waitForKey();
	afficheur.afficherPerso(&lucina);

	Personnage raven(stat, std::string("Raven"), instancieur->getClasseH("Archer"),  instancieur->getRace("genasi"), false, 2);
	raven.setArmeEquiper(instancieur->getArme("Lance"));
	Personnage malak(stat, std::string("Malak"), instancieur->getClasseH("Archer"),  instancieur->getRace("genasi"), false, 2);
	malak.setArmeEquiper(instancieur->getArme("Epee longue"));
	std::system("clear");

	test(&lucina, instancieur, &afficheur);

	combat(&lucina,&raven);

	if(!lucina.estMort()){
		marchand1->afficherMenu(&lucina);
		marchand2->afficherMenu(&lucina);
		marchand3->afficherMenu(&lucina);

		afficheur.afficherPerso(&lucina);
		waitForKey();
		lucina.promotion(instancieur->getClasseP("Reine"));
		afficheur.afficherPerso(&lucina);
		//TODO boucle de jeu + narration ?
		//TODO marchand random
		//TODO upgrade IA
		waitForKey();
		combat(&lucina,&malak);
	}

	std::cout << "Fin \nPress any key (other than Enter) and press Enter" << std::endl;
	std::string h;
	std::cin >> h;
	std::cout << std::endl << std::endl;
	delete marchand1;
	delete marchand2;
	delete marchand3;

	delete instancieur;
	return 0;
}




void waitForKey(){
	std::cout << "Press the ENTER key\n";
	if (std::cin.get() == '\n'){
	   // std::cout << "Good job.\n";
	}else{
	   // std::cout << "I meant ONLY the ENTER key... Oh well.\n";
		std::cin.clear();
    	std::cin.ignore(999,'\n');
	}
}

void test(Personnage *persoJoueur, Instancieur* instancieur,  Afficheur* afficheur){
	std::cout << "\t 1/ Jeu \n\t 2/ Mode Test" << std::endl;
	std::string cmd1;
	cmd1 = "000";
	bool test = false;
	while((!test) || (cmd1.length() != 1)){
		std::cin >> cmd1;
		std::cin.clear();
		std::cin.ignore(999,'\n');
		try{
			int cmd = std::stoi(cmd1);
			switch (cmd){
			case 1:
				test = true;
				break;
			case 2:
				testState(persoJoueur, instancieur, afficheur);//TEST STATE
				std::system("clear");
				//combat(persoJoueur,&raven);//testCombatRaven
				//testMarchand
				//persoJoueur->promotion(instancieur->getClasseP("Reine"));//testPromotion
				//combat(persoJoueur,&malak);//testcombatMalak
				test = true;
				break;
			default :
				std::cout << "entre un nombre 1 et 2 merci !" << std::endl;
			}
		}catch (std::invalid_argument){
			cmd1 = "000";
			std::cout << "Veuiller enter un nombre compris entre 1 et 2" << std::endl;
		}
	}
}


void vectorAdd10Int(std::vector<int> &Vec, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
	Vec.push_back(a);  Vec.push_back(b);  Vec.push_back(c);  Vec.push_back(d);  Vec.push_back(e);
	Vec.push_back(f);  Vec.push_back(g);  Vec.push_back(h);  Vec.push_back(i);  Vec.push_back(j);
}

void combat(Personnage *persoJoueur, Personnage *persoIA){
	Afficheur afficheur;
	while(!persoJoueur->estMort() && !persoIA->estMort() ){
		std::system("clear");
		afficheur.afficherPersos(persoJoueur,persoIA);
		if(!persoJoueur->estMort()){
			persoJoueur->actionCombat(persoIA);
		}
		std::system("clear");
		afficheur.afficherPersos(persoJoueur,persoIA);
		if(!persoIA->estMort()){
			persoIA->combatAutomatique(persoJoueur);
		}
		waitForKey();
	}
}

void testState(Personnage *persoJoueur, Instancieur* instancieur, Afficheur* afficheur){
																		afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->decheance();											afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->promotion(instancieur->getClasseP("Reine"));			afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->decheance();											afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->decheance();											afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->promotion(instancieur->getClasseP("Reine"));			afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->promotion(instancieur->getClasseP("Reine"));			afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->promotion(instancieur->getClasseD("Sainte Reine"));	afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->promotion(instancieur->getClasseD("Sainte Reine"));	afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->decheance();											afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->decheance();											afficheur->afficherPerso(persoJoueur);	waitForKey();
	persoJoueur->decheance();											afficheur->afficherPerso(persoJoueur);	waitForKey();
}

