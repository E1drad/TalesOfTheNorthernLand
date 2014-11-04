/*
 * Main.cpp
 *
 *  Created on: 26 sept. 2014
 *      Author: BEGAUDEAU Charles
 */

#include "Personnage.hpp"
#include "string"
using namespace std;


int main(){
	int a[] = {0,20,20,5,5,5,5,5,5,5,0,0};
	vector<int> sStatReel (a, a + sizeof(a) / sizeof(int));
	int b[] = {0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> sStatTemp (b, b + sizeof(b) / sizeof(int));
	int c[] = {50,1,0,0,0,0,0,0,0,0,50,1};
	vector<int> sStatArme (c, c + sizeof(c) / sizeof(int));
	Statistique statistique(sStatReel, sStatTemp, sStatArme);

	int d[] = {0,-2,-2,-1, 1,3,3,1,0,1,0,0};
	vector<int> sStatElfe (d, d + sizeof(d) / sizeof(int));
	Race race(string("elfe"), sStatElfe);

	int e[] = {0, 1, 1,-1,-1,0,0,1,4,4,0,0};
	vector<int> sStatPrincesse (e, e + sizeof(e) / sizeof(int));
	ClasseHeroique classe(string("Princesse"), sStatPrincesse, string("Clerger"), Technique(string("zele")), Technique(string("celeste")), 5, 15);

	Personnage lucina(statistique, string("Lucina"), classe, race, true);
	return 0;
}

//Statistique s(std::vector<int>(12,5),std::vector<int>(12,5),std::vector<int>(12,5));
