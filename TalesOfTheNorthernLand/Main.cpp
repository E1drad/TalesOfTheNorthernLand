/*
 * Main.cpp
 *
 *  Created on: 26 sept. 2014
 *      Author: BEGAUDEAU Charles
 */
#include "Technique.hpp"
#include "Classe.hpp"
#include "Race.hpp"
//#include "Personnage.hpp"*/
#include "Armes.hpp"
#include "Item.hpp"
#include <vector>
#include <string>
#include <iostream>

int main(void){


	Arme epee("Epee batarde", 0, 8, 75, 5, false);

	std::cout << epee.getNomItem() << " " << epee.getType() << " " << epee.getDegat() << " " << epee.getPrecision() <<
			" " << epee.getCritique() << " " << epee.getEstMagique() << std::endl;

	//int d[] = {0,-2,-2,-1, 1,3,3,1,0,1,0,0};

	std::vector<int> sStatElfe;
	sStatElfe.push_back(0);
	sStatElfe.push_back(-2);
	sStatElfe.push_back(-2);
	sStatElfe.push_back(-1);
	sStatElfe.push_back(1);
	sStatElfe.push_back(3);
	sStatElfe.push_back(3);
	sStatElfe.push_back(1);
	sStatElfe.push_back(0);
	sStatElfe.push_back(1);
	sStatElfe.push_back(0);
	sStatElfe.push_back(0);
	std::string nomRace = "elfe";
	Race race(nomRace , sStatElfe);
	std::cout << race.getNomRace() << " " << race.getmodificateurStatistiqueString() << std::endl;


	//int e[] = {0, 1, 1,-1,-1,0,0,1,4,4,0,0};
	std::vector<int> sStatPrincesse; //(e, e + sizeof(e) / sizeof(int));
	sStatPrincesse.push_back(0);
	sStatPrincesse.push_back(1);
	sStatPrincesse.push_back(1);
	sStatPrincesse.push_back(-1);
	sStatPrincesse.push_back(-1);
	sStatPrincesse.push_back(0);
	sStatPrincesse.push_back(0);
	sStatPrincesse.push_back(1);
	sStatPrincesse.push_back(4);
	sStatPrincesse.push_back(4);
	sStatPrincesse.push_back(0);
	sStatPrincesse.push_back(0);
	TechniqueStatistique* zele = new TechniqueStatistique(std::string("zele"), 2);
	TechniqueStatistique* celeste = new TechniqueStatistique(std::string("celeste"), 1);
	ClasseHeroique classe(std::string("Princesse"), sStatPrincesse, std::string("Clerger"), zele, celeste, 5, 15);

	std::cout << classe.getNomClasse() << " " << classe.getBranche() << " " << classe.getTechnique1()->getNomTechnique() << " " << classe.getTechnique2()->getNomTechnique() << " " << classe.getmodificateurStatistiqueString() << std::endl;
/*
	//int a[] = {0,20,20, 5, 5,5,5,5,5,5,0,0};
	vector<int> stat;// (a, a + sizeof(a) / sizeof(int));
	stat.push_back(0);
	stat.push_back(20);
	stat.push_back(20);
	stat.push_back(5);
	stat.push_back(5);
	stat.push_back(5);
	stat.push_back(5);
	stat.push_back(5);
	stat.push_back(5);
	stat.push_back(5);
	stat.push_back(0);
	stat.push_back(0);

	//Personnage lucina(stat, string("Lucina"), classe, race, true);
	for(int i = 0; i<12; ++i){
		cout << "statElfe a " << i << " : " << sStatElfe.at(i) << endl;
	}
	for(int i = 0; i<12; ++i){
		cout << "statPrincesse a " << i << " : " << sStatPrincesse.at(i) << endl;
	}
	for(int i = 0; i<12; ++i){
		cout << "statLucina a " << i << " : " << stat.at(i) << endl;
	}*/


	return 0;
}


/*
 * Plop, ai jeté un oeil sur ton code.
 * Tu as des soucis de redéfinition de tes classes ^^.
 * Notamment pour Items.cpp, dans Item.hpp tu fais class item{}; et du coup dans Items.cpp
 * tu ne devrais pas avoir class Item{];
 * ,ça va que dans le hpp. Dans cpp t'as que les fonctions du coup c'est plus facile
 * et tes include de string, c'est include <string> pas include "string" les ""
 *  c'pour les trucs que tu rajoutes toi genre les .h ^^
 * Et je crois que t'es obligé d'y mettre un Classe::fonction() dans les cpp
 * (t'as aussi des include en trop) (notamment, armes.hpp avait un include vers personnage qui a
 * un include vers arme ^^", du coup double include et ça rale parce qu'il peut pas
 * builde l'un sans l'autre ni l'autre sans l'un)
 * après j'ai eu la flemme de regarder plus °o°"
 * et je sais pas faire un pull request sinon je t'aurais proposé un truc ^^"
 */

