/*
 * CreateurPersonnage.cpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "CreateurPersonnage.hpp"

//class CreateurPersonnage
	Personnage CreateurPersonnage::creationPersonnage(){
		string nom = "";
		string classe = "";
		Branche* branche = nullptr;
		while(nom == ""){
			cout << "Quel sera le nom de votre personnage ?" << endl;
			cin >> nom;
			if(nom == ""){
				cout << "UN NOM CE HERO RECLAME, MERITE UN NOM UN VRAI !" << endl;
			}
		}
		texteBranche(nom);
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		texteBranche(nom);
		while((!test) || (cmd1.length() != 1)){
			std::cin >> cmd1;
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					//need instancieur pour get les branches
					branche;
					test = true;
					break;
				case 2:
					branche;
					test = true;
					break;
				case  3:
					branche;
					test = true;
					break;
				default :
					std::cout << "entre 1 et 3 merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::cout << "Veuiller enter un nombre compris entre 1 et 3" << std::endl;

			}
		}
		std::vector<Classe*> classeDeBranche;
		//need instancieur pour get les classes qui sont de la branche

	}


	void CreateurPersonnage::texteBranche(std::string nom){
		std::cout << "Bien maintenant il est temps de choisir une branche de classe pour " << nom << "." << std::endl;
		std::cout << "Trois choix s'offre a vous :" << std::endl
			 << "Le clerger, des soingeurs solides mais avec des degats limites" << std::endl
			 << "L'ordre des guerriers, des soldats repute pour leur force et leur armures, mais a l'intelligence et la sagesse limites" << std::endl
			 << "La loge des mages, des erudits aussi sages qu'intelligents mais dont leur force physique est equivalente a la solidite de leur robes." << std::endl;
		std::cout << "1/ Pour être un menbre du clerger\n\t2/ Pour appartenir à l'ordre des guerriers\n\t3/ Pour pouvoir siègé à la loge des magiciens" << std::endl;
	}

