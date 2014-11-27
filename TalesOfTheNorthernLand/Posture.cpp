/*
 * Posture.cpp
 *
 *  Created on: 20 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Posture.hpp"
//class Posture {
	Posture::Posture(std::string nomPosture, int niveau){
		this->nomPosture = nomPosture;
		this->niveau = niveau;
	}

	Posture::~Posture(){

	}

	int Posture::attaquer(int degat){
		return degat;
	}

	int Posture::soigner(int soin){
		return soin;
	}

	int Posture::subirDegat(int degat){
		return degat;
	}

	int Posture::toucher(int toucher){
		return toucher;
	}

//class Attaquant : public Posture {
	Attaquant::Attaquant(int niveau) : Posture::Posture("Attaquant", niveau){
		std::cout << "Time for a real fight!" << std::endl;
	}

	Attaquant::~Attaquant(){

	}

	int Attaquant::attaquer(int degat){
		std::cout << "\tNon "<< ceil((1.25 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(1.25*degat);
	}

	int Attaquant::soigner(int soin){
		int newSoin = 0;
		newSoin = (soin > 0 ) ? ceil((0.75 + 0.05*this->niveau)*soin) :  floor((0.5 + 0.05*this->niveau)*soin);
		std::cout << "\tNon "<< newSoin << " point de vie !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return newSoin;
	}

	int Attaquant::subirDegat(int degat){
		std::cout << "\tNon "<< floor( (1.15 + 0.025*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return floor((1.15 + 0.025*this->niveau)*degat);
	}

	int Attaquant::toucher(int toucher){
		std::cout << "\tUn coup peu precis. " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil((0.85 + 0.05*this->niveau)*toucher);
	}

//class Defenseur : public Posture {
	Defenseur::Defenseur(int niveau) : Posture::Posture("Defenseur", niveau){
		std::cout << "Warrior goddess, I will stand guard over your legacy" << std::endl;
	}

	Defenseur::~Defenseur(){

	}

	int Defenseur::attaquer(int degat){
		std::cout << "\tNon "<< ceil((0.75 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(0.75*degat);
	}

	int Defenseur::subirDegat(int degat){
		std::cout << "\tNon "<< floor( (0.75 + 0.025*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return floor((0.75 + 0.025*this->niveau)*degat);
	}

//class Soigneur : public Posture {

	Soigneur::Soigneur(int niveau) : Posture::Posture("Soigneur", niveau){
		std::cout << "Savior's got a job." << std::endl;
	}

	Soigneur::~Soigneur(){

	}

	int Soigneur::attaquer(int degat){
		std::cout << "\tNon "<< ceil((0.75 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(0.75*degat);
	}

	int Soigneur::subirDegat(int degat){
		std::cout << "\tNon "<< floor( (1.15 + 0.025*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return floor((1.15 + 0.025*this->niveau)*degat);
	}

	int Soigneur::soigner(int soin){
		int newSoin = 0;
		newSoin = (soin > 0 ) ? ceil((1.25 + 0.05*this->niveau)*soin) :  abs((0.5 + 0.05*this->niveau)*soin);
		std::cout << "\tNon "<< newSoin << " point de vie !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return newSoin;
	}

//class Tacticien : public Posture {

	Tacticien::Tacticien(int niveau): Posture::Posture("Tacticien", niveau){
		std::cout << "Did you really think you can beat me" << std::endl;
	}

	Tacticien::~Tacticien(){

	}

	int Tacticien::attaquer(int degat){
		std::cout << "\tNon "<< ceil((0.85 + 0.05*this->niveau)*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(0.85*degat);
	}

	int Tacticien::toucher(int toucher){
		std::cout << "\tUn coup aussi rapide que la foudre. " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil((1.25 + 0.05*this->niveau)*toucher);
	}
