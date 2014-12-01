/*
 * CreateurPersonnage.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef CREATEURPERSONNAGE_HPP_
#define CREATEURPERSONNAGE_HPP_

#include "Personnage.hpp"
#include "Instancieur.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

class CreateurPersonnage{
private:
	Personnage* joueur;
	std::string nom;
	std::string classe;
	std::string branche;
	std::string race;
public:
	CreateurPersonnage();
	void creation(Instancieur inst);
	bool confiramation();
	void texteBranche();
	void texteClasse();
	void vectorAdd10Int(std::vector<int> &Vec, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
};
#endif /* CREATEURPERSONNAGE_HPP_ */
