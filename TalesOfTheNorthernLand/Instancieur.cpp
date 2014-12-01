/*
 * Instancieur.cpp
 *
 *  Created on: 21 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Instancieur.hpp"

	Instancieur::Instancieur(){
        makeArmes();
        makeBranches();
        makeRaces();
        makeClasses();
	}

	Instancieur::~Instancieur(){

	}

	std::vector<Arme*> Instancieur::getArmes(){
		return this->armes;
	}

	void Instancieur::vectorAdd10Int(std::vector<int> &Vec, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
        Vec.push_back(a);  Vec.push_back(b);  Vec.push_back(c);  Vec.push_back(d);  Vec.push_back(e);
        Vec.push_back(f);  Vec.push_back(g);  Vec.push_back(h);  Vec.push_back(i);  Vec.push_back(j);
    }

    void Instancieur::makeArmes(){
        Lance *lance1 = new Lance("Lance", 7, 75, 5, false, 80);
		Epee *epee1 = new Epee("Epee longue", 6, 65, 5, false, 100);
		Sort *sort1 = new Sort("Ruine", 8, 85, 5, true, 120);
		Epee *epee2 = new Epee("Epee batarde", 10, 65, 5, false, 600);
		Sort *sort2 = new Sort("Graviter", 12, 85, 5, true, 500);
		Lance *lance2 = new Lance("Lance de la veriter", 9, 75, 5, false, 400);
		Epee *epee3 = new Epee("Epee deux à main", 13, 65, 5, false, 800);
		Sort *sort3 = new Sort("Inferno", 15, 85, 5, true, 1000);
		Lance *lance3 = new Lance("Lance de la justice", 12, 75, 5, false, 700);
		this->armes.push_back(lance1);
		this->armes.push_back(lance2);
		this->armes.push_back(lance3);
		this->armes.push_back(epee1);
		this->armes.push_back(epee2);
		this->armes.push_back(epee3);
		this->armes.push_back(sort1);
		this->armes.push_back(sort2);
		this->armes.push_back(sort3);
    }

    void Instancieur::makeBranches(){
        Branche *clerger = new Branche(std::string("Clerger"));
        clerger->vectorAdd6String("It too late for redemption, sinner!","Pick a god and prey"
                ,"Be ready to meet your maker","Hope will never die","I challenge my fate"
                ,"I live to make the impossible possible");
        branches.push_back(clerger);

        Branche *guerrier = new Branche(std::string("Guerrier"));
        guerrier->vectorAdd6String("Stand up and fight","You will pay the iron price"
                ,"Look like the champ gonna kill you","Just you and me!","Fear my wrath"
                ,"Nice, i needed a skull for my wine");
        branches.push_back(guerrier);

        Branche *mage = new Branche(std::string("Mage"));
        mage->vectorAdd6String("Resistance is futile, you will be annihilated !",
                "With your death my research will make huge progress.","Begone, foul miscreation!",
                "How well will you die?","A predictable outcome.","You're already dead..");
        branches.push_back(mage);
    }

    void Instancieur::makeRaces(){
        std::vector<int> sStatElfe;
        vectorAdd10Int(sStatElfe,0,-2,-2,-1,1,3,3,1,0,1);
        std::string nomElfe = "elfe";
        Race *elfe = new Race(nomElfe , sStatElfe);
        races.push_back(elfe);

        std::vector<int> sStatGenasi;
        vectorAdd10Int(sStatGenasi,0,3,3,2,-1,1,-1,-1,3,3);
        std::string nomGenasi = "genasi";
        Race *genasi = new Race(nomGenasi,sStatGenasi);
        races.push_back(genasi);
    }

    /*
     * WARNING LES NOMS DE BRANCHE COMMENCE PAR UN MAJUSCULE ie getBranche("clerger") => std::out_of_range !!!
     */
    void Instancieur::makeClasses(){
        std::vector<int> sStatArcher;
        vectorAdd10Int(sStatArcher,0,1,1,2,-2,4,2,1,1,-2);
        TechniqueStatistique* adresse = new TechniqueStatistique(std::string("adresse"), 6);
        TechniqueStatistique* colosse = new TechniqueStatistique(std::string("colosse"), 3);
        ClasseHeroique *archer = new ClasseHeroique(std::string("Archer"), sStatArcher, getBranche("Guerrier"), adresse, colosse, 5, 15);
        classesH.push_back(archer);

        std::vector<int> sStatArcaniste;
        vectorAdd10Int(sStatArcaniste,0,10,10,4,2,4,2,8,6,6);
        TechniqueStatistique* erudit = new TechniqueStatistique(std::string("erudit"), 8);
        TechniqueStatistique* concentration = new TechniqueStatistique(std::string("concentration"), 2);
        ClasseHeroique *arcaniste = new ClasseHeroique(std::string("Arcaniste"), sStatArcaniste, getBranche("Mage"), erudit, concentration, 5, 15);
        classesH.push_back(arcaniste);

        std::vector<int> sStatPretresse;
        vectorAdd10Int(sStatPretresse,0,1,1,-1,-1,0,0,1,4,4);
        TechniqueStatistique* zele = new TechniqueStatistique(std::string("zele"), 9);
        TechniqueStatistique* celeste = new TechniqueStatistique(std::string("celeste"), 7);
        ClasseHeroique *pretresse = new ClasseHeroique(std::string("Pretresse"), sStatPretresse, getBranche("Clerger"), zele, celeste, 5, 15);
        classesH.push_back(pretresse);

        std::vector<int> sStatReine;
        vectorAdd10Int(sStatReine,0,10,10,4,2,4,2,8,6,6);
        TechniqueStatistique* volonter = new TechniqueStatistique(std::string("volonter"), 8);
        TechniqueStatistique* demiDieu = new TechniqueStatistique(std::string("demi dieu"), 2);
        ClasseParangon *reine = new ClasseParangon(std::string("Reine"), sStatReine, getBranche("Clerger"), volonter, demiDieu, 5, 15);
        classesP.push_back(reine);

        std::vector<int> sStatSainteReine;
        vectorAdd10Int(sStatSainteReine,0,18,18,8,8,6,7,15,8,8);
        ClasseDivine *sainteReine = new ClasseDivine(std::string("Sainte Reine"), sStatSainteReine, getBranche("Clerger"), demiDieu, 5);
        classesD.push_back(sainteReine);

        std::vector<int> sStatSainte;
        vectorAdd10Int(sStatSainte,0,25,25,4,4,6,5,12,10,10);
        ClasseDivine *sainte = new ClasseDivine(std::string("Sainte"), sStatSainte, getBranche("Clerger"), volonter, 5);
        classesD.push_back(sainte);

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

	Branche* Instancieur::getBranche(std::string nomBranche){
		unsigned int i = 0;
		bool test = false;
		Branche *branche = nullptr;
		while(i < branches.size() || !test){
			if(branches.at(i)->getNomBranche() == nomBranche){
				test = true;
				branche = branches.at(i);
			}
			i = i +1;
		}
		return branche;
	}

	Race* Instancieur::getRace(std::string nomRace){
		unsigned int i = 0;
		bool test = false;
		Race* race = nullptr;
		while(i <races.size() || !test){
			if(races.at(i)->getNomRace() == nomRace){
				test = true;
				race = races.at(i);
			}
			i = i +1;
		}
		return race;
	}

	ClasseHeroique* Instancieur::getClasseH(std::string nomClasse){
		unsigned int i = 0;
		bool test = false;
		ClasseHeroique* classe = nullptr;
		while(i <classesH.size() || !test){
			if(classesH.at(i)->getNomClasse() == nomClasse){
				test = true;
				classe = classesH.at(i);
			}
			i = i +1;
		}
		return classe;
	}

	ClasseParangon* Instancieur::getClasseP(std::string nomClasse){
		unsigned int i = 0;
		bool test = false;
		ClasseParangon* classe = nullptr;
		while(i <classesP.size() || !test){
			if(classesP.at(i)->getNomClasse() == nomClasse){
				test = true;
				classe = classesP.at(i);
			}
			i = i +1;
		}
		return classe;
	}

	ClasseDivine* Instancieur::getClasseD(std::string nomClasse){
		unsigned int i = 0;
		bool test = false;
		ClasseDivine* classe = nullptr;
		while(i <classesD.size() || !test){
			if(classesD.at(i)->getNomClasse() == nomClasse){
				test = true;
				classe = classesD.at(i);
			}
			i = i +1;
		}
		return classe;
	}

	std::vector<ClasseHeroique*> Instancieur::getClasseHBranche(std::string nomBranche){
		unsigned int i = 0;
		bool test = false;
		std::vector<ClasseHeroique*> retour;
		while(i <classesH.size() || !test){
			if(classesH.at(i)->getBranche()->getNomBranche() == nomBranche){
				retour.push_back(classesH.at(i));
			}
			i = i +1;
		}
		return retour;
	}



