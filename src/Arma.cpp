#include "Arma.h"
#include <string>
#include <iostream>
#include "FuncoesGerais.h"

Arma::Arma(){
	this->id = 0;
	this->name = "Sem arma";
	this->b_attack = 0;
	this->price = 0;
}

Arma::Arma(int _id, std::string _name, int _b_attack, int _price){
	if(_id < 0){
		this->id = 0;
	} else{
		this->id = _id;
	}

	this->name = _name;
	if(_b_attack < 0){
		this->b_attack = 0;
	} else{
		this->b_attack = _b_attack;
	}

	if(_price < 0){
		this->price = 0;
	} else{
		this->price = _price;
	}
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
	std::string to_print1 = "Id:" + std::to_string(this->id);
	std::string to_print2 = "Nome:" + this->name;
	std::string to_print3 = "Ataque:" + std::to_string(this->b_attack);
	std::string to_print4 = "Preco:" + std::to_string(this->price);

	print_square(to_print1, to_print2, to_print3, to_print4);
}

void Arma::equip(Arma toequip){
	set_id(toequip.get_id());
	set_name(toequip.get_name());
	set_attack(toequip.get_attack());
	set_price(toequip.get_price());
}

void Arma::unequip(){
	set_id(0);
	set_name("Sem arma");
	set_attack(0);
	set_price(0);
}

	