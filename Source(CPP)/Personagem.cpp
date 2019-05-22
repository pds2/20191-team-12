#include "Pocao.h"
#include "Inventario.h"
#include "Personagem.h"

//#include "Arma.h"
//#include "Armadura.h"
#include <iostream>

// CONSTRUTOR

Personagem::Personagem(std::string _obj_name, int _life, int _deffense, int _attack, int _stamina){
	this->object_name = _obj_name;
	this->life = _life;
	this->deffense = _deffense;
	this->attack = _attack;
	this->stamina = _stamina;
	
	Inventario _inventory = Inventario();
	inventory = _inventory;

}

// ACESSO E MUDANÇA DE ATRIBUTOS GERAIS

std::string Personagem::get_object_name(){
	return this->object_name;
}

void Personagem::set_object_name(std::string name_change){
	this->object_name = name_change;
	std::cout << "Name updated" << std::endl;
}

int Personagem::get_life(){
	return this->life;
}

void Personagem::set_life(int life_change){
	if(this->life + life_change <= 0){
		std::cout << "Your character died." << std::endl;
		// call fim de jogo...
	} else{
		this->life += life_change;
		std::cout << "Life updated" << std::endl;
	}
}

int Personagem::get_deffense(){
	return this->deffense;
}

void Personagem::set_deffense(int def_change){
	this->deffense += def_change;
	std::cout << "Deffense updated" << std::endl;
}

int Personagem::get_attack(){
	return this->attack;
}

void Personagem::set_attack(int attack_change){
	this->attack += attack_change;
	std::cout << "Attack updated" << std::endl;
}

int Personagem::get_stamina(){
	return this->stamina;
}

void Personagem::set_stamina(int stamina_change){
	this->stamina += stamina_change;
	std::cout << "Stamina updated" << std::endl;
}

void Personagem::use_life_potion(){
	if(this->inventory.get_life_quantity() < 1){
		std::cout << "There is no potion to be used." << std::endl;
	} else{
		this->set_life(this->inventory.get_life());
		this->inventory.set_life_quantity(-1);
	}
}

void Personagem::use_stamina_potion(){
	if(this->inventory.get_stamina_quantity() < 1){
		std::cout << "There is no potion to be used." << std::endl;
	} else{
		this->set_stamina(this->inventory.get_stamina());
		this->inventory.set_stamina_quantity(-1);
	}
}

int Personagem::get_life_pot_quantity(){
	return this->inventory.get_life_quantity();
}

int Personagem::get_stamina_pot_quantity(){
	return this->inventory.get_stamina_quantity();
}

void Personagem::set_life_pot_quantity(int num){
	if(this->inventory.get_life_quantity() + num < 0){
		std::cout << "Character cannot have a negative quantity of potions" << std::endl;
	} else{
		this->inventory.set_life_quantity(num);
	}
}

void Personagem::set_stamina_pot_quantity(int num){
	if(this->inventory.get_stamina_quantity() + num < 0){
		std::cout << "Character cannot have a negative quantity of potions" << std::endl;
	} else{
		this->inventory.set_stamina_quantity(num);
	}
}

int Personagem::get_gold(){
	return this->inventory.get_gold();
}

void Personagem::set_gold(int num){
	this->inventory.set_gold(num);
}

/*

void Personagem::equip_armor(Armadura toequip){
	B->equip();
}

void Personagem::unequip_armor(){
	B->unequip();
}

void Personagem::equip_weapon(Arma toequip){
	B->equip(toequip);
}

void Personagem::unequip_weapon(){
	B->unequip();
}

void apply_armor_stats(){
	
}

void apply_weapon_stats(){

}

*/ 


