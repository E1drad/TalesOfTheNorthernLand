/*
 * Posture.hpp
 *
 *  Created on: 20 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef POSTURE_HPP_
#define POSTURE_HPP_

#include <string>
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

class Posture {
protected :
	int niveau;
	std::string nomPosture;
public:
	Posture(std::string nomPosture, int niveau);
	virtual ~Posture() = 0;
	virtual int attaquer(int degat);
	virtual int soigner(int soin);
	virtual int subirDegat(int degat);
	virtual int toucher(int toucher);
};

class Attaquant : public Posture {
private:
public:
	Attaquant(int niveau);
	~Attaquant();
	int attaquer(int degat);
	int subirDegat(int degat);
	int soigner(int soin);
	int toucher(int toucher);

};
class Defenseur : public Posture {
private:
public:
	Defenseur(int niveau);
	~Defenseur();
	int attaquer(int degat);
	int subirDegat(int degat);

};

class Soigneur : public Posture {
private:
public:
	Soigneur(int niveau);
	~Soigneur();
	int attaquer(int degat);
	int subirDegat(int degat);
	int soigner(int soin);
};

class Tacticien : public Posture {
private:
public:
	Tacticien(int niveau);
	~Tacticien();
	int attaquer(int degat);
	int toucher(int toucher);
};

#endif /* POSTURE_HPP_ */
