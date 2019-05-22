#include "Pocao.h"
#include <iostream>

Pocao::Pocao(){
	this->i_stamina = 0;
	this->i_life = 0;
	this->quantity = 0;
}

Pocao::Pocao(int _stamina, int _life, int _quantity){
	this->i_stamina = _stamina;
	this->i_life = _life;
	this->quantity = _quantity;
}

int Pocao::get_life(){
	return this->i_life;
}

int Pocao::get_stamina(){
	return this->i_stamina;
}

int Pocao::get_quantity(){
	return this->quantity;
}

void Pocao::set_quantity(int num){
	this->quantity += num;
	std::cout << "Pot quantity updated" << std::endl;
}