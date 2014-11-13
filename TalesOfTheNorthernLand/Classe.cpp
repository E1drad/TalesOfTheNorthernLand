/*
 * Classe.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Classe.hpp"

//class Classe
	Classe::Classe(std::string nC, std::vector<int> mS, std::string b){
		this->nomClasse = nC;
		this->modificateurStatistique = mS;
		this->branche = b;
	}

	std::vector<int> Classe::getmodificateurStatistique(){
		return this->modificateurStatistique;
	}

	Classe::~Classe(){

	}

	std::string Classe::getNomClasse(){
		return this->nomClasse;
	}
	std::string Classe::getBranche(){
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
	ClasseHeroique::ClasseHeroique(std::string nc, std::vector<int> ms, std::string b, Technique* t1, Technique* t2, int nT1, int nT2):Classe::Classe(nc,ms,b){
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

	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseParagon
/*	ClasseParangon::ClasseParangon(std::string nc, std::vector<int> ms, std::string b, Technique t1, Technique t2, int nT1, int nT2):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->technique2 = t2;
		this->niveauTechnique1 = nT1;
		this->niveauTechnique2 = nT2;
	}

	Technique ClasseParangon::getTechnique1() {
		return this->technique1;
	}

	Technique ClasseParangon::getTechnique2() {
		return this->technique2;
	}

	int ClasseParangon::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	int ClasseParangon::getniveauTechnique2() {
		return this->niveauTechnique2;
	}

	ClasseParangon::~ClasseParangon(){

	}
*/
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseDivine
/*	ClasseDivine::ClasseDivine(std::string nc, std::vector<int> ms, std::string b, Technique t1, int nT1):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->niveauTechnique1 = nT1;
	}

	Technique ClasseDivine::getTechnique1() {
		return this->technique1;
	}
	int ClasseDivine::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	ClasseDivine::~ClasseDivine(){

	}
*/
