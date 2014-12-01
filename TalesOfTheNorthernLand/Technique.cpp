/*
 * Technique.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: Charles BEGAUDEAU
 */
#include "Technique.hpp"

	/**
	 * \brief	Constructeur de Technique (classe abstaite)
	 * \param	nomT 	std::string le nom de la Technique
	 */
	Technique::Technique(std::string nomT){
		this->nomTechnique = nomT;
	}

	/**
	 * \brief	getter du  nom de la Technique
	 * \return	std::string le nom de la Technique
	 */
	std::string Technique::getNomTechnique(){
		return nomTechnique;
	}

	/**
	 * \brief	Destructeur de Technique
	 */
	Technique::~Technique(){
		std::cout << "Technique is being delete " << std::endl;
	}


/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

	/**
	 * \brief	Constructeur de TechniqueStatistique
	 * \param	nomT 	std::string le nom de la Technique
	 * \param	s		int	la stat a ameliorer
	 */
	TechniqueStatistique::TechniqueStatistique(std::string nomT, int s):Technique::Technique(nomT){
		this->statToUp = s;
	}

	/**
	 * \brief	Destructeur de TechniqueStatistique
	 */
	TechniqueStatistique::~TechniqueStatistique(){
		std::cout << "TechniqueStatistique is being delete " << std::endl;

	}

	/**
	 * \brief	getter de statToUp
	 * \return	int la stat a ameliorer
	 */
	int TechniqueStatistique::getStatToUp(){
		return this->statToUp;
	}

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/




/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

