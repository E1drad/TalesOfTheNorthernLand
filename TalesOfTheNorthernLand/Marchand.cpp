/*
 * Marchand.cpp
 *
 *  Created on: 21 nov. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Marchand.hpp"

	/*Marchand::Marchand(Pool poolArme){
		for(unsigned int i = 0 ; i < poolArme.getPool().size(); ++i){
			if(typeid(poolArme.getPool().at(i)) == typeid(Arme())){
				this->Armes.push_back(poolArme.getPool().at(i));
			}
		}
	}*/

	Marchand::Marchand(){
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


	Marchand::~Marchand(){

	}

	void Marchand::marcher(Personnage *perso){
		afficherMenu(perso);
	}


	void Marchand::afficherMenu(Personnage *perso){
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		while((!test) || (cmd1.length() != 1)){
			std::cout << "\t1/ Pour acheter une arme \n\t"
					" 2/ Pour ameliorer votre arme" << std::endl;
			std::cin >> cmd1;
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					this->achat(perso);
					test = true;
					break;
				case 2:
					this->ameliorer(perso->getArmeActuelle());
					test = true;
					break;
				default :
					std::cout << "entrer 1 et 2 merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::cout << "Veuiller enter un nombre compris entre 1 et 2" << std::endl;
			}
		}//while
	}


	void Marchand::achat(Personnage *perso){

	}

	Arme* Marchand::getArme(std::string nomArme){
		unsigned int i = 0;
		bool test = false;
		Arme* arme = nullptr;
		while(i < this->armes.size() || !test){
			if(this->armes.at(i)->getNomItem() == nomArme){
				test = true;
				arme = this->armes.at(i);
			}
			i = i + 1;
		}
		return arme;
	}

	void Marchand::ameliorer(Arme *arme){
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		while((!test) || (cmd1.length() != 1)){
			std::cout << "\t1/ Pour ameliorer les degats  \n\t"
					" 2/ Pour ameliorer la prescision \n\t"
					" 3/ Pour ameliorer sa capacité a faire des coups critiques"
					" 4/ Pour quitter" << std::endl;
			std::cin >> cmd1;
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					arme = new AmeliorationDegat(arme);
					break;
				case 2:
					arme = new AmeliorationPrecision(arme);
					break;
				case 3:
					arme = new AmeliorationCritique(arme);;
					break;
				case 4:
					test = true;
					break;
				default :
					std::cout << "entrer 1 et 4 merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::cout << "Veuiller enter un nombre compris entre 1 et 4" << std::endl;
			}
		}//while
	}
