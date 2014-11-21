/*
 * Branche.cpp
 *
 *  Created on: 18 nov. 2014
 *      Author: Charles BEGAUDEAU
 */

#include "Branche.hpp"

	Branche::Branche(std::string nomBranche){
		this->nomBranche = nomBranche;
		this->citations.empty();
	}

	Branche::~Branche(){

	}

	std::string Branche::getCitationAt(int i){
		return this->citations.at(i);
	}

	std::vector<std::string> Branche::getCitations(){
		return this->citations;
	}

	std::string Branche::getNomBranche(){
		return this->nomBranche;
	}

	void Branche::addCitation(std::string citation){
		this->citations.push_back(citation);
	}

	void Branche::vectorAdd6String(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f){
		this->citations.push_back(a);  this->citations.push_back(b);  this->citations.push_back(c);
		this->citations.push_back(d);  this->citations.push_back(e);  this->citations.push_back(f);
	}
