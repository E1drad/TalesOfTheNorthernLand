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

	std::vector Classe::getmodificateurStatistique(){
		return this->modificateurStatistique;
	}


//class ClasseHeroique
	ClasseHeroique::ClasseHeroique(std::string nC, std::vector<int> mS, std::string b, Technique te1, Technique t2, int nT1, int nT2){
		Classe(nc,ms,b);
		this->technique1 = t1;
		this->technique2 = t2;
		this->niveauTechnique1 = nT1;
		this->niveauTechnique2 = nT2;
	}

	Technique ClasseHeroique::getTechnique1() {
		return this->technique1;
	}

	Technique ClasseHeroique::getTechnique2() {
		return this->technique2;
	}

	int ClasseHeroique::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	int ClasseHeroique::getniveauTechnique2() {
		return this->niveauTechnique2;
	}

//class ClasseParagon
	ClasseParagon::ClasseParagon(std::string nC, std::vector<int> mS, std::string b, Technique te1, Technique t2, int nT1, int nT2){
		Classe(nc,ms,b);
		this->technique1 = t1;
		this->technique2 = t2;
		this->niveauTechnique1 = nT1;
		this->niveauTechnique2 = nT2;
	}

	Technique ClasseDivine::getTechnique1() {
		return this->technique1;
	}

	Technique ClasseDivine::getTechnique2() {
		return this->technique2;
	}

	int ClasseDivine::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	int ClasseDivine::getniveauTechnique2() {
		return this->niveauTechnique2;
	}

//class ClasseDivine
	ClasseDivine::ClasseDivine(std::string nC, std::vector<int> mS, std::string b, Technique t1, int nT1){
		Classe(nc,ms,b);
		this->technique1 = t1;
		this->niveauTechnique1 = nT1;
	}

	Technique ClasseDivine::getTechnique1() {
		return this->technique1;
	}
	int ClasseDivine::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

