/*
 * Item.hpp
 *
 *  Created on: 10 oct. 2014
 *      Author: Charles BEGAUDEAU
 */

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>

class Item {
protected:
	std::string nomItem;
public :
	Item(std::string nomItem);
	~Item();
	std::string getNomItem();
	virtual void doNothing() = 0;
};

#endif /* ITEM_HPP_ */
