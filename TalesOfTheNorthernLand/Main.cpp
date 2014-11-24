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
#include "Afficheur.hpp"
#include "Instancieur.hpp"
//#include <ctime> ancien methode
//srand(time(0));//ancien methode !

//#include <random>//nouvelle methode !
//std::random_device rd;//nouvelle methode !
//std::mt19937 rng(rd());//nouvelle methode !
//rng();//nouvelle methode !



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
			//lucina.attaquer(&raven);
			persoJoueur->actionCombat(persoIA);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		std::system("clear");
		afficheur.afficherPersos(persoJoueur,persoIA);
		if(!persoIA->estMort()){
			persoIA->attaquer(persoJoueur);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	}
}

int main(void){
	Afficheur afficheur;
	//Instancieur* instancieur = new Instancieur();
	Marchand* marchand = new Marchand();
	Branche clerger(std::string("Clerger"));
	clerger.vectorAdd6String("It too late for redemption, sinner!","Pick a god and prey"
			,"Be ready to meet your maker","Hope will never die","I challenge my fate"
			,"I live to make the impossible possible");
	Branche guerrier(std::string("Guerrier"));
	guerrier.vectorAdd6String("Stand up and fight","You will pay the iron price"
			,"Look like the champ gonna kill you","Just you and me!","Fear my wrath"
			,"Nice, i needed a skull for my wine");
	Branche mage(std::string("Mage"));
	mage.vectorAdd6String("Resistance is futile, you will be annihilated !",
			"With your death my research will make huge progress.","Begone, foul miscreation!",
			"How well will you die?","A predictable outcome.","You're already dead..");

	std::vector<int> sStatElfe;
	vectorAdd10Int(sStatElfe,0,-2,-2,-1,1,3,3,1,0,1);
	std::string nomElfe = "elfe";
	Race elfe(nomElfe , sStatElfe);

	std::vector<int> sStatGenasi;
	vectorAdd10Int(sStatGenasi,0,-5,-5,2,-1,1,-1,-1,3,3);
	std::string nomGenasi = "genasi";
	Race genasi(nomGenasi,sStatGenasi);

	std::vector<int> sStatPrincesse;
	vectorAdd10Int(sStatPrincesse,0,1,1,-1,-1,0,0,1,4,4);
	TechniqueStatistique* zele = new TechniqueStatistique(std::string("zele"), 9);
	TechniqueStatistique* celeste = new TechniqueStatistique(std::string("celeste"), 7);
	ClasseHeroique pretresse(std::string("Pretresse"), sStatPrincesse, &clerger, zele, celeste, 5, 15);

	std::vector<int> sStatArcher;
	vectorAdd10Int(sStatArcher,0,1,1,2,-2,4,2,1,1,-2);
	TechniqueStatistique* adresse = new TechniqueStatistique(std::string("adresse"), 6);
	TechniqueStatistique* colosse = new TechniqueStatistique(std::string("colosse"), 3);
	ClasseHeroique archer(std::string("Archer"), sStatArcher, &guerrier, adresse, colosse, 5, 15);

	std::vector<int> sStatReine;
	vectorAdd10Int(sStatReine,0,10,10,4,2,4,2,8,6,6);
	TechniqueStatistique* volonter = new TechniqueStatistique(std::string("volonter"), 8);
	TechniqueStatistique* demiDieu = new TechniqueStatistique(std::string("demi dieu"), 2);;
	ClasseParangon reine(std::string("Reine"), sStatReine, &clerger, volonter, demiDieu, 5, 15);

	std::vector<int> sStatSainteReine;
	vectorAdd10Int(sStatSainteReine,0,15,15,8,8,6,7,15,8,8);
	ClasseDivine sainteReine(std::string("Sainte Reine"), sStatSainteReine, &clerger, demiDieu, 5);


	std::vector<int> sStatSainte;
	vectorAdd10Int(sStatSainte,0,25,25,4,4,6,5,12,10,10);
	ClasseDivine sainte(std::string("Sainte"), sStatSainte, &clerger, volonter, 5);


	std::vector<int> stat;
	vectorAdd10Int(stat,0,20,20,5,5,5,5,5,5,5);

	Personnage lucina(stat, std::string("Lucina"), &pretresse, &elfe, true, 1);
	//afficherStat(&lucina);
	afficheur.afficherPerso(&lucina);
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	lucina.setArmeEquiper(marchand->getArme("Inferno"));
	//afficherStat(&lucina);
	afficheur.afficherPerso(&lucina);
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	Personnage raven(stat, std::string("Raven"), &archer, &genasi, false, 2);
	raven.setArmeEquiper(marchand->getArme("Lance"));
	Personnage malak(stat, std::string("Malak"), &archer, &genasi, false, 2);
	malak.setArmeEquiper(marchand->getArme("Epee longue"));

	combat(&lucina,&raven);
	if(!lucina.estMort()){
		marchand->afficherMenu(&lucina);
		afficheur.afficherPerso(&lucina);
		std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		lucina.promotion(&reine);
		afficheur.afficherPerso(&lucina);
		std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		std::system("clear");

		combat(&lucina,&malak);
	}

	std::cout << "Fin \nPress any key (other than Enter) and press Enter" << std::endl;
	std::string h;
	std::cin >> h;
	std::cout << std::endl << std::endl;
	delete adresse;
	delete colosse;
	delete zele;
	delete celeste;
	delete marchand;
	return 0;
}
