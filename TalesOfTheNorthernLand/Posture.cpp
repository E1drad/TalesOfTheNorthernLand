/*
 * Posture.cpp
 *
 *  Created on: 20 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Posture.hpp"
//class Posture {
	/**
	 * \brief	Constructeur de Posture (classe abstaite)
	 * \param	nC 		std::string le nom de la Posture
	 * \param	niveau  int le niveau de la posture
	 */
	Posture::Posture(std::string nomPosture, int niveau){
		this->nomPosture = nomPosture;
		this->niveau = niveau;
	}
	/**
	 * \brief	Destructeur de Posture
	 */
	Posture::~Posture(){

	}
	/**
	 * \brief	comportement de base d'attaque
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Posture::attaquer(int degat){
		return degat;
	}
	/**
	 * \brief	comportement de base de soigner
	 * \param	soin 	int le nombre de pv soigner de base
	 * \return  int 	les le nombre de pv soigner
	 */
	int Posture::soigner(int soin){
		return soin;
	}
	/**
	 * \brief	comportement de base de subirDegat
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Posture::subirDegat(int degat){
		return degat;
	}
	/**
	 * \brief	comportement de base de toucher
	 * \param	degat 	int le pourcentage de chance toucher de base
	 * \return  int 	les le pourcentage de chance toucher de base
	 */
	int Posture::toucher(int toucher){
		return toucher;
	}

//class Attaquant : public Posture {
	/**
	 * \brief	Constructeur de Attaquant herite de Posture
	 * \param	niveau  int le niveau de la posture
	 */
	Attaquant::Attaquant(int niveau) : Posture::Posture("Attaquant", niveau){
		std::cout << "Time for a real fight!" << std::endl;
	}
	/**
	 * \brief	Destructeur de Attaquant
	 */
	Attaquant::~Attaquant(){

	}
	/**
	 * \brief	comportement de base d'attaque d'Attaquant
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Attaquant::attaquer(int degat){
		std::cout << "\tNon "<< ceil((1.25 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(1.25*degat);
	}
	/**
	 * \brief	comportement de se soigner en Attaquant
	 * \param	soin 	int le nombre de pv soigner de base
	 * \return  int 	les le nombre de pv soigner
	 */
	int Attaquant::soigner(int soin){
		int newSoin = 0;
		newSoin = (soin > 0 ) ? ceil((0.75 + 0.05*this->niveau)*soin) :  floor((0.5 + 0.05*this->niveau)*soin);
		std::cout << "\tNon "<< newSoin << " point de vie !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return newSoin;
	}
	/**
	 * \brief	comportement de subirDegat en Attaquant
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Attaquant::subirDegat(int degat){
		std::cout << "\tNon "<< floor( (1.15 + 0.025*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return floor((1.15 + 0.025*this->niveau)*degat);
	}
	/**
	 * \brief	comportement de toucher en Attaquant
	 * \param	degat 	int le pourcentage de chance toucher de base
	 * \return  int 	les le pourcentage de chance toucher de base
	 */
	int Attaquant::toucher(int toucher){
		std::cout << "\tUn coup peu precis. " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil((0.85 + 0.05*this->niveau)*toucher);
	}

//class Defenseur : public Posture {
	/**
	 * \brief	Constructeur de Defenseur herite de Posture
	 * \param	niveau  int le niveau de la posture
	 */
	Defenseur::Defenseur(int niveau) : Posture::Posture("Defenseur", niveau){
		std::cout << "Warrior goddess, I will stand guard over your legacy" << std::endl;
	}
	/**
	 * \brief	Destructeur de Defenseur
	 */
	Defenseur::~Defenseur(){

	}
	/**
	 * \brief	comportement d'attaque de Defenseur
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Defenseur::attaquer(int degat){
		std::cout << "\tNon "<< ceil((0.75 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(0.75*degat);
	}
	/**
	 * \brief	comportement de subirDegat en Defenseur
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Defenseur::subirDegat(int degat){
		std::cout << "\tNon "<< floor( (0.75 + 0.025*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return floor((0.75 + 0.025*this->niveau)*degat);
	}

//class Soigneur : public Posture {
	/**
	 * \brief	Constructeur de Soigneur herite de Posture
	 * \param	niveau  int le niveau de la posture
	 */
	Soigneur::Soigneur(int niveau) : Posture::Posture("Soigneur", niveau){
		std::cout << "Savior's got a job." << std::endl;
	}
	/**
	 * \brief	Destructeur de Soigneur
	 */
	Soigneur::~Soigneur(){

	}
	/**
	 * \brief	comportement  d'attaque de Soigneur
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Soigneur::attaquer(int degat){
		std::cout << "\tNon "<< ceil((0.75 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(0.75*degat);
	}
	/**
	 * \brief	comportement de subirDegat en Soigneur
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Soigneur::subirDegat(int degat){
		std::cout << "\tNon "<< floor( (1.15 + 0.025*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return floor((1.15 + 0.025*this->niveau)*degat);
	}

	/**
	 * \brief	comportement de se soigner en Soigneur
	 * \param	soin 	int le nombre de pv soigner de base
	 * \return  int 	les le nombre de pv soigner
	 */
	int Soigneur::soigner(int soin){
		int newSoin = 0;
		newSoin = (soin > 0 ) ? ceil((1.25 + 0.05*this->niveau)*soin) :  abs((0.5 + 0.05*this->niveau)*soin);
		std::cout << "\tNon "<< newSoin << " point de vie !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return newSoin;
	}

//class Tacticien : public Posture {
	/**
	 * \brief	Constructeur de Tacticien herite de Posture
	 * \param	niveau  int le niveau de la posture
	 */
	Tacticien::Tacticien(int niveau): Posture::Posture("Tacticien", niveau){
		std::cout << "Did you really think you can beat me" << std::endl;
	}
	/**
	 * \brief	Destructeur de Tacticien
	 */
	Tacticien::~Tacticien(){

	}
	/**
	 * \brief	comportement d'attaque de Tacticien
	 * \param	degat 	int les degats de base
	 * \return  int 	les degats
	 */
	int Tacticien::attaquer(int degat){
		std::cout << "\tNon "<< ceil((0.85 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(0.85*degat);
	}
	/**
	 * \brief	comportement de toucher en Tacticien
	 * \param	degat 	int le pourcentage de chance toucher de base
	 * \return  int 	les le pourcentage de chance toucher de base
	 */
	int Tacticien::toucher(int toucher){
		std::cout << "\tUn coup aussi rapide que la foudre. " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil((1.25 + 0.05*this->niveau)*toucher);
	}
