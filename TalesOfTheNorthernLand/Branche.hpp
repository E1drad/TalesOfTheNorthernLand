/*
 * Branche.hpp
 *
 *  Created on: 18 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef BRANCHE_HPP_
#define BRANCHE_HPP_

#include <vector>
#include <string>

class Branche {
private :
	std::string nomBranche;
	std::vector<std::string> citations;
public :
	Branche(std::string nomBranche);
	~Branche();
	std::string getCitationAt(int i);
	std::vector<std::string> getCitations();
	std::string getNomBranche();
	void addCitation(std::string citation);
	void vectorAdd6String(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f);
};

#endif /* BRANCHE_HPP_ */
