/*
 * Race.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef RACE_HPP_
#define RACE_HPP_

#include <string>
#include <vector>

class Race{

private :
	std::string nomRace;
	std::vector<int> modificateurStatistique;
public :
	~Race();
	Race(std::string nR, std::vector<int> mS);
	std::vector<int> getmodificateurStatistique();
	std::string getmodificateurStatistiqueString();
	std::string getNomRace();
};

#endif /* RACE_HPP_ */
