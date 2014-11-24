/*
 * Classe.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef CLASSE_HPP_
#define CLASSE_HPP_

#include <string>
#include "Technique.hpp"
#include "Branche.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <random>

class Personnage;//a cause des includes circulaires

/*
 * ATTENTION les attributs de type Technique sont des pointeurs
 * ie on utilise sa comme ceci classe.getTechnique1()->getNomTechnique()
 */

class Classe {
protected :
	std::string nomClasse;
	std::vector<int>  modificateurStatistique;
	Branche* branche;

public :

	Classe(std::string nC, std::vector<int> mS, Branche* b);
	virtual ~Classe() = 0;
	std::vector<int> getmodificateurStatistique();
	std::string getNomClasse();
	std::string getmodificateurStatistiqueString();
	Branche* getBranche();
	virtual int attaquer(int degat, int statAttaque) = 0;
	virtual int mort(int statChance, int pvMax) = 0;
	virtual void promotion(Personnage* p, Classe* c) = 0;
	virtual void decheance(Personnage* p) = 0;
};

class ClasseHeroique : public Classe {
private:
	Technique* technique1;
	Technique* technique2;
	int niveauTechnique1;
	int niveauTechnique2;
public:
	ClasseHeroique(std::string nC, std::vector<int> ms, Branche* b, Technique* t1, Technique* t2, int nT1, int nT2);
	~ClasseHeroique();
	Technique* getTechnique1();
	Technique* getTechnique2();
	int getniveauTechnique1();
	int getniveauTechnique2();
	int attaquer(int degat, int statAttaque);
	int mort(int statChance, int pvMax);
	void promotion(Personnage* p, Classe* c);
	void decheance(Personnage* p);
};

class ClasseParangon : public Classe {
private:
	Technique* technique1;
	Technique* technique2;
	int niveauTechnique1;
	int niveauTechnique2;
public:
	ClasseParangon(std::string nC, std::vector<int> ms, Branche* b, Technique* t1, Technique* t2, int nT1, int nT2);
	~ClasseParangon();
	Technique* getTechnique1();
	Technique* getTechnique2();
	int getniveauTechnique1();
	int getniveauTechnique2();
	int attaquer(int degat, int statAttaque);
	int mort(int statChance, int pvMax);
	void promotion(Personnage* p, Classe* c);
	void decheance(Personnage* p);
};

class ClasseDivine : public Classe {
private:
	Technique* technique1;
	int niveauTechnique1;
public:
	ClasseDivine(std::string nC, std::vector<int> ms, Branche* b, Technique* t1, int nT1);
	~ClasseDivine();
	Technique* getTechnique1();
	int getniveauTechnique1();
	int attaquer(int degat, int statAttaque);
	int mort(int statChance, int pvMax);
	void promotion(Personnage* p, Classe* c);
	void decheance(Personnage* p);
};


#endif /* CLASSE_HPP_ */
