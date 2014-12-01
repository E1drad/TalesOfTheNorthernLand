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

	/**
	 * \brief	Ajoute les modificateurs de statistique raciaux au personnage
	 * \details	Ajoute les modificateurs raciaux, cette methode
	 *  est appeller lors dans le constructeur
	 */
	void Personnage::modificateurRace(){
		for(unsigned int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) + this->race->getmodificateurStatistique().at(i);
		}
	}

	/**
	 * \brief	Ajoute les modificateurs de statistique de la classe
	 * \details	Ajoute les modificateurs de la classe, cette methode
	 *  est appeller lors de la promotion et dans le constructeur
	 * \param	classe 		Classe* La classe dont on veut ajouter les modificateurs au personnage
	 *
	 */
	void Personnage::modificateurClasse(Classe* classe){
		for(unsigned int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) + classe->getmodificateurStatistique().at(i);
		}
	}

	/**
	 * \brief	Supprimer les modificateurs de statistique que l'on viens de quitter
	 * \details	Est appellé lors de la decheance pour enlever les modificateurs de statistique
	 * ajouter précédent via modificateurClasse
	 * \param	classe 		Classe* La classe dont on veut enlever les modificateurs au personnage
	 */
	void Personnage::modificateurClasseDecheance(Classe* classe){
		for(unsigned int i = 0; i < this->statistique.size(); ++i){
			this->statistique.at(i) = this->statistique.at(i) - classe->getmodificateurStatistique().at(i);
		}
	}


	/**
	 * \brief	Constructeur de Personnage
	 * \details	Sers a crée un personnage via les paramètres decrit ci desous, à initialiser ses statistiques
	 * ainsi que sa classeActuelle et initialiser sa posture a Defenseur
	 * \param	s			vector<int> Le vector de stat de base du perso
	 * \param	n			string	Le nom du personnage
	 * \param	c			ClasseHeroique*	Le pointeur vers la classe heroique(ne peut pas être modifier)
	 * \param	r			Race* La pointeur vers la race du personnage
	 * \param	estFemme	bool vrai si le personnage est une femme
	 * \param	niveau		int  indique le niveau du personnage(normale 1 au debut)
	 */
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
		if(this->niveau > 20){
			this->niveau = 20;
		}
	}

	/**
	 * \brief	Destructeur de personnage
	 * \details		remet tout les pointeurs a nullptr car les objets doivent être detruit dans l'instancieur
	 */
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


	/**
	 * \brief	Menu d'action du joueur
	 * \details	affiche le menu et en fonction d'une entré clavier appelle une methode specifique
	 * 1 pour attaquer, 2 pour se soigner, 3 pour changer de posture
	 * \param	cible Personnage* notre ennemie actuelle
	 */
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


	/**
	 * \brief	la methode de gestion prise de decision pour l'IA
	 * \param	cible Personnage* l'ennemie actuelle de l'IA (à l'heure actuelle le joueur)
	 */
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

	/**
	 * \brief	Menu de changement de posture
	 * \details	affiche le menu et en fonction d'une entré clavier crée une nouvelle posture
	 * \bug need un delete de la posture ?
	 */
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

	/**
	 * \brief	permet de se soigner
	 * \details	redonne des points de vies si les pv sont inferieurs au pvMax
	 * \return  Un \e booleen qui est vrai si on pouvait gagner des points des vie
	 */
	bool Personnage::seSoigner(){
		if(this->statistique.at(1) < this->statistique.at(2)){
			int soin = ceil( this->statistique.at(2) * (sin(rng1())/6 + 0.15 ) );//TODO A MODIFIER
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


	/**
	 * \brief	Change l'arme du personnage
	 * \details	change l'arme, met a jour les statitisques derivés et affiche la difference avant/après
	 */
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

	/**
	 * \brief setter de classeActuelle
	 * \details est utile pour les Classes lors des promotions/decheance
	 * \param	classe Classe* notre nouvelle classe actuelle
	 */
	void Personnage::setClasseActuelle(Classe* classe){
		this->classeActuelle = classe;
	}

	/**
	 * \brief setter de classeParangon
	 * \details est utile pour les Classes lors des promotions/decheance
	 * \param	classe Classe* notre nouvelle classeParangon
	 */
	void Personnage::setClasseParangon(Classe* classe){
		this->classeParangon = classe;
	}

	/**
	 * \brief setter de classeDivine
	 * \details est utile pour les Classes lors des promotions/decheance
	 * \param	classe Classe* notre nouvelle classeDivine
	 */
	void Personnage::setClasseDivine(Classe* classe){
		this->classeDivine = classe;
	}

	/**
	 * \brief	S000000000N !!!
	 * \details	S000000000N !!!
	 * \param	S000000000N !!!
	 * \param	S000000000N !!!
	 * \return	S000000000N !!!
	 */
	void Personnage::monterNiveau(){
		this->niveau = this->niveau + 1;
		std::cout << this->nom << " viens de passer au niveau " << this->niveau << std::endl;
	}

	/**
	 * \brief	calcul les degats
	 * \details	si il n'a pas d'arme degat = 0, si l'arme est magique le calcule
	 * ce fait avec l'intelligence sinon avec la force
	 * \return valeur \e int les degats du perso
	 */
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

	/**
	 * \brief	calcul la precision
	 * \return valeur \e int la precision du perso
	 */
	int Personnage::updatePrecision(){
		int valeur = 2*this->statistique.at(5);
		if( (this->armeEquiper != nullptr) ){//si diff de null
			valeur = 2*this->statistique.at(5) + this->armeEquiper->getPrecision();
		}
		return valeur;
	}

	/**
	 * \brief	calcul la valeur de critique
	 * \return valeur \e int la valeur de critique du perso
	 */
	int Personnage::updateCritique(){
		int valeur = 2*this->statistique.at(7);
		if( (this->armeEquiper != nullptr) ){//si diff de null
			valeur = 2*this->statistique.at(7) + this->armeEquiper->getCritique();
		}
		return valeur;
	}

	/**
	 * \brief	calcul l'esquive
	 * \return valeur \e int l'equive du perso
	 */
	int Personnage::updateEsquive(){
		return this->statistique.at(6) + this->statistique.at(6);
	}


	/**
	 * \brief	verifie que les pv sont inferieurs au pvMax
	 */
	void Personnage::updatePV(){
		if ( this->statistique.at(1) > this->statistique.at(2) ){
			this->statistique.at(1) = this->statistique.at(2);
		}
	}

	/**
	 * \brief	calcul l'experience et appelle la methode de monter de niveau
	 * \return valeur \e int l'equive du perso
	 */
	void Personnage::updateNiveau(){
		if ( (this->statistique.at(0) > 99 ) && (this->niveau < 20) ){
			this->statistique.at(0) = this->statistique.at(0) - 99;
			this->niveau = this->niveau + 1;
			std::cout << this->nom << " à gagné un niveau !!!\n\t Accès au menu de monter de niveau !" << std::endl;
			this->monterNiveau();
		}
	}

	/**
	 * \brief	Affiche et retire les pv perdut après mis a jour via la posture
	 * \param	degat int les degat que l'on va subir avant mis a jour via la posture
	 */
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

	/**
	 * \brief	determine si le personnage touche puis calcule les degats
	 * \details	les calculs se fait viens du rng
	 * \param	cible Personnage* l'ennemie actuelle
	 */
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
	/**
	 * \brief	determine la mort du perso en fonction de sa classe
	 * \details si le perso reussi un jet de dé il peut recupérer des points de vie et eviter la mort
	 */
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

	/**
	 * \brief	modifie une stat a une position donner d'une valeur donner puis met a jour les statistique deriver
	 * \param	stat	int la position dans le vector de stat
	 * \param	modificateur	int le modificateur de stat
	 */
	void Personnage::modStat(int stat, int modificateur){
		this->statistique.at(stat) = this->statistique.at(stat) + modificateur;
		this->updateStatistique();
	}

	/**
	 * \brief getter de Race*
	 * \return Race* le pointeur de race du perso
	 */
	Race* Personnage::getRace(){
		return this->race;
	}

	/**
	 * \brief getter de Nom
	 * \return Nom le string de nom du perso
	 */
	std::string Personnage::getNom(){
		return this->nom;
	}

	/**
	 * \brief getter de ClasseActuelle*
	 * \return ClasseActuelle* le pointeur de classe actuelle du perso
	 */
	Classe* Personnage::getClasseActuelle(){
		return this->classeActuelle;
	}

	/**
	 * \brief getter de estFemme
	 * \return estFemme vrai si le perso est une femme
	 */
	bool Personnage::getEstFemme(){
		return this->estFemme;
	}

	/**
	 * \brief appelle les autres methodes d'update
	 */
	void Personnage::updateStatistique(){
		this->statistiqueDerive.at(0) = this->updateDegat();
		this->statistiqueDerive.at(1) = this->updatePrecision();
		this->statistiqueDerive.at(2) = this->updateEsquive();
		this->statistiqueDerive.at(3) = this->updateCritique();
		this->updateNiveau();
		this->updatePV();
	}

	/**
	 * \brief getter de statistique
	 * \return statistique le vector<int> de statistique
	 */
	std::vector<int> Personnage::getStatistique(){
		return this->statistique;
	}

	/**
	 * \brief getter de statistiqueDerive retour les statistiqueDerive Après avoir fait une mise a jour
	 * \return statistique derive le vector<int> de statistique derive
	 */
	std::vector<int>  Personnage::getStatistiqueDerive(){
		this->updateStatistique();
		return this->statistiqueDerive;
	}

	/**
	 * \brief getter de classeHeroique*
	 * \return classeHeroique* le pointeur de classe Heroique du perso
	 */
	Classe* Personnage::getClasseHeroique(){
		return this->classeHeroique;
	}

	/**
	 * \brief getter de classeParangon*
	 * \return classeParangon* le pointeur de classe Parangon du perso
	 */
	Classe* Personnage::getClasseParangon(){
		return this->classeParangon;
	}

	/**
	 * \brief getter de classeDivine*
	 * \return classeDivine* le pointeur de classe Divine du perso
	 */
	Classe* Personnage::getClasseDivine(){
		return this->classeDivine;
	}


	/**
	 * \brief afficher les statistiques puis les statistiques derivées du perso
	 */
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

	/**
	 * \brief	effectue un changement d'etat "vers le haut" si les conditions sont valide
	 * \details La classe doit être "d'etat" superieur sinon il ne se passe rien (mis a part le message d'erreur
	 * inaproprier)
	 * \param	classe Classe* la classe vers laquelle on veut allé
	 */
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

	/**
	 * \brief	effectue un changement d'etat "vers le bas" si on est pas en Heroique
	 */
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

	/**
	 * \brief Determine si le coups est un coups critique
	 * \param	degat int les degat avant le calcule du critique
	 * \param	cible Personnage* notre cible actuelle
	 */
	int Personnage::critique(int degat, Personnage *cible){
		int jetDe;
		jetDe = (rng1() % 100) + 1;
		if(jetDe <= (this->statistiqueDerive.at(3)  - cible->statistique.at(7)) ){
			degat = degat * 2;
			std::cout << " COUUUUUP CRIIITIIIIQUEE !!!" << std::endl;
		}
		return degat;
	}

	/**
	 * \brief indique si le perso est mort ie pv negatif ou nul
	 * \return vrai si les pv sont negatif ou nul
	 */
	bool Personnage::estMort(){
		return this->statistique.at(1) <= 0;
	}

	/**
	 * \brief modifie l'argent selon un entier donner en param
	 * \param argent int le nombre de Pesos que l'on veut ajoute/enlever au perso
	 */
	void Personnage::modArgent(int argent){
		this->argent = this->argent + argent;
	}

	/**
	 * \brief indique si le perso a assez d'argent
	 * \param argent int le nombre de Pesos que le perso doit avoir pour faire qqch
	 * \return vrai l'argent du perso est superieur ou egale a la valeur en parametre
	 */
	bool Personnage::possedeAssezArgent(int argent){
		bool test = false;
		if(this->argent >= argent){
			test = true;
		}
		return test;
	}

	/**
	 * \brief getter d'argent
	 * \return argent int l'argent du perso
	 */
	int Personnage::getArgent(){
		return this->argent;
	}

	/**
	 * \brief getter de l'arme actuelle du perso
	 * \return armeEquiper Arme*
	 */
	Arme* Personnage::getArmeActuelle(){
		return this->armeEquiper;
	}

	/**
	 * \brief detecter une enter clavier
	 * \detail si l'entrer est \n elle ne fait rien sinon elle clear le std::cin
	 */
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
	
