/*
 * Marchand.cpp
 *
 *  Created on: 21 nov. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Marchand.hpp"


std::random_device rd4;//nouvelle methode !
std::mt19937 rng4(rd4());//nouvelle methode !

	int Marchand::min(int a, int b){
		if(a>b){
			return b;
		}else{
			return a;
		}
	}

	bool Marchand::contains(std::vector<Arme*> vec, Arme* arme){
		bool test = false;
		for(unsigned int i = 0; i <vec.size(); ++i){
			if(vec.at(i) == arme){
				test = true;
			}
		}
		return test;
	}

	void Marchand::waitForKey(){
		std::cout << "Press the ENTER key\n";
		if (std::cin.get() == '\n'){
		}else{
			std::cin.clear();
			std::cin.ignore(999,'\n');
		}
	}

	Marchand::Marchand(std::vector<Arme*> vecInsatancieur){
		//this->armes = vecInsatancieur;
		unsigned int sizetemp = rng4() % 6 + 4;
		unsigned int size = min(sizetemp, vecInsatancieur.size());
		unsigned int j = rng4() % (size +1);
		for(unsigned int i = 0; i < size; ++i){
			//pour varier les armes.
			if(this->contains(this->armes, vecInsatancieur.at(j))){
				j = rng4() % (size +1);
				if(this->contains(this->armes, vecInsatancieur.at(j))){
					j = rng4() % (size +1);
					if(this->contains(this->armes, vecInsatancieur.at(j))){
						j = rng4() % (size +1);
						this->armes.push_back( vecInsatancieur.at(j) );
					}else{
						this->armes.push_back( vecInsatancieur.at(j) );
					}
				}else{
					this->armes.push_back( vecInsatancieur.at(j) );
				}
			}else{
				this->armes.push_back( vecInsatancieur.at(j) );
			}
			j = rng4() % (size +1);
		}
	}


	Marchand::~Marchand(){

	}

	void Marchand::marcher(Personnage *perso){
		afficherMenu(perso);
	}


	void Marchand::afficherMenu(Personnage *perso){
		Afficheur *aff = new Afficheur();
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		while((!test) || (cmd1.length() != 1)){
			std::system("clear");
			aff->afficherPerso(perso);
			std::cout << "\t 1/ Pour acheter une arme \n\t"
					" 2/ Pour ameliorer votre arme\n\t"
					" 3/ Pour quitter" << std::endl;
			std::cin >> cmd1;
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					this->achat(perso);
					std::cin.clear();
					std::cin.ignore(999,'\n');
					waitForKey();
					break;
				case 2:
					this->ameliorer(perso);
					std::cin.clear();
					std::cin.ignore(999,'\n');
					waitForKey();
					break;
				case 3:
					test = true;
					std::cin.clear();
					std::cin.ignore(999,'\n');
					waitForKey();
					break;
				default :
					std::cout << "entrer 1 et 3 merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::cout << "Veuiller enter un nombre compris entre 1 et 3" << std::endl;
			}
		}//while
	}


	void Marchand::achat(Personnage *perso){
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		std::system("clear");
		for(unsigned int i = 0; i < this->armes.size(); ++i){
			std::cout << i+1 << "/ "; this->armes.at(i)->afficher();
		}
		std::cout << "-1/ Pour quitter" << std::endl;
		std::cout << perso->getArgent() << " Iverios" << std::endl;
		while((!test) || (cmd1.length() != 1)){
			std::cin >> cmd1;
			try{
				int cmd = std::stoi(cmd1);
				cmd = cmd -1;//compensation de l'affichage
				if(cmd > -1 && cmd < this->armes.size()){
					if(perso->possedeAssezArgent(this->armes.at(cmd)->getPrix())){
						perso->modArgent( -this->armes.at(cmd)->getPrix());
						perso->setArmeEquiper(this->armes.at(cmd));
						this->armes.erase(this->armes.begin()+cmd);
						std::cout << "Merci pour l'achat et bon voyage !" << std::endl;
						test = true;
					}else{
						std::cout << "Desole mais il semblerait que votre bourse ne pas assez remplit pour acheter " << this->armes.at(cmd)->getNomItem() << std::endl;
					}
				}else if(cmd == -2){
					std::cout << "Revenez bientôt et avec plus d'Iverios !" << std::endl;
					test = true;
				}else{
					std::cout << "entrer un nombre 1 et " << this->armes.size() << " merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::system("clear");
				std::cout << "Veuiller enter un nombre compris entre 1 et " << this->armes.size() << " ou -1 pour quitter" << std::endl;
				for(unsigned int i = 0; i < this->armes.size(); ++i){
					std::cout << i+1; this->armes.at(i)->afficher();
				}
				std::cout << "-1/ Pour quitter" << std::endl;
				std::cout << perso->getArgent() << " Iverios" << std::endl;
			}
		}//while
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

	void Marchand::ameliorer(Personnage *perso){
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		while((!test) || (cmd1.length() != 1)){
			std::cout << "\t 1/ Pour ameliorer les degats  \n\t"
					" 2/ Pour ameliorer la prescision \n\t"
					" 3/ Pour ameliorer sa capacité a faire des coups critiques\n\t"
					" 4/ Pour quitter" << std::endl;
			std::cin >> cmd1;
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					perso->setArmeEquiper(new AmeliorationDegat(perso->getArmeActuelle()));
					test = true;
					break;
				case 2:
					perso->setArmeEquiper(new AmeliorationPrecision(perso->getArmeActuelle()));
					test = true;
					break;
				case 3:
					perso->setArmeEquiper(new AmeliorationCritique(perso->getArmeActuelle()));
					test = true;
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
