/*
 * Classe.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef CLASSE_HPP_
#define CLASSE_HPP_

#include "string"
#include "Technique.cpp"

class Classe {
private :
	std::string nomClasse;
	std::vector<int>  modificateurStatistique;
	std::string branche;

public :

	Classe(std::string nC, std::vector<int> mS, std::string b);
	std::vector<int> getmodificateurStatistique();
};

class ClasseHeroique : public Classe {
private:
	Technique technique1;
	Technique technique2;
	int niveauTechnique1;
	int niveauTechnique2;
public:
	ClasseHeroique(std::string nC, std::vector<int> mS, std::string b, Technique te1, Technique t2, int nT1, int nT2);
	Technique getTechnique1();
	Technique getTechnique2();
	int getniveauTechnique1();
	int getniveauTechnique2();
};

class ClasseParagon : public Classe {
private:
	Technique technique1;
	Technique technique2;
	int niveauTechnique1;
	int niveauTechnique2;
public:
	ClasseParagon(std::string nC, std::vector<int> mS, std::string b, Technique te1, Technique t2, int nT1, int nT2);
	Technique getTechnique1();
	Technique getTechnique2();
	int getniveauTechnique1();
	int getniveauTechnique2();
};

class ClasseDivine : public Classe {
private:
	Technique technique1;
	int niveauTechnique1;
public:
	ClasseDivine(std::string nC, std::vector<int> mS, std::string b, Technique t1, int nT1);
	Technique getTechnique1();
	int getniveauTechnique1();
};


#endif /* CLASSE_HPP_ */
