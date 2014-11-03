/*
 * Technique.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef TECHNIQUE_HPP_
#define TECHNIQUE_HPP_

#include "string"

class Technique {
protected:
	std::string nomTechnique;
public:
	Technique(std::string nomT);
	std::string getNomTechnique();
};

class TechniqueStatistiqueUn : Technique {
private:

public:

};

class TechniqueStatistiqueDeux : Technique {
private:

public:

};

//PATTERNS STATE a implementer

class TechniqueActitivableAttaque : Technique {
private:

public:

};

//PATTERNS STATE a implementer

class TechniqueActitivableDefense : Technique {
private:

public:

};


#endif /* TECHNIQUE_HPP_ */
