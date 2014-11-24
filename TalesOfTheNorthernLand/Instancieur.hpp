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
#include "Branche.hpp"
#include "Classe.hpp"

class Instancieur {
private:
	std::vector<Arme*> armes;
	std::vector<Branche*> branches;
	std::vector<Race*> races;
	std::vector<Classe*> classes;
public:
	Instancieur();
	~Instancieur();
	void vectorAdd10Int(std::vector<int> &Vec, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	std::vector<Arme*> getArmes();
	void makeArmes();
	void makeBranches();
	void makeRaces();
	void makeClasses();
	Arme* getArme(std::string nomArme);
	Branche* getBranche(std::string nomBranche);
	Race* getRace(std::string nomRace);
	Classe* getClasse(std::string nomClasse);
};

#endif /* INSTANCIEUR_HPP_ */
