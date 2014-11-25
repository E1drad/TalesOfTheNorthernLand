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


//Joachim on ecrit sa WAIT PAS WHAIT mais j'ai trop la flemme de changé sa partout :(
//Signé Charles
void whaitForKey(){
	std::cout << "Press the ENTER key\n";
	if (std::cin.get() == '\n'){
	   // std::cout << "Good job.\n";
	}else{
	   // std::cout << "I meant ONLY the ENTER key... Oh well.\n";
		std::cin.clear();
    	std::cin.ignore(999,'\n');
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
		//std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		std::system("clear");
		afficheur.afficherPersos(persoJoueur,persoIA);
		//whaitForKey();
		if(!persoIA->estMort()){
			persoIA->combatAutomatique(persoJoueur);
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		whaitForKey();
	}
}

int main(void){
	Afficheur afficheur;
	Instancieur* instancieur = new Instancieur();
	Marchand* marchand = new Marchand();
/*
	std::vector<int> sStatSainteReine;
	vectorAdd10Int(sStatSainteReine,0,15,15,8,8,6,7,15,8,8);
	ClasseDivine sainteReine(std::string("Sainte Reine"), sStatSainteReine, &clerger, demiDieu, 5);

	std::vector<int> sStatSainte;
	vectorAdd10Int(sStatSainte,0,25,25,4,4,6,5,12,10,10);
	ClasseDivine sainte(std::string("Sainte"), sStatSainte, &clerger, volonter, 5);
*/

	std::vector<int> stat;
	vectorAdd10Int(stat,0,40,40,6,6,7,7,7,9,9);

	Personnage lucina(stat, std::string("Lucina"), instancieur->getClasseH("Pretresse"),  instancieur->getRace("elfe"), true, 1);
	afficheur.afficherPerso(&lucina);
	lucina.setArmeEquiper(marchand->getArme("Graviter"));
	whaitForKey();
	afficheur.afficherPerso(&lucina);

	Personnage raven(stat, std::string("Raven"), instancieur->getClasseH("Archer"),  instancieur->getRace("genasi"), false, 2);
	raven.setArmeEquiper(marchand->getArme("Lance"));
	Personnage malak(stat, std::string("Malak"), instancieur->getClasseH("Archer"),  instancieur->getRace("genasi"), false, 2);
	malak.setArmeEquiper(marchand->getArme("Epee longue"));
	std::system("clear");

	combat(&lucina,&raven);

	
	if(!lucina.estMort()){
		marchand->afficherMenu(&lucina);
		afficheur.afficherPerso(&lucina);
		//std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		whaitForKey();
		lucina.promotion(instancieur->getClasseP("Reine"));
		afficheur.afficherPerso(&lucina);
		//TODO boucle de jeu + narration ?
		//TODO marchand random
		//TODO upgrade IA

		//std::system("clear");
		//std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		whaitForKey();
		combat(&lucina,&malak);
	}

	std::cout << "Fin \nPress any key (other than Enter) and press Enter" << std::endl;
	std::string h;
	std::cin >> h;
	std::cout << std::endl << std::endl;
	delete marchand;
	return 0;
}
