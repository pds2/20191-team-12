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
	this->life += life_change;
	std::cout << "Life updated" << std::endl;
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

// ACESSO E MUDANÇA DE ATRIBUTOS INTERNOS

Inventario* Personagem::git(){ // get_inventory_pointer();
	Inventario* inventory_pointer = &(this->inventory);
	return inventory_pointer;
}

void Personagem::use_life_potion(Inventario *B){
	Personagem::set_life(B->get_pot_life(B->get_life_pointer()));
	B->set_pot_quantity2(B->get_life_pointer(), -1);
	std::cout << "Life Potion used" << std::endl;
}

void Personagem::use_stamina_potion(Inventario *B){
	Personagem::set_stamina(B->get_pot_stamina(B->get_stamina_pointer()));
	B->set_pot_quantity2(B->get_stamina_pointer(), -1);
}

int Personagem::get_life_pot_quantity(Inventario *B){
	return B->get_pot_quantity2(B->get_life_pointer());
}

int Personagem::get_stamina_pot_quantity(Inventario *B){
	return B->get_pot_quantity2(B->get_stamina_pointer());
}

void Personagem::set_life_pot_quantity(Inventario *B, int num1){
	B->set_pot_quantity2(B->get_life_pointer(), num1);
}

void Personagem::set_stamina_pot_quantity(Inventario *B, int num1){
	B->set_pot_quantity2(B->get_stamina_pointer(), num1);
}

int Personagem::get_gold1(Inventario *B){
	return B->get_gold2();
}

void Personagem::set_gold1(Inventario *B, int num1){
	B->set_gold2(num1);
}