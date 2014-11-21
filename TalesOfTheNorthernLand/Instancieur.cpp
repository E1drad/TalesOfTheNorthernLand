/*
 * Instancieur.cpp
 *
 *  Created on: 21 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Instancieur.hpp"

	Instancieur::Instancieur(){
		Lance *lance1 = new Lance("Lance", 7, 75, 5, false, 80);
		Epee *epee1 = new Epee("Epee longue", 6, 65, 5, false, 100);
		Sort *ruine1 = new Sort("Ruine", 8, 85, 5, true, 120);
		Epee *epee2 = new Epee("Epee batarde", 10, 65, 5, false, 600);
		Sort *ruine2 = new Sort("Graviter", 12, 85, 5, true, 500);
		Lance *lance2 = new Lance("Lance de la veriter", 9, 75, 5, false, 400);
		Epee *epee3 = new Epee("Epee deux à main", 13, 65, 5, false, 800);
		Sort *ruine3 = new Sort("Inferno", 15, 85, 5, true, 1000);
		Lance *lance3 = new Lance("Lance de la justice", 12, 75, 5, false, 700);
		this->armes.push_back(lance1);
		this->armes.push_back(lance2);
		this->armes.push_back(lance3);
		this->armes.push_back(epee1);
		this->armes.push_back(epee2);
		this->armes.push_back(epee3);
		this->armes.push_back(ruine1);
		this->armes.push_back(ruine2);
		this->armes.push_back(ruine3);
	}

	Instancieur::~Instancieur(){

	}

	std::vector<Arme*> Instancieur::getArmes(){
		return this->armes;
	}


	Arme* Instancieur::getArme(std::string nomArme){
		unsigned int i = 0;
		bool test = false;
		Arme* arme = nullptr;
		while(i < this->armes.size() || !test){
			if(this->armes.at(i)->getNomItem() == nomArme){
				test = true;
				arme = this->armes.at(i);
			}
			i = i +1;
		}
		return arme;
	}
