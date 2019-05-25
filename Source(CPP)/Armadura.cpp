#include "Armadura.h"
#include <string>
#include <iostream>

Armadura::Armadura(){
	this->id = 0;
	this->name = "No name";
	this->b_defense = 10;
	this->price = 5;
}

Armadura::Armadura(int _id, std::string _name, int _b_defense, int _price){
	this->id = _id;
	this->name = _name;
	this->b_defense = _b_defense; 
	this->price = _price;
} 

int Armadura::get_id(){
	return this->id;
}

void Armadura::set_id(int _id){
	this->id = _id;
}

int Armadura::get_defense(){
	return this->b_defense;
}

void Armadura::set_defense(int _defense){
	this->b_defense = _defense;
}

std::string Armadura::get_name(){
	return this->name;
}

void Armadura::set_name(std::string _name){
	this->name = _name;
}

int Armadura::get_price(){
	return this->price;
}

void Armadura::set_price(int _price){
	this->price = _price;
}

void Armadura::display_armor(){
	std::cout << "    Id: " << get_id() << " - Name: " << get_name() << " - Defense: " << get_defense() << " - Price: " << get_price() << "\n\n";
}

void Armadura::equip(Armadura toequip){
	set_id(toequip.get_id());
	set_name(toequip.get_name());
	set_defense(toequip.get_defense());
	set_price(toequip.get_price());
}

void Armadura::unequip(){
	set_id(0);
	set_name("No armor is being used");
	set_defense(0);
	set_price(0);
}