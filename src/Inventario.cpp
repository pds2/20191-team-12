#include <iostream>
#include "Arma.h"
#include "Armadura.h"
#include "Pocao.h"
#include "Inventario.h"
#include <vector>

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
	this->gold = _gold;
}

void Inventario::add_armor(Armadura A){
	Armadura tobeadded = A;
	this->unused_armor.push_back(tobeadded);
}

void Inventario::add_weapon(Arma A){
	Arma tobeadded = A;
	this->unused_weapons.push_back(tobeadded);
}

Armadura Inventario::get_x_armor(int num){
	//if(unused_armor.size() < num){
	return this->unused_armor[num];
	//}else{
	//	std::cout << "Failed acessing " << num << "position on armor inventory" << std::endl;
}

Arma Inventario::get_x_weapon(int num){
	return this->unused_weapons[num];
}

void Inventario::display_inventory(){
	int i;

	std::cout << "Armaduras: " << std::endl; 
	for(i = 0; i<unused_armor.size(); i++){
		this->unused_armor[i].display_armor();
	}
	std::cout << "Armas: " << std::endl;
	for(i = 0; i<unused_weapons.size(); i++){
		this->unused_weapons[i].display_weapon();
	}

	std::cout << "Pocoes de vida - Tamanho: " << this->life_pot.get_life() << " - Quantidade: " << this->get_life_quantity() << std::endl;
	std::cout << "Pocoes de stamina - Tamanho: " << this->stamina_pot.get_stamina() << " - Quantidade: " << this->get_stamina_quantity() << "\n" << std::endl;
}