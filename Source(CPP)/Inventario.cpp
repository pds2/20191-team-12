#include <iostream>
//#include "Arma.h"
//#include "Armadura.h"
#include "Pocao.h"
#include "Inventario.h"

Inventario::Inventario(){ // Todos os números abaixo podem ser mudados para balancear o inicio de jogo*
	this->gold = 50; 
	this->stamina_pot = Pocao(50, 0, 1);
	this->life_pot = Pocao(0, 50, 1);
}

int Inventario::get_life(){
	return this->life_pot.get_life();
}

int Inventario::get_stamina(){
	return this->stamina_pot.get_stamina();
}

int Inventario::get_life_quantity(){
	return this->life_pot.get_quantity();
}

int Inventario::get_stamina_quantity(){
	return this->stamina_pot.get_quantity();
}

void Inventario::set_life_quantity(int num){
	this->life_pot.set_quantity(num);
}

void Inventario::set_stamina_quantity(int num){
	this->stamina_pot.set_quantity(num);
}

int Inventario::get_gold(){
	return this->gold;
}

void Inventario::set_gold(int _gold){
	this->gold += _gold;
}
