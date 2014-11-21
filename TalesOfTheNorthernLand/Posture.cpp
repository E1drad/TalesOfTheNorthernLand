/*
 * Posture.cpp
 *
 *  Created on: 20 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Posture.hpp"
//class Posture {
	Posture::Posture(std::string nomPosture){
		this->nomPosture = nomPosture;
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
	Attaquant::Attaquant() : Posture::Posture("Attaquant"){
		std::cout << "Time for a real fight!" << std::endl;
	}

	Attaquant::~Attaquant(){

	}

	int Attaquant::attaquer(int degat){
		std::cout << " Non "<< ceil(1.25*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(1.25*degat);
	}

//class Defenseur : public Posture {
	Defenseur::Defenseur() : Posture::Posture("Defenseur"){
		std::cout << "Warrior goddess, I will stand guard over your legacy" << std::endl;
	}

	Defenseur::~Defenseur(){

	}

	int Defenseur::subirDegat(int degat){
		std::cout << " Non "<< floor(0.75*degat) << " degats !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return floor(0.75*degat);
	}

//class Soigneur : public Posture {

	Soigneur::Soigneur() : Posture::Posture("Soigneur"){
		std::cout << "Savior's got a job." << std::endl;
	}

	Soigneur::~Soigneur(){

	}
	int Soigneur::soigner(int soin){
		std::cout << " Non "<< ceil(1.25*soin) << " point de vie !" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(1.25*soin);
	}
//class Tacticien : public Posture {

	Tacticien::Tacticien(): Posture::Posture("Tacticien"){
		std::cout << "Did you really think you can beat me" << std::endl;
	}

	Tacticien::~Tacticien(){
	}

	int Tacticien::toucher(int toucher){
		std::cout << ". Non il feinte pour mieux contre-attaquer " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		return ceil(1.25*toucher);
	}
