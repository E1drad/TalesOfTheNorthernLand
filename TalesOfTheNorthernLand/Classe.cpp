/*
 * Classe.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Classe.hpp"
#include "Personnage.hpp"

	std::random_device rd3;
	std::mt19937 rng3(rd3());
	std::random_device rd2;
	std::mt19937 rng2(rd2());
//class Classe

	/**
	 * \brief	Constructeur de Classe (classe abstaite)
	 * \param	nC 		std::string le nom de la classe
	 * \param	mS 		std::vector<int> les modificateurs de la classe
	 * \param	b 		Branche* sa branche
	 */
	Classe::Classe(std::string nC, std::vector<int> mS, Branche* b){
		this->nomClasse = nC;
		this->modificateurStatistique = mS;
		this->branche = b;
	}

	/**
	 * \brief	getter de modificateurStatistique
	 * \return 	modificateurStatistique	std::vector<int> le vector de stat
	 */
	std::vector<int> Classe::getmodificateurStatistique(){
		return this->modificateurStatistique;
	}


	/**
	 * \brief	Destructeur de Classe
	 */
	Classe::~Classe(){
		std::cout << "Classe is being deleted" << std::endl;
		this->branche = nullptr;
		delete this->branche;
	}

	/**
	 * \brief	getter du nom de la classe
	 * \return 	modificateurStatistique	std::string le nom de la classe
	 */
	std::string Classe::getNomClasse(){
		return this->nomClasse;
	}

	/**
	 * \brief	getter de la branche
	 * \return  branche Branche* la branche de la classe
	 */
	Branche* Classe::getBranche(){
		return this->branche;
	}

	/**
	 * \brief	retour le vector sous la forme d'une string
	 * \return vector std::string
	 */
	std::string Classe::getmodificateurStatistiqueString(){
		std::string s;
		s = "";
		for(unsigned int i = 0; i < this->modificateurStatistique.size(); ++i ){
			s = s + " " + std::to_string(this->modificateurStatistique.at(i));
		}
		return s;
	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseHeroique


	/**
	 * \brief	Constructeur de ClasseHeroique herite de Classe
	 * \param	nC 		std::string le nom de la classe
	 * \param	mS 		std::vector<int> les modificateurs de la classe
	 * \param	b 		Branche* sa branche
	 * \param	t1 		Technique* technique 1
	 * \param	t2 		Technique* technique 2
	 * \param	nT1 	int niveau technique 1
	 * \param	nT2		int niveau technique 2
	 */
	ClasseHeroique::ClasseHeroique(std::string nc, std::vector<int> ms, Branche* b, Technique* t1, Technique* t2, int nT1, int nT2):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->technique2 = t2;
		this->niveauTechnique1 = nT1;
		this->niveauTechnique2 = nT2;
	}

	/**
	 * \brief	getter de la 1er technique
	 * \return technique *Technique la 1er technique
	 */
	Technique* ClasseHeroique::getTechnique1() {
		return this->technique1;
	}

	/**
	 * \brief	getter de la 2eme technique
	 * \return technique *Technique la 2eme technique
	 */
	Technique* ClasseHeroique::getTechnique2() {
		return this->technique2;
	}

	/**
	 * \brief	getter du niveau pour la 1er technique
	 * \return technique *Technique la 1er technique
	 */
	int ClasseHeroique::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	/**
	 * \brief	getter du niveau pour la 2em technique
	 * \return technique *Technique la 2eme technique
	 */
	int ClasseHeroique::getniveauTechnique2() {
		return this->niveauTechnique2;
	}


	/**
	 * \brief	Destructeur de ClasseHeroique
	 */
	ClasseHeroique::~ClasseHeroique(){
		std::cout << "ClasseHeroique is being deleted" << std::endl;
		this->technique1 = nullptr;
		this->technique2 = nullptr;
		delete this->technique1;
		delete this->technique2;
	}


	/**
	 * \brief	methode d'attaque (change en fonction de la classe)
	 * \param	degat 	int degat
	 * \param	statAttaque 	int  force ou intelligence
	 */
	int ClasseHeroique::attaquer(int degat, int statAttaque){
		int jetDe;
		jetDe = (rng2() % 2);
		if(jetDe == 1){
			std::cout << "Un coup de champion !" << std::endl;
			degat = ceil(degat * 1.10);
		}else if(jetDe <= floor(statAttaque/3) ) {
			std::cout << "Un coup prodigieux !" << std::endl;
			degat = ceil(degat * 1.05);
		}
		std::cout << this->branche->getCitationAt(jetDe) << std::endl;
		return degat;
	}


	/**
	 * \brief	determine si le perso peux regagner miraculeusement des pv(change en fonction de la classe)
	 * \param	statChance 	int chance du personnage
	 * \param	pvMax 	int  les pvMax du personnage
	 */
	int ClasseHeroique::mort(int statChance, int pvMax){
		int jetDe;
		int regain = 0;
		jetDe = (rng3() % 100) + 1;
		std::cout << " Regain ? " << jetDe << std::endl;
		if(jetDe == 1){
			regain = ceil(pvMax * 0.10);
		}else if(jetDe <= ceil(statChance/5) ) {
			regain = ceil(pvMax * 0.05);
		}
		return regain;
	}

	/**
	 * \brief methode de "transition vers le haut"
	 * \param	p 	Personnage* le perso promu
	 * \param	c 	Classe*  la nouvelle classe du perso (doit être Parangon)
	 * \return bool true si classe Parangon sinon false
	 */
	bool ClasseHeroique::promotion(Personnage *p, Classe* c){
		bool t = false;
		if(typeid(*c) == typeid(ClasseParangon)){
			p->setClasseParangon(c);
			p->setClasseActuelle(p->getClasseParangon());
			t = true;
		}
		return t;
	}

	/**
	 * \brief methode de "transition vers le bas"
	 * \param	p 	Personnage* le perso dechut
	 * ne doit pas être utiliser
	 */
	void ClasseHeroique::decheance(Personnage* p){
		std::cout << "LOLWUT ? I know someone who will be find dead S00N !" << std::endl;//ne doit pas être utiliser
		//ne doit pas être utiliser
	}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseParagon

	/**
	 * \brief	Constructeur de ClasseParangon herite de Classe
	 * \param	nC 		std::string le nom de la classe
	 * \param	mS 		std::vector<int> les modificateurs de la classe
	 * \param	b 		Branche* sa branche
	 * \param	t1 		Technique* technique 1
	 * \param	t2 		Technique* technique 2
	 * \param	nT1 	int niveau technique 1
	 * \param	nT2		int niveau technique 2
	 */
	ClasseParangon::ClasseParangon(std::string nc, std::vector<int> ms, Branche* b, Technique* t1, Technique* t2, int nT1, int nT2):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->technique2 = t2;
		this->niveauTechnique1 = nT1;
		this->niveauTechnique2 = nT2;
	}

	/**
	 * \brief	getter de la 1er technique
	 * \return technique *Technique la 1er technique
	 */
	Technique* ClasseParangon::getTechnique1() {
		return this->technique1;
	}

	/**
	 * \brief	getter de la 2eme technique
	 * \return technique *Technique la 2eme technique
	 */
	Technique* ClasseParangon::getTechnique2() {
		return this->technique2;
	}

	/**
	 * \brief	getter du niveau pour la 1er technique
	 * \return technique *Technique la 1er technique
	 */
	int ClasseParangon::getniveauTechnique1() {
		return this->niveauTechnique1;
	}

	/**
	 * \brief	getter du niveau pour la 2em technique
	 * \return technique *Technique la 2eme technique
	 */
	int ClasseParangon::getniveauTechnique2() {
		return this->niveauTechnique2;
	}


	/**
	 * \brief	Destructeur de ClasseParangon
	 */
	ClasseParangon::~ClasseParangon(){
		std::cout << "ClasseParangon is being deleted" << std::endl;
		this->technique1 = nullptr;
		this->technique2 = nullptr;
		delete this->technique1;
		delete this->technique2;
	}

	/**
	 * \brief	methode d'attaque (change en fonction de la classe)
	 * \param	degat 	int degat
	 * \param	statAttaque 	int  force ou intelligence
		 */
	int ClasseParangon::attaquer(int degat, int statAttaque){
		int jetDe;
		jetDe = (rng3() % 100) + 1;
		if(jetDe == 1){
			std::cout << "Un coup de maitre !" << std::endl;
			degat = ceil(degat * 1.25);
		}else if(jetDe <= floor(statAttaque/3) ) {
			std::cout << "Un coup de genie !" << std::endl;
			degat = ceil(degat * 1.10);
		}
		jetDe = (rng2() % 2) + 2;
		std::cout << this->branche->getCitationAt(jetDe) << std::endl;
		return degat;

	}

	/**
	 * \brief	determine si le perso peux regagner miraculeusement des pv(change en fonction de la classe)
	 * \param	statChance 	int chance du personnage
	 * \param	pvMax 	int  les pvMax du personnage
	 */
	int ClasseParangon::mort(int statChance, int pvMax){
		int jetDe;
		int regain = 0;
		jetDe = (rng3() % 100) + 1;
		std::cout << " Regain ? " << jetDe << std::endl;
		if(jetDe == 1){
			regain = ceil(pvMax * 0.25);
		}else if(jetDe <= ceil(statChance/4) ) {
			regain = ceil(pvMax * 0.15);
		}
		return regain;
	}

	/**
	 * \brief methode de "transition vers le haut"
	 * \param	p 	Personnage* le perso promu
	 * \param	c 	Classe*  la nouvelle classe du perso (doit être Divine)
	 * \return bool true si classe divine sinon false
	 */
	bool ClasseParangon::promotion(Personnage* p, Classe* c){
		bool t = false;
		if(typeid(*c) == typeid(ClasseDivine)){
			p->setClasseDivine(c);
			p->setClasseActuelle(p->getClasseDivine());
			t = true;
		}
		return t;
	}

	/**
	 * \brief methode de "transition vers le bas"
	 * \param	p 	Personnage* le perso dechut
	 */
	void ClasseParangon::decheance(Personnage* p){
		p->setClasseActuelle(p->getClasseHeroique());
	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
//class ClasseDivine

	/**
	 * \brief	Constructeur de ClasseDivine herite de Classe
	 * \param	nC 		std::string le nom de la classe
	 * \param	mS 		std::vector<int> les modificateurs de la classe
	 * \param	b 		Branche* sa branche
	 * \param	t1 		Technique* technique 1
	 * \param	nT1 	int niveau technique 1
	 */
	ClasseDivine::ClasseDivine(std::string nc, std::vector<int> ms, Branche* b, Technique* t1, int nT1):Classe::Classe(nc,ms,b){
		this->technique1 = t1;
		this->niveauTechnique1 = nT1;
	}


	/**
	 * \brief	getter de la 1er technique
	 * \return technique *Technique la 1er technique
	 */
	Technique* ClasseDivine::getTechnique1() {
		return this->technique1;
	}

	/**
	 * \brief	getter du niveau pour la 1er technique
	 * \return technique *Technique la 1er technique
	 */
	int ClasseDivine::getniveauTechnique1() {
		return this->niveauTechnique1;
	}


	/**
	 * \brief	Destructeur de ClasseDivine
	 */
	ClasseDivine::~ClasseDivine(){
		std::cout << "ClasseDivine is being deleted" << std::endl;
		this->technique1 = nullptr;
		delete this->technique1;
	}


	/**
	 * \brief	methode d'attaque (change en fonction de la classe)
	 * \param	degat 	int degat
	 * \param	statAttaque 	int  force ou intelligence
	 */
	int ClasseDivine::attaquer(int degat, int statAttaque){
		int jetDe;
		jetDe = (rng3() % 100) + 1;
		if(jetDe == 1){
			std::cout << "Un coup de divin !" << std::endl;
			degat = ceil(degat * 1.75);
		}else if(jetDe <= floor(statAttaque/2) ) {
			std::cout << "Un coup de digne d'un dieu !" << std::endl;
			degat = ceil(degat * 1.25);
		}
		jetDe = (rng2() % 2) + 4;
		std::cout << this->branche->getCitationAt(jetDe) << std::endl;
		return degat;

	}

	/**
	 * \brief	determine si le perso peux regagner miraculeusement des pv(change en fonction de la classe)
	 * \param	statChance 	int chance du personnage
	 * \param	pvMax 	int  les pvMax du personnage
	 */
	int ClasseDivine::mort(int statChance, int pvMax){
		int jetDe;
		int regain = 0;
		jetDe = (rng3() % 100) + 1;
		std::cout << " Regain ? " << jetDe << std::endl;
		if(jetDe == 1){
			regain = ceil(pvMax * 0.25);
		}else if(jetDe <= ceil(statChance/3) ) {
			regain = ceil(pvMax * 0.15);
		}
		return regain;
	}


	/**
	 * \brief methode de "transition vers le haut" en Divin elle retour TOUJOURS faux
	 * \param	p 	Personnage* le perso promu
	 * \param	c 	Classe*  la nouvelle classe du perso
	 * \return bool false resultat constant
	 */
	bool ClasseDivine::promotion(Personnage* p, Classe* c){
		//ne doit pas être utiliser
		return false;
	}

	/**
	 * \brief methode de "transition vers le bas"
	 * \param	p 	Personnage* le perso dechut
	 */
	void ClasseDivine::decheance(Personnage* p){
		p->setClasseActuelle(p->getClasseParangon());
	}
