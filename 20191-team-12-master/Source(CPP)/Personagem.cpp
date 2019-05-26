#include "Pocao.h"
#include "Inventario.h"
#include "Personagem.h"
#include "Arma.h"
#include "Armadura.h"
#include "Habilidade.h"

#include <iostream>
#include <string>
#include <vector>


// CONSTRUTOR

Personagem::Personagem(std::string _obj_name, std::string _casa, int _life, int _defense, int _attack, int _stamina, Inventario _inventory, Armadura _armor, Arma _weapon){
	this->name = _obj_name;
	this->casa = _casa;
	this->life = _life;
	this->defense = _defense;
	this->attack = _attack;
	this->stamina = _stamina;
	this->inventory = _inventory;
	equip_armor(_armor);
	equip_weapon(_weapon);
}

// ACESSO E MUDANÇA DE ATRIBUTOS GERAIS

std::string Personagem::get_name(){
	return this->name;
}

std::string Personagem::get_casa(){
	return this->casa;
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

// ACESSO E MUDANÇA DE POCOES

int Personagem::get_life_pot_quantity(){
	return this->inventory.get_life_quantity();
}

int Personagem::get_stamina_pot_quantity(){
	return this->inventory.get_stamina_quantity();
}

void Personagem::set_life_pot_quantity(int num){
	if(this->inventory.get_life_quantity() + num < 0){
		std::cout << "O personagem não pode ter um numero negativo de poções" << std::endl;
	} else{
		this->inventory.set_life_quantity(num);
	}
}

void Personagem::set_stamina_pot_quantity(int num){
	if(this->inventory.get_stamina_quantity() + num < 0){
		std::cout << "O personagem não pode ter um numero negativo de poções" << std::endl;
	} else{
		this->inventory.set_stamina_quantity(num);
	}
}

// ACESSO DIRETO INVENTARIO;

int Personagem::get_gold(){
	return this->inventory.get_gold();
}

void Personagem::set_gold(int num){
	this->inventory.set_gold(num);
}

void Personagem::display_inventory(){
	std::cout << "**Inventario**:" << std::endl;
	this->inventory.display_inventory();
}

// ACESSO E MUDANÇA ARMAS E ARMADURAS

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

void Personagem::display_armor(){
	std::cout << "Sua armadura: ";
	this->armor.display_armor();
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

void Personagem::display_weapon(){
	std::cout << "Sua arma: ";
	this->weapon.display_weapon();
}
//FUNÇÕES HABILIDADES
void Personagem::add_skill(&Habilidade x){
	this-> skill.pushback(x);
}

void Personagem::remove_skill(int y){
	if(this->skill.size() >= y){
		this-> skill.erase(y);
	}else{
		std::cout<<"Opção Invalida"
	}
	return;
}

void Personagem::display_skill(){
	for(int i = 0; this->skill.size() > i; i++){
		std::cout<<"HABILIDADES:          (Dano/Stamina)"<<std::endl;
		std::cout<<"#"<<i<<this->skill[i].get_name()<<"("<<this->skill[i].get_damage()<<"/"<<this->skill[i].get_spend()<<")"<<std::endl;
	}

}
int Personagem::get_nskill(){
	return this->skill.size();
}

Habilidade Personagem::get_skill(int k){
	return this->skill[k];
}

// Funcoes de uso direto

void Personagem::use_life_potion(){
	if(this->inventory.get_life_quantity() < 1){
		std::cout << "Não há poção para ser usada." << std::endl;
	} else{
		this->set_life(this->inventory.get_life());
		this->inventory.set_life_quantity(-1);
	}
}

void Personagem::use_stamina_potion(){
	if(this->inventory.get_stamina_quantity() < 1){
		std::cout << "Não há poção para ser usada." << std::endl;
	} else{
		this->set_stamina(this->inventory.get_stamina());
		this->inventory.set_stamina_quantity(-1);
	}
}

void Personagem::add_armor(Armadura A){
	this->inventory.add_armor(A);
}

void Personagem::add_weapon(Arma A){
	this->inventory.add_weapon(A);
}

void Personagem::equip_armor(Armadura toequip){
	unequip_armor();
	this->armor.equip(toequip);
	set_defense(this->armor.get_defense());
}

void Personagem::unequip_armor(){
	set_defense((-1) * this->armor.get_defense());
	if(this->armor.get_id() != 0){
		this->inventory.add_armor(this->armor);
	}
	this->armor.unequip();
}

void Personagem::equip_weapon(Arma toequip){ // Ainda precisa fazer checagem de inventário ou direto da loja!!!
	unequip_weapon();
	this->weapon.equip(toequip);
	set_attack(this->weapon.get_attack());
}

void Personagem::unequip_weapon(){
	set_attack((-1) * this->weapon.get_attack());
	if(this->weapon.get_id() != 0){
		this->inventory.add_weapon(this->weapon);
	}
	this->weapon.unequip();
}

void Personagem::display_stats(){
	std::cout << "\nGuerreiro " << get_name() << " da casa " << get_casa() << "\nVida: " << get_life() << "\t Stamina: " << get_stamina() << "\nAtaque: " << get_attack() <<
	"\tDefesa: " << get_defense() << "\n\n";
}

