/*
 * Item.cpp
 *
 *  Created on: 29 sept. 2014
 *      Author: E123313L
 */

class Item {
protected:
	virtual String nomItem;
public :
	String Item::getNomItem();

};

class Arme : public Item {
private:
	int puissance;
	int precision;
	int critique;
public:


};

class Potion : public Item {
private :
	int valeur;
	int nombre;
	int statistique;
public :


};
