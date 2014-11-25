/*
 * CreateurPersonnage.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef CREATEURPERSONNAGE_HPP_
#define CREATEURPERSONNAGE_HPP_

#include "Personnage.hpp"
#include "Branche.hpp"
#include "Classe.hpp"
#include <iostream>
#include <string>
#include <vector>

class CreateurPersonnage{
private:

public:
	Personnage creationPersonnage();
	void texteBranche(std::string nom);
};
#endif /* CREATEURPERSONNAGE_HPP_ */
