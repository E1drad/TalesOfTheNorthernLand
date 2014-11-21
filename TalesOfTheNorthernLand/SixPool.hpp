/*
 * SixPool.hpp
 *
 *  Created on: 20 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef SIXPOOL_HPP_
#define SIXPOOL_HPP_

#include <string>
#include <vector>

class ObjetDePool {
private:
	std::string nom;
public:
	ObjetDePool(std::string nom);
	~ObjetDePool();
	std::string getNom();
};

class Pool {
private:
	std::vector<ObjetDePool> objectPool;
public:
	Pool();
	~Pool();
	bool addObjet(ObjetDePool objetDePool);
	bool removeObjet(ObjetDePool objetDePool);
	std::vector<ObjetDePool> getPool();
};

#endif /* SIXPOOL_HPP_ */
