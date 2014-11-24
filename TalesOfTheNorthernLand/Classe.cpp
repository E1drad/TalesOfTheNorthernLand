/*
 * Classe.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Classe.hpp"
#include "Personnage.hpp"

	std::random_device rd3;
	std::mt19937 rng3(rd3());
	std::random_device rd2;
	std::mt19937 rng2(rd2());
//class Classe
	Classe::Classe(std::string nC, std::vector<int> mS, Branche* b){
		this->nomClasse = nC;
		this->modificateurStatistique = mS;
		this->branche = b;
	}

	std::vector<int> Classe::getmodificateurStatistique(){
		return this->modificateurStatistique;
	}

	Classe::~Classe(){
		std::cout << "Classe is being deleted" << std::endl;
		this->branche = nullptr;
		delete this->branche;
	}

	std::string Classe::getNomClasse(){
		return this->nomClasse;
	}
	Branche* Classe::getBranche(){
		return this->branche;
	}

	std::string Classe::getmodificateurStatistiqueString(){
		std::string s;
		s = "";
		for(unsigned int i = 0; i < this->modificateurStatistique.size(); ++i ){
			s = s + " " + std::to_string(this->modificateurStatistique.at(i));
		}
		return s;
	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseHeroique
	ClasseHeroique::ClasseHeroique(std::string nc, std::vector<int> ms, Branche* b, Technique* t1, Technique* t2, int nT1, int nT2):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->technique2 = t2;
		this->niveauTechnique1 = nT1;
		this->niveauTechnique2 = nT2;
	}

	Technique* ClasseHeroique::getTechnique1() {
		return this->technique1;
	}

	Technique* ClasseHeroique::getTechnique2() {
		return this->technique2;
	}

	int ClasseHeroique::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	int ClasseHeroique::getniveauTechnique2() {
		return this->niveauTechnique2;
	}

	ClasseHeroique::~ClasseHeroique(){
		std::cout << "ClasseHeroique is being deleted" << std::endl;
		this->technique1 = nullptr;
		this->technique2 = nullptr;
		delete this->technique1;
		delete this->technique2;
	}

	int ClasseHeroique::attaquer(int degat, int statAttaque){
		int jetDe;
		jetDe = (rng2() % 2);
		if(jetDe == 1){
			std::cout << "Un coup de champion !" << std::endl;
			degat = ceil(degat * 1.10);
		}else if(jetDe <= floor(statAttaque/3) ) {
			std::cout << "Un coup prodigieux !" << std::endl;
			degat = ceil(degat * 1.05);
		}
		std::cout << this->branche->getCitationAt(jetDe) << std::endl;
		return degat;
	}

	int ClasseHeroique::mort(int statChance, int pvMax){
		int jetDe;
		int regain = 0;
		jetDe = (rng3() % 100) + 1;
		std::cout << " Regain ? " << jetDe << std::endl;
		if(jetDe == 1){
			regain = ceil(pvMax * 0.10);
		}
		return regain;
	}

	void ClasseHeroique::promotion(Personnage *p, Classe* c){
		p->setClasseParangon(c);
		p->setClasseActuelle(p->getClasseParangon());
	}

	void ClasseHeroique::decheance(Personnage* p){
		std::cout << "LOLWUT ? I know someone who will be find dead S00N !" << std::endl;//ne doit pas être utiliser
		//ne doit pas être utiliser
	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseParagon
	ClasseParangon::ClasseParangon(std::string nc, std::vector<int> ms, Branche* b, Technique* t1, Technique* t2, int nT1, int nT2):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->technique2 = t2;
		this->niveauTechnique1 = nT1;
		this->niveauTechnique2 = nT2;
	}

	Technique* ClasseParangon::getTechnique1() {
		return this->technique1;
	}

	Technique* ClasseParangon::getTechnique2() {
		return this->technique2;
	}

	int ClasseParangon::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	int ClasseParangon::getniveauTechnique2() {
		return this->niveauTechnique2;
	}

	ClasseParangon::~ClasseParangon(){
		std::cout << "ClasseParangon is being deleted" << std::endl;
		this->technique1 = nullptr;
		this->technique2 = nullptr;
		delete this->technique1;
		delete this->technique2;
	}

	int ClasseParangon::attaquer(int degat, int statAttaque){
		int jetDe;
		jetDe = (rng3() % 100) + 1;
		if(jetDe == 1){
			std::cout << "Un coup de maitre !" << std::endl;
			degat = ceil(degat * 1.25);
		}else if(jetDe <= floor(statAttaque/3) ) {
			std::cout << "Un coup de genie !" << std::endl;
			degat = ceil(degat * 1.10);
		}
		jetDe = (rng2() % 2) + 2;
		std::cout << this->branche->getCitationAt(jetDe) << std::endl;
		return degat;

	}

	int ClasseParangon::mort(int statChance, int pvMax){
		int jetDe;
		int regain = 0;
		jetDe = (rng3() % 100) + 1;
		std::cout << " Regain ? " << jetDe << std::endl;
		if(jetDe == 1){
			regain = ceil(pvMax * 0.25);
		}else if(jetDe <= floor(statChance/5) ) {
			regain = ceil(pvMax * 0.15);
		}
		return regain;
	}

	void ClasseParangon::promotion(Personnage* p, Classe* c){
		p->setClasseDivine(c);
		p->setClasseActuelle(p->getClasseDivine());
	}

	void ClasseParangon::decheance(Personnage* p){
		p->setClasseActuelle(p->getClasseHeroique());
	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseDivine
	ClasseDivine::ClasseDivine(std::string nc, std::vector<int> ms, Branche* b, Technique* t1, int nT1):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->niveauTechnique1 = nT1;
	}

	Technique* ClasseDivine::getTechnique1() {
		return this->technique1;
	}
	int ClasseDivine::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	ClasseDivine::~ClasseDivine(){
		std::cout << "ClasseDivine is being deleted" << std::endl;
		this->technique1 = nullptr;
		delete this->technique1;
	}

	int ClasseDivine::attaquer(int degat, int statAttaque){
		int jetDe;
		jetDe = (rng3() % 100) + 1;
		if(jetDe == 1){
			std::cout << "Un coup de divin !" << std::endl;
			degat = ceil(degat * 1.75);
		}else if(jetDe <= floor(statAttaque/2) ) {
			std::cout << "Un coup de digne d'un dieu !" << std::endl;
			degat = ceil(degat * 1.25);
		}
		jetDe = (rng2() % 2) + 4;
		std::cout << this->branche->getCitationAt(jetDe) << std::endl;
		return degat;

	}

	int ClasseDivine::mort(int statChance, int pvMax){
		int jetDe;
		int regain = 0;
		jetDe = (rng3() % 100) + 1;
		std::cout << " Regain ? " << jetDe << std::endl;
		if(jetDe == 1){
			regain = ceil(pvMax * 0.25);
		}else if(jetDe <= floor(statChance/5) ) {
			regain = ceil(pvMax * 0.15);
		}
		return regain;
	}

	void ClasseDivine::promotion(Personnage* p, Classe* c){
		std::cout << "LOLWUT ? I know someone who will be find dead S00N !" << std::endl;//ne doit pas être utiliser
	}

	void ClasseDivine::decheance(Personnage* p){
		p->setClasseActuelle(p->getClasseParangon());
	}
