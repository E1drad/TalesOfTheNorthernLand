/*
 * Technique.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef TECHNIQUE_HPP_
#define TECHNIQUE_HPP_

#include <string>

class Technique {
protected:
	std::string nomTechnique;
public:
	Technique(std::string nomT);
	std::string getNomTechnique();
	virtual ~Technique() = 0;
};

//un up de 15
class TechniqueStatistique : public Technique {
private:
	int statToUp;
public:
	TechniqueStatistique(std::string nomT, int s);
	~TechniqueStatistique();
	int getStatToUp();
};
/*
//PATTERNS STATE a implementer

class TechniqueActitivableAttaque : public Technique {
private:

public:

};

//PATTERNS STATE a implementer

class TechniqueActitivableDefense : public Technique {
private:

public:

};
*/

#endif /* TECHNIQUE_HPP_ */
