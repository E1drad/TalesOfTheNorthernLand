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
#include "SixPool.hpp"
#include <vector>
#include "Afficheur.hpp"


class Marchand {
private:
	std::vector<Arme*> armes;
public:
	//Marchand(Pool poolArme);
	Marchand();
	~Marchand();
	void marcher(Personnage *perso);
	void afficherMenu(Personnage *perso);
	void achat(Personnage *perso);
	void ameliorer(Arme *arme);
	Arme* getArme(std::string nomArme);

};

#endif /* MARCHAND_HPP_ */
