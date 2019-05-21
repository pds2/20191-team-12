#include <iostream>
//#include "Arma.h"
//#include "Armadura.h"
#include "Pocao.h"
#include "Inventario.h"

Inventario::Inventario(){
	this->gold = 0;
	this->stamina_pot = Pocao(50, 0, 1);
	this->life_pot = Pocao(0, 50, 1);
}

int Inventario::get_pot_life(Pocao *C){
	return C->get_i_life();
}

int Inventario::get_pot_stamina(Pocao *C){
	return C->get_i_stamina();
}

int Inventario::get_pot_quantity2(Pocao *C){
	return C->get_quantity();
}

void Inventario::set_pot_quantity2(Pocao *C, int num2){
	C->set_pot_quantity3(num2);
}

int Inventario::get_gold2(){
	return this->gold;
}

void Inventario::set_gold2(int _gold){
	this->gold = _gold;
}

Pocao* Inventario::get_life_pointer(){
	Pocao* life_pointer = &(this->life_pot);
	return life_pointer;
}

Pocao* Inventario::get_stamina_pointer(){
	Pocao* stamina_pointer = &(this->stamina_pot);
	return stamina_pointer;
}