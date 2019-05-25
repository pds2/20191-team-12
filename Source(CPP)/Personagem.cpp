#include "Pocao.h"
#include "Inventario.h"
#include "Personagem.h"
#include "Arma.h"
#include "Armadura.h"

#include <iostream>
#include <string>


// CONSTRUTOR

Personagem::Personagem(std::string _obj_name, std::string _casa, int _life, int _defense, int _attack, int _stamina, Armadura _armor, Arma _weapon){
	this->object_name = _obj_name;
	this->casa = _casa;
	this->life = _life;
	this->defense = _defense;
	this->attack = _attack;
	this->stamina = _stamina;
	
	Inventario _inventory = Inventario();
	this->inventory = _inventory;

	this->armor = _armor;

	equip_armor(_armor);
	equip_weapon(_weapon);
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

int Personagem::get_defense(){
	return this->defense;
}

void Personagem::set_defense(int def_change){
	this->defense += def_change;
	std::cout << "Defense updated" << std::endl;
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

void Personagem::equip_armor(Armadura toequip){
	unequip_armor();
	this->armor.equip(toequip);
	set_defense(this->armor.get_defense());
}

void Personagem::unequip_armor(){
	set_defense((-1) * this->armor.get_defense());
	this->inventory.add_armor(this->armor);
	this->armor.unequip();
}

void Personagem::equip_weapon(Arma toequip){ // Ainda precisa fazer checagem de inventário ou direto da loja!!!
	unequip_weapon();
	this->weapon.equip(toequip);
	set_attack(this->weapon.get_attack());
}

void Personagem::unequip_weapon(){
	set_attack((-1) * this->weapon.get_attack());
	this->inventory.add_weapon(this->weapon);
	this->weapon.unequip();
}

std::string Personagem::get_armor_name(){
	return this->armor.get_name();
}

int Personagem::get_armor_defense(){
	return this->armor.get_defense();
}

int Personagem::get_armor_id(){
	return this->armor.get_id();
}

int Personagem::get_armor_price(){
	return this->armor.get_price();
}

std::string Personagem::get_weapon_name(){
	return this->weapon.get_name();
}

int Personagem::get_weapon_attack(){
	return this->weapon.get_attack();
}

int Personagem::get_weapon_id(){
	return this->weapon.get_id();
}

int Personagem::get_weapon_price(){
	return this->weapon.get_price();
}

void Personagem::display_inventory(){
	std::cout << "**Your itens**:" << std::endl;
	this->inventory.display_inventory();
}

void Personagem::add_armor(Armadura A){
	this->inventory.add_armor(A);
}

void Personagem::add_weapon(Arma A){
	this->inventory.add_weapon(A);
}