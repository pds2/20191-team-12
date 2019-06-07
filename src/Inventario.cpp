#include <iostream>
#include "Arma.h"
#include "Armadura.h"
#include "Pocao.h"
#include "Inventario.h"
#include <vector>

Inventario::Inventario(){ // Todos os números abaixo podem ser mudados para balancear o inicio de jogo*
	this->gold = 50; 
	this->stamina_pot = Pocao(50, 0, 2);
	this->life_pot = Pocao(0, 50, 2);
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

int Inventario::armor_inventory_position(int id){
	int armor_position = -1, i;
	auto it = this->unused_armor.begin();
	for(it, i = 0; it != this->unused_armor.end(); ++it, ++i){
		if(id = it->get_id()){
			armor_position = i;
		}
	}
	return armor_position;
}

int Inventario::weapon_inventory_position(int id){ // Se a posicao for igual a -1, a arma nao existe no inventario
	int weapon_position = -1, i;
	auto it = this->unused_weapons.begin();
	for(it, i = 0; it != this->unused_weapons.end(); ++it, ++i){
		if(id = it->get_id()){
			weapon_position = i;
		}
	}
	return weapon_position;
}


void Inventario::remove_armor(int id){
	if(armor_inventory_position(id) >= 0){
		this->unused_armor.erase(unused_armor.begin() + armor_inventory_position(id));
	} else{
		std::cout << "Remocao de armadura falhou" << std::endl;
	}
}

void Inventario::remove_weapon(int id){
	std::cout << "Teste" ;
	if(weapon_inventory_position(id) >= 0){
		this->unused_weapons.erase(unused_weapons.begin() + weapon_inventory_position(id));
	} else{
		std::cout << "Remocao de arma falhou" << std::endl;
	}

}

std::vector<Armadura> Inventario::get_full_unused_armor(){
	return this->unused_armor;
}

std::vector<Arma> Inventario::get_full_unused_weapon(){
	return this->unused_weapons;
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