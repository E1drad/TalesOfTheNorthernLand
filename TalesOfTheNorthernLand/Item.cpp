/*
 * Item.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Item.hpp"
	Item::Item(std::string nomItem){
		this->nomItem = nomItem;
	}

	std::string Item::getNomItem(){
		return this->nomItem;
	}

	Item::~Item(){

	}
