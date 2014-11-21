/*
 * Marchand.hpp
 *
 *  Created on: 21 nov. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Personnage.hpp"
#include "Armes.hpp"
#include <string>
#include <iostream>
#include "SixPool.hpp"
#include <vector>

#ifndef MARCHAND_HPP_
#define MARCHAND_HPP_

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
