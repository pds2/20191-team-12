#include "Arma.h"
#include <string>
#include <iostream>

Arma::Arma(){
	this->id = 0;
	this->name = "No name";
	this->b_attack = 10;
	this->price = 5;
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

void Arma::display_weapon(){
	std::cout << "    Id: " << get_id() << " - Name: " << get_name() << " - Attack: " << get_attack() << " - Price: " << get_price() << "\n\n";
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
