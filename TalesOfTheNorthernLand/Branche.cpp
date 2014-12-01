/*
 * Branche.cpp
 *
 *  Created on: 18 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Branche.hpp"

	/**
	 * \brief Constructeur de Branche
	 * \param nomBranche string le nom de la branche
	 */
	Branche::Branche(std::string nomBranche){
		this->nomBranche = nomBranche;
		this->citations.empty();
	}

	/**
	 * \brief Destructeur de Branche
	 */
	Branche::~Branche(){

	}

	/**
	 * \brief donne une citation de la branche
	 * \param i int le numero de la citation
	 * \return citation \e string une citation de la branche
	 */
	std::string Branche::getCitationAt(int i){
		return this->citations.at(i);
	}
	/**
	 * \brief getter du vector de citation de la branche
	 * \return citation \e vector<std::string>
	 */
	std::vector<std::string> Branche::getCitations(){
		return this->citations;
	}
	/**
	 * \brief getter du nom de la branche
	 * \return nomBranche \e std::string
	 */
	std::string Branche::getNomBranche(){
		return this->nomBranche;
	}

	/**
	 * \brief donne une citation de la branche
	 * \param i int le numero de la citation
	 * \return citation \e string une citation de la branche
	 */
	void Branche::addCitation(std::string citation){
		this->citations.push_back(citation);
	}

	/**
	 * \brief ajoute six strings au vector de citation de la branche
	 * \param a std::string une des six strings ajouter (1er)
	 * \param b std::string une des six strings ajouter (2eme)
	 * \param c std::string une des six strings ajouter (3eme)
	 * \param d std::string une des six strings ajouter (4eme)
	 * \param e std::string une des six strings ajouter (5eme)
	 * \param f std::string une des six strings ajouter (6eme)
	 * \return citation \e string une citation de la branche
	 */
	void Branche::vectorAdd6String(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f){
		this->citations.push_back(a);  this->citations.push_back(b);  this->citations.push_back(c);
		this->citations.push_back(d);  this->citations.push_back(e);  this->citations.push_back(f);
	}
