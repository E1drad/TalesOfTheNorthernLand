/*
 * CreateurPersonnage.cpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Personnage.hpp"
//#include ".hpp"

//class CreateurPersonnage
	Personnage CreateurPersonnage::creationPersonnage(){
		string nom = "";
		string classe = "";
		while(nom == ""){
			cout << "Quel sera le nom de votre personnage ?" << endl;
			cin >> nom;
			if(nom == ""){
				cout << "UN NOM CE HERO RECLAME, MERITE UN NOM UN VRAI !" << endl;
			}
		}
		texteBranche();

	}

	/*
	 * Statistique statistique;
	 * string nom;
	 * Classe classe;
	 * Race race;
	 * bool estFemme;
	 * Item inventaire[5];
	 * Arme armeEquiper;
	 * ZoneDeDeplacement zoneDeDeplacement;
	 * ZoneAction zoneAction;
	 * Technique technique[5];
	 */

	void CreateurPersonnage::texteBranche(){
		cout << "Bien maintenant il est temps de choisir une branche de classe pour " << nom << "." << endl;
		cout << "Quatre choix s'offre a vous :" << endl
			 << "Le clerger, des soingeurs solides mais avec des degats limites" << endl
			 << "L'ordre des chevalier, des heros accompagnents de puissante monture qui font leur agilité mais aussi leur fragilité" << endl
			 << "L'ordre des guerriers, des soldats repute pour leur force et leur armures, mais a l'intelligence et la sagesse limites" << endl
			 << "La loge des mages, des erudits aussi sages qu'intelligents mais dont leur force physique est equivalente a la solidite de leur robes." << endl;
	}

};
