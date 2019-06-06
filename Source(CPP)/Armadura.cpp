#include "Armadura.h"
#include <string>
#include <iostream>

Armadura::Armadura(){
	this->id = 0;
	this->name = "No name";
	this->b_defense = 0;
	this->price = 0;
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


std::string Armadura::adjust_square(std::string to_print, int num){
	to_print.append((num - to_print.size()), ' ');
	return to_print;
}

void Armadura::display_armor(){
	std::string to_print1 = "Id: " + std::to_string(this->id);
	std::string to_print2 = "Nome: " + this->name;
	std::string to_print3 = "Attack: " + std::to_string(this->b_defense);
	std::string to_print4 = "Price: " + std::to_string(this->price);

	to_print1 = adjust_square(to_print1, 35);
	to_print2 = adjust_square(to_print2, 35);
	to_print3 = adjust_square(to_print3, 35);
	to_print4 = adjust_square(to_print4, 35);


	std::cout << R"(+-----------------------------------+
|)" << to_print1 << R"(|
|)" << to_print2 << R"(|
|)" << to_print3 << R"(|
|)" << to_print4 << R"(|
+-----------------------------------+)" << std::endl;
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
