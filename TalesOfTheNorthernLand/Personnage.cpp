/*
 * Personnage.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Personnage.hpp"

	std::random_device rd1;
	std::mt19937 rng1(rd1());

	/* int pointDexp;		0 | int pointDeVie;		1
	 * int pointDeVieMax;	2 | int force;			3
	 * int intelligence;	4 | int dexterite;		5
	 * int agilite;			6 | int chance;			7
	 * int armure;			8 | int sagesse;		9
	 *///statistique

	/* int degat;		0 |	int precision;		1
	 * int esquive;		2 |	int critique;		3
	 *///statistiqueDerive

	void Personnage::modificateurRace(){
		for(unsigned int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) + this->race->getmodificateurStatistique().at(i);
		}
	}
	void Personnage::modificateurClasse(Classe* classe){
		for(unsigned int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) + classe->getmodificateurStatistique().at(i);
		}
	}

	void Personnage::modificateurClasseDecheance(Classe* classe){
		for(unsigned int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) - classe->getmodificateurStatistique().at(i);
		}
	}

	Personnage::Personnage(std::vector<int> s, std::string n, ClasseHeroique* c, Race* r, bool estFemme, int niveau){
		this->nom = n;
		this->race = r;
		this->estFemme = estFemme;
		this->statistique = s;
		this->statistiqueDerive.push_back(0);//degat
		this->statistiqueDerive.push_back(0);//esq
		this->statistiqueDerive.push_back(0);//pre
		this->statistiqueDerive.push_back(0);//crit
		this->statistiqueDerive.push_back(0);//lvl attanquant
		this->statistiqueDerive.push_back(0);//lvl defenseur
		this->statistiqueDerive.push_back(0);//lvl soigneur
		this->statistiqueDerive.push_back(0);//lvl tacticien
		this->classeHeroique = c;
		this->niveau = niveau;
		this->classeActuelle = this->classeHeroique;
		this->posture = new Defenseur(this->statistiqueDerive.at(5));
		this->classeParangon = nullptr;
		this->classeDivine = nullptr;
		this->armeEquiper = nullptr;
		this->modificateurRace();
		this->modificateurClasse(this->classeActuelle);
		this->updateStatistique();
		this->argent = 1000;
	}

	Personnage::~Personnage(){
		std::cout << "Personnage is being deleted  ";
		this->race = nullptr;
		this->classeActuelle = nullptr;
		this->classeDivine = nullptr;
		this->classeHeroique = nullptr;
		this->classeParangon = nullptr;
		this->armeEquiper = nullptr;
		delete this->race;
		delete this->classeActuelle;
		delete this->classeDivine;
		delete this->classeParangon;
		delete this->classeHeroique;
		delete this->armeEquiper;
		std::cout << " " << std::endl;
	}

	void Personnage::actionCombat(Personnage *cible){
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		while((!test) || (cmd1.length() != 1)){
			std::cout << "Qu'est que " << this->nom << " va faire ?\n\t 1/ Pour attaquer\n\t"
							" 2/ Pour se soigner\n\t 3/ Pour changer de posture" << std::endl;
			std::cin >> cmd1;
			std::cin.clear();
    		std::cin.ignore(999,'\n');
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					this->attaquer(cible);
					test = true;
					break;
				case 2:
					test = this->seSoigner();//ne se soigne pas si PV = PVMAX
					break;
				case 3:
					this->changePosture();
					test = false;
					break;
				default :
					std::cout << "entre un nombre 1 et 3 merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::cout << "Veuiller enter un nombre compris entre 1 et 3" << std::endl;
			}
		}
		std::cout << "Fin de votre tour !" << std::endl;
		//std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		waitForKey();
	}

	void Personnage::combatAutomatique(Personnage *cible){
		//si pv < 35% pvMax
		if( this->statistique.at(1) < floor(0.35*this->statistique.at(2)) ){
			//si pv > 17% pvMax && pv < 75% des degat de la cible
			if( this->statistique.at(1) > floor( 0.17*this->statistique.at(2) ) && this->statistique.at(1) < cible->getStatistiqueDerive().at(0)*0.75  ){
				this->posture = new Defenseur(this->statistiqueDerive.at(5)-1);
			}else{
				this->posture = new Soigneur(this->statistiqueDerive.at(6)-1);
			}
			this->seSoigner();
		}else{
			//si precision - esquive (autrement dit le % de chance de toucher) est < 60
			if( (this->statistiqueDerive.at(1) - cible->getStatistiqueDerive().at(2)) < 60 ){
				this->posture = new Tacticien(this->statistiqueDerive.at(7)-1);
			//si pv < degat de la cible OU si pv < 60%pvMax
			}else if(  (this->statistique.at(1) < ceil(cible->getStatistiqueDerive().at(0))) || (this->statistique.at(1) < ceil(0.60*this->statistique.at(2))) ){
				this->posture = new Defenseur(this->statistiqueDerive.at(5)-1);
			}else{
				this->posture = new Attaquant(this->statistiqueDerive.at(4)-1);
			}
			this->attaquer(cible);
		}
	}


	void Personnage::changePosture(){
		std::cout << "Qu'elle posture " << this->nom << " va prendre ?" << std::endl;
		std::string cmd1;
		cmd1 = "000";
		bool test = false;
		while((!test) || (cmd1.length() != 1)){
			std::cout << "\t 1/ Pour attaquant\n\t 2/ Pour defenseur \n\t 3/ Pour soigneur \n\t 4/ Pour tacticien" << std::endl;
			std::cin >> cmd1;
			std::cin.clear();
    		std::cin.ignore(999,'\n');
			try{
				int cmd = std::stoi(cmd1);
				switch (cmd){
				case 1:
					this->posture = new Attaquant(this->statistiqueDerive.at(4));
					test = true;
					break;
				case 2:
					this->posture = new Defenseur(this->statistiqueDerive.at(5));
					test = true;
					break;
				case  3:
					this->posture = new Soigneur(this->statistiqueDerive.at(6));
					test = true;
					break;
				case  4:
					this->posture = new Tacticien(this->statistiqueDerive.at(7));
					test = true;
					break;
				default :
					std::cout << "entre un nombre 1 et 4 merci !" << std::endl;
				}
			}catch (std::invalid_argument){
				cmd1 = "000";
				std::cout << "Veuiller enter un nombre compris entre 1 et 4" << std::endl;

			}
		}
	}

	bool Personnage::seSoigner(){
		if(this->statistique.at(1) < this->statistique.at(2)){
			int soin = ceil( this->statistique.at(2) * (sin(rng1())/5 + 0.15 ) );//TODO A MODIFIER
			std::cout << this->nom << " se soin de " << soin << " points "<< std::endl;
			soin = this->posture->soigner(soin);
			if( (this->statistique.at(1) + soin) <= this->statistique.at(2)){
				this->statistique.at(1) = this->statistique.at(1) + soin;
			}else{
				this->statistique.at(1) = this->statistique.at(2);
			}
			return true;
		}
		return false;
	}

	void Personnage::setArmeEquiper(Arme* a){//TODO need update controle classe
		this->updateStatistique();
		std::cout << this->nom << " viens de s'équiper avec " << a->getNomItem() << std::endl;
		int deg = this->getStatistiqueDerive().at(0);//avant
		int pre = this->getStatistiqueDerive().at(1);//avant
		int cri = this->getStatistiqueDerive().at(3);//avant
		this->armeEquiper = a;
		this->updateStatistique();
		std::cout << deg << "\t DEG  >> " <<this->getStatistiqueDerive().at(0) << std::endl;
		std::cout << pre << "\t PRE  >> " <<this->getStatistiqueDerive().at(1) << std::endl;
		std::cout << cri << "\t CRI  >> " <<this->getStatistiqueDerive().at(3) << std::endl;
	}

	void Personnage::setClasseActuelle(Classe* classe){
		this->classeActuelle = classe;
	}

	void Personnage::setClasseParangon(Classe* classe){
		this->classeParangon = classe;
	}

	void Personnage::setClasseDivine(Classe* classe){
		this->classeDivine = classe;
	}

	void Personnage::monterNiveau(){

	}

	int Personnage::updateDegat(){
		int valeur;
		if(this->armeEquiper == nullptr){//rien ie 0
			valeur = 0;
		}else if(this->armeEquiper->getEstMagique()){//intelligence + degat
			valeur = this->statistique.at(4) + this->armeEquiper->getDegat();
		}else{//force + degat
			valeur = this->statistique.at(3) + this->armeEquiper->getDegat();
		}
		return valeur;
	}

	int Personnage::updatePrecision(){
		int valeur = 2*this->statistique.at(5);
		if( (this->armeEquiper != nullptr) ){//si diff de null
			valeur = 2*this->statistique.at(5) + this->armeEquiper->getPrecision();
		}
		return valeur;
	}

	int Personnage::updateCritique(){
		int valeur = 2*this->statistique.at(7);
		if( (this->armeEquiper != nullptr) ){//si diff de null
			valeur = 2*this->statistique.at(7) + this->armeEquiper->getCritique();
		}
		return valeur;
	}

	int Personnage::updateEsquive(){
		return this->statistique.at(6) + this->statistique.at(6);
	}

	void Personnage::updatePV(){
		if ( this->statistique.at(1) > this->statistique.at(2) ){
			this->statistique.at(1) = this->statistique.at(2);
		}
	}

	void Personnage::updateNiveau(){
		if ( (this->statistique.at(0) > 99 ) && (this->niveau < 20) ){
			this->statistique.at(0) = this->statistique.at(0) - 99;
			this->niveau = this->niveau + 1;
			std::cout << this->nom << " à gagné un niveau !!!\n\t Accès au menu de monter de niveau !" << std::endl;
			this->monterNiveau();
		}
	}

	void Personnage::prendreDegat(int degat){
		degat = this->posture->subirDegat(degat);
		if(degat >= 0){
			this->modStat(1, -degat);
			std::cout << this->nom << " a perdu " << degat << " point de vie." << std::endl;
			if(this->statistique.at(1) <= 0){
				this->mourant();
			}
		}
	}

	void Personnage::attaquer(Personnage *cible){
		int jetDe;
		int degat;
		int touche;
		this->updateStatistique();
		cible->updateStatistique();
		jetDe = (rng1() % 100) + 1;
		std::string genre = (this->estFemme)? "elle" : "il";
		std::cout << this->nom << " attaque " << cible->getNom() << ", " << genre << " fait un " << jetDe << std::endl;;
		touche = this->posture->toucher(this->statistiqueDerive.at(1));
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		if(jetDe <= touche - cible->getStatistiqueDerive().at(2)){
			std::cout << " et " << this->nom << " touche !" << std::endl;
			int statAttaque;
			int statDefense;
			statAttaque = (this->armeEquiper->getEstMagique())? 4 : 3;
			statDefense = (this->armeEquiper->getEstMagique())? 9 : 8;
			degat = this->classeActuelle->attaquer(this->statistiqueDerive.at(0), this->statistique.at(statAttaque) );
			degat = degat - cible->getStatistique().at(statDefense);
			std::cout << degat << " degats !" << std::endl;
			degat = this->posture->attaquer(degat);
			degat = this->critique(degat, cible);
			std::cout << cible->getNom() << " subit " << degat << " degats" << std::endl;
			cible->prendreDegat(degat);
		}else{
			std::cout << " mais " << this->nom << " ne touche pas !" << std::endl;
		}
	}

	void Personnage::mourant(){
		std::string genre = (this->estFemme)? "t'elle" : "t'il";
		std::cout << this->nom << " est agonisant ! Va " << genre << " mourir ?" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(333));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(333));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(333));
		std::cout << "."  << std::endl;
		this->statistique.at(1) = this->classeActuelle->mort(this->statistique.at(7), this->statistique.at(2));
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if(this->statistique.at(1) <= 0){
			genre = (this->estFemme)? "morte" : "mort";
			std::cout << this->nom << " est " << genre << " tragiquement !" << std::endl;
			this->statistique.at(1) = 0;
		}
	}

	void Personnage::modStat(int stat, int modificateur){
		this->statistique.at(stat) = this->statistique.at(stat) + modificateur;
		this->updateStatistique();
	}

	Race* Personnage::getRace(){
		return this->race;
	}

	std::string Personnage::getNom(){
		return this->nom;
	}

	Classe* Personnage::getClasseActuelle(){
		return this->classeActuelle;
	}

	bool Personnage::getEstFemme(){
		return this->estFemme;
	}

	void Personnage::updateStatistique(){
		this->statistiqueDerive.at(0) = this->updateDegat();
		this->statistiqueDerive.at(1) = this->updatePrecision();
		this->statistiqueDerive.at(2) = this->updateEsquive();
		this->statistiqueDerive.at(3) = this->updateCritique();
		this->updateNiveau();
		this->updatePV();
	}

	std::vector<int> Personnage::getStatistique(){
		return this->statistique;
	}

	std::vector<int>  Personnage::getStatistiqueDerive(){
		this->updateStatistique();
		return this->statistiqueDerive;
	}

	Classe* Personnage::getClasseHeroique(){
		return this->classeHeroique;
	}

	Classe* Personnage::getClasseParangon(){
		return this->classeParangon;
	}

	Classe* Personnage::getClasseDivine(){
		return this->classeDivine;
	}

	void Personnage::afficherStat(){
		for(unsigned int i = 0; i <this->statistique.size(); ++i){
			std::cout << this->statistique.at(i) << " ";
		}
		std::cout << "" << std::endl;
		std::cout << "deg " << this->statistiqueDerive.at(0) << std::endl;
		std::cout << "pre " << this->statistiqueDerive.at(1) << std::endl;
		std::cout << "esq " << this->statistiqueDerive.at(2) << std::endl;
		std::cout << "crit " << this->statistiqueDerive.at(3) << std::endl;

	}
//TODO make a setter for classeP and classeD and classeH
	void Personnage::promotion(Classe* classe){
		std::cout << "Vous avez peut-être être promut !" << std::endl;
		if(this->classeActuelle->promotion(this, classe)){
			this->modificateurClasse(classe);
			this->updateStatistique();
			std::cout << "Vous avez été promut a la classe de " << this->classeActuelle->getNomClasse()  << std::endl;
		}else{
			std::cout << "Vous êtes déjà une divinité que desirez-vous de plus ?" << std::endl;
		}
	}
//TODO need to make something to do a instance of
	void Personnage::decheance(){
		if(this->classeActuelle != this->classeHeroique){
			this->modificateurClasseDecheance(this->classeActuelle);
			this->classeActuelle->decheance(this);
			this->updateStatistique();
			std::cout << "Vous avez été déchut a la classe de " << this->classeActuelle->getNomClasse()  << std::endl;
		}else{
			std::cout << "impossible de descendre plus bas que le statut de Heros." << std::endl;
		}
	}

	int Personnage::critique(int degat, Personnage *cible){
		int jetDe;
		jetDe = (rng1() % 100) + 1;
		if(jetDe <= (this->statistiqueDerive.at(3)  - cible->statistique.at(7)) ){
			degat = degat * 2;
			std::cout << " COUUUUUP CRIIITIIIIQUEE !!!" << std::endl;
		}
		return degat;
	}


	bool Personnage::estMort(){
		return this->statistique.at(1) <= 0;
	}

	void Personnage::modArgent(int argent){
		this->argent = this->argent + argent;
	}

	bool Personnage::possedeAssezArgent(int argent){
		bool test = false;
		if(this->argent >= argent){
			test = true;
		}
		return test;
	}

	int Personnage::getArgent(){
		return this->argent;
	}


	Arme* Personnage::getArmeActuelle(){
		return this->armeEquiper;
	}

	void Personnage::waitForKey(){
		std::cout << "Press the ENTER key\n";
		if (std::cin.get() == '\n'){
	    	//std::cout << "Good job.\n";
		}else{
	    	//std::cout << "I meant ONLY the ENTER key... Oh well.\n";
			std::cin.clear();
    		std::cin.ignore(999,'\n');
		}
	}
	
