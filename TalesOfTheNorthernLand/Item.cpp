/*
 * Item.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Item.hpp"

	/**
 	 *\brief Constructeur d'item (Classe abstraite)
 	 *	\param nomArme Le nom de l'item.
 	 */
	Item::Item(std::string nomItem){
		this->nomItem = nomItem;
	}

	/**
	 * \brief getter de nomItem
	 * \return std::string nom de l'item
	 */
	std::string Item::getNomItem(){
		return this->nomItem;
	}

	/**
	 *\brief Le destructeur de l'item.
	 */
	Item::~Item(){
		std::cout << "Item is being deleted" << std::endl;
	}
