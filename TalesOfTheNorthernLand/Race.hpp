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

	Race(std::string nR, std::vector<int> mS);
	std::vector<int> getmodificateurStatistique();
};

#endif /* RACE_HPP_ */
