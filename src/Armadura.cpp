#include "Armadura.h"
#include <string>
#include <iostream>
#include "FuncoesGerais.h"

Armadura::Armadura(){
	this->id = 0;
	this->name = "Sem armadura";
	this->b_defense = 0;
	this->price = 0;
}

Armadura::Armadura(int _id, std::string _name, int _b_defense, int _price){
	if(_id < 0){
		this->id = 0;
	} else{
		this->id = _id;
	}

	this->name = _name;
	if(_b_defense < 0){
		this->b_defense = 0;
	} else{
		this->b_defense = _b_defense;
	}

	if(_price < 0){
		this->price = 0;
	} else{
		this->price = _price;
	}
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
	std::string to_print1 = "Id: " + std::to_string(this->id);
	std::string to_print2 = "Nome: " + this->name;
	std::string to_print3 = "Defesa: " + std::to_string(this->b_defense);
	std::string to_print4 = "Preco: " + std::to_string(this->price);

	print_square(to_print1, to_print2, to_print3, to_print4);
}

void Armadura::equip(Armadura toequip){
	set_id(toequip.get_id());
	set_name(toequip.get_name());
	set_defense(toequip.get_defense());
	set_price(toequip.get_price());
}

void Armadura::unequip(){
	set_id(0);
	set_name("Sem armadura");
	set_defense(0);
	set_price(0);
}
