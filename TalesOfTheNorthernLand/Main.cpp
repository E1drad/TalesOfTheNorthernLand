/*
 * Main.cpp
 *
 *  Created on: 26 sept. 2014
 *      Author: BEGAUDEAU Charles
 */

#include "Personnage.hpp"
#include <vector>
#include "string"
using namespace std;


int main(){


	int d[] = {0,-2,-2,-1, 1,3,3,1,0,1,0,0};
	vector<int> sStatElfe (d, d + sizeof(d) / sizeof(int));
	Race race(string("elfe"), sStatElfe);

	int e[] = {0, 1, 1,-1,-1,0,0,1,4,4,0,0};
	vector<int> sStatPrincesse (e, e + sizeof(e) / sizeof(int));
	ClasseHeroique classe(string("Princesse"), sStatPrincesse, string("Clerger"), Technique(string("zele")), Technique(string("celeste")), 5, 15);

	int a[] = {0,20,20, 5, 5,5,5,5,5,5,0,0};
	vector<int> stat (a, a + sizeof(a) / sizeof(int));
	Personnage lucina(stat, string("Lucina"), classe, race, true);
	return 0;
}
