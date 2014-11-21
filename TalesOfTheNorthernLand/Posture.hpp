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
	std::string nomPosture;
public:
	Posture(std::string nomPosture);
	virtual ~Posture() = 0;
	virtual int attaquer(int degat);
	virtual int soigner(int soin);
	virtual int subirDegat(int degat);
	virtual int toucher(int toucher);
};

class Attaquant : public Posture {
private:
public:
	Attaquant();
	~Attaquant();
	int attaquer(int degat);

};
class Defenseur : public Posture {
private:
public:
	Defenseur();
	~Defenseur();
	int subirDegat(int degat);

};

class Soigneur : public Posture {
private:
public:
	Soigneur();
	~Soigneur();
	int soigner(int soin);
};

class Tacticien : public Posture {
private:
public:
	Tacticien();
	~Tacticien();
	int toucher(int toucher);
};

#endif /* POSTURE_HPP_ */
