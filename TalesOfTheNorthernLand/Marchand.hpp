/*
 * Marchand.hpp
 *
 *  Created on: 21 nov. 2014
 *      Author: Charles BEGAUDEAU
 */
#ifndef MARCHAND_HPP_
#define MARCHAND_HPP_

#include "Personnage.hpp"
#include "Armes.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "Afficheur.hpp"
#include <random>

//std::random_device rd;//nouvelle methode !
//std::mt19937 rng(rd());//nouvelle methode !
//rng();//nouvelle methode !


class Marchand {
private:
	std::vector<Arme*> armes;
	void waitForKey();
public:
	//Marchand(Pool poolArme);
	//Marchand();
	Marchand(std::vector<Arme*> vecInsatancieur);
	~Marchand();
	void marcher(Personnage *perso);
	void afficherMenu(Personnage *perso);
	void achat(Personnage *perso);
	void ameliorer(Personnage *perso);
	Arme* getArme(std::string nomArme);
	int min(int a, int b);
	bool contains(std::vector<Arme*> vec, Arme* arme);

};

#endif /* MARCHAND_HPP_ */
