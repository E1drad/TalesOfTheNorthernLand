/*
 * CreateurPersonnage.cpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "CreateurPersonnage.hpp"

//class CreateurPersonnage
	CreateurPersonnage::CreateurPersonnage(){
		nom = "";
		classe = "";
		branche = "";
		race = "";
		joueur = nullptr;
	}

	void CreateurPersonnage::creation(Instancieur inst){

		std::vector<int> stat;
		vectorAdd10Int(stat,0,40,40,6,6,7,7,7,9,9);


		bool ok = false;

		while(!ok){
			std::cout << "Quel sera le nom de votre personnage ?" << std::endl;
			std::cin >> nom;
			if(nom == ""){
				std::cout << "UN NOM ! CE HERO RECLAME UN NOM ! IL MERITE UN NOM, UN VRAI !" << std::endl;
			}else{
				std::cout << "Votre nom est : " << nom << "\nCela vous convient ?\ny/n :";
				ok =confiramation();
			}
		}

		texteBranche();
		std::string cmd1;
		cmd1 = "000";
		ok = false;

		while((!ok) || (cmd1.length() != 1)){
			std::cin >> cmd1;
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					//need instancieur pour get les branches
					branche = "Clerger";
					ok = true;
					break;
				case 2:
					branche = "Guerrier";
					ok = true;
					break;
				case  3:
					branche = "Mage";
					ok = true;
					break;
				default :
					std::cout << "entre 1 et 3 merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::cout << "Veuiller enter un nombre compris entre 1 et 3" << std::endl;

			}

			if(ok){
				std::cout << "Votre chemin est donc celui du " << branche << "\nCela vous convient ?\ny/n :";
				ok =confiramation();
			}
		}

		texteClasse(branche);
		unsigned int i = 0;
		while(i < inst.getClasseHBranche(branche).size()){
			std::cout << i+1 << "/ " << inst.getClasseHBranche(branche).at(1) << std::endl;
			i = i +1;
		}


	}


	bool CreateurPersonnage::confiramation(){
		char conf;
		std::cin >> conf;
		while(tolower(conf)!='y' || tolower(conf)!='n'){
			std::cout << "y/n :";
			std::cin >> conf;
		}

		if(conf=='y'){
			std::cout << "Et bien pourquoi pas, continuons !" << std::endl;
			return true;
		}
		std::cout << "Bon très bien ..." << std::endl;
		return false;
	}

	void CreateurPersonnage::texteBranche(){
		std::cout << "Bien maintenant il est temps de choisir une branche de classe pour " << nom << "." << std::endl;
		std::cout << "Trois choix s'offre a vous :" << std::endl
			 << "Le clerger, des soingeurs solides mais avec des degats limites" << std::endl
			 << "L'ordre des guerriers, des soldats repute pour leur force et leur armures, mais a l'intelligence et la sagesse limites" << std::endl
			 << "La loge des mages, des erudits aussi sages qu'intelligents mais dont leur force physique est equivalente a la solidite de leur robes." << std::endl;
		std::cout << "\t1/ Pour être un menbre du clerger\n\t2/ Pour appartenir à l'ordre des guerriers\n\t3/ Pour pouvoir siègé à la loge des magiciens" << std::endl;
	}

	void CreateurPersonnage::texteClasse(){
		std::cout << "Bien maintenant il vous faut choisir une classe pour " << nom << "." << std::endl;
		std::cout << "Voici les choix de votre branche :" << std::endl;
	}

	void CreateurPersonnage::vectorAdd10Int(std::vector<int> &Vec, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
		Vec.push_back(a);  Vec.push_back(b);  Vec.push_back(c);  Vec.push_back(d);  Vec.push_back(e);
		Vec.push_back(f);  Vec.push_back(g);  Vec.push_back(h);  Vec.push_back(i);  Vec.push_back(j);
	}




