/*
 * Instancieur.hpp
 *
 *  Created on: 21 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef INSTANCIEUR_HPP_
#define INSTANCIEUR_HPP_

#include <vector>
#include <string>
#include "Armes.hpp"
#include "Item.hpp"

class Instancieur {
private:
	std::vector<Arme*> armes;
public:
	Instancieur();
	~Instancieur();
	std::vector<Arme*> getArmes();
	Arme* getArme(std::string nomArme);
};

#endif /* INSTANCIEUR_HPP_ */
