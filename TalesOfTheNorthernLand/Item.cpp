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
	Item::~Item(){}
	std::string Item::getNomItem(){
		return this->nomItem;
	}


