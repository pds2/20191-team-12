#include "Arma.h"
#include <string>
#include <iostream>

Arma::Arma(){
	this->id = 0;
	this->name = "No name";
	this->b_attack = 0;
	this->price = 0;
}

Arma::Arma(int _id, std::string _name, int _b_attack, int _price){
	this->id = _id;
	this->name = _name;
	this->b_attack = _b_attack;
	this->price = _price;
}

int Arma::get_id(){
	return this->id;
}

void Arma::set_id(int _id){
	this->id = _id;
}

int Arma::get_attack(){
	return this->b_attack;
}

void Arma::set_attack(int _attack){
	this->b_attack = _attack;
}

std::string Arma::get_name(){
	return this->name;
}

void Arma::set_name(std::string _name){
	this->name = _name;
}

int Arma::get_price(){
	return this->price;
}

void Arma::set_price(int _price){
	this->price = _price;
}


std::string Arma::adjust_square(std::string to_print, int num){
	to_print.append((num - to_print.size()), ' ');
	return to_print;
}

void Arma::display_weapon(){
	std::string to_print1 = "Id:" + std::to_string(this->id);
	std::string to_print2 = "Nome:" + this->name;
	std::string to_print3 = "Ataque:" + std::to_string(this->b_attack);
	std::string to_print4 = "Preco:" + std::to_string(this->price);

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


void Arma::equip(Arma toequip){
	set_id(toequip.get_id());
	set_name(toequip.get_name());
	set_attack(toequip.get_attack());
	set_price(toequip.get_price());
}

void Arma::unequip(){
	set_id(0);
	set_name("No weapon is being used.");
	set_attack(0);
	set_price(0);
}

	