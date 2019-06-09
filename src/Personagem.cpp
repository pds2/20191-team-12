#include "Inventario.h"
#include "Personagem.h"
#include "Arma.h"
#include "Armadura.h"
#include "Habilidade.h"
#include "FuncoesGerais.h"

#include <iostream>
#include <string>
#include <vector>


// CONSTRUTOR

Personagem::Personagem(std::string _name){
	this->name = _name;
	this->life = 100;
	this->defense = 20;
	this->attack = 20;
	this->stamina = 100;
}

Personagem::Personagem(std::string _name, int _life, int _defense, int _attack, int _stamina){
	this->name = _name;
	this->life = _life;
	this->defense = _defense;
	this->attack = _attack;
	this->stamina = _stamina;
}

// ACESSO E MUDANÇA DE ATRIBUTOS GERAIS

std::string Personagem::get_name(){
	return this->name;
}

int Personagem::get_life(){
	return this->life;
}

void Personagem::set_life(int life_change){
	if(life_change <= 0){
		this->life = 0;
	} else{
		this->life = life_change;
	}
}

int Personagem::get_defense(){
	return this->defense;
}

void Personagem::set_defense(int def_change){
	this->defense = def_change;
}

int Personagem::get_attack(){
	return this->attack;
}

void Personagem::set_attack(int attack_change){
	this->attack = attack_change;
}

int Personagem::get_stamina(){
	return this->stamina;
}

void Personagem::set_stamina(int stamina_change){
	if(stamina_change <= 0){ 
		this->stamina = 0;
	} else{
		this->stamina = stamina_change;
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

bool Personagem::check_gold(int price){
	if(this->inventory.get_gold() < price){
		return false;
	} else{
		return true;
	}
}

std::vector<Armadura> Personagem::get_inventory_armor(){
	return this->inventory.get_full_unused_armor();
}

std::vector<Arma> Personagem::get_inventory_weapon(){
	return this->inventory.get_full_unused_weapon();
}

int Personagem::armor_inventory_position(int id){
	return this->inventory.armor_inventory_position(id);
}

int Personagem::weapon_inventory_position(int id){
	return this->inventory.weapon_inventory_position(id);
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
	std::cout << "Sua armadura atual: \n";
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
	std::cout << "Sua arma atual: \n";
	this->weapon.display_weapon();
}
//FUNÇÕES HABILIDADES
void Personagem::add_skill(Habilidade hab){
	Habilidade A = Habilidade(hab.get_name(),hab.get_damage(),hab.get_spend());
	this-> skill.push_back(A);
}

void Personagem::remove_skill(int y){
	if(this->skill.size() >= y){
		if(y == 0){
			this-> skill.erase(skill.begin());
			return;
		}
		this-> skill.erase(skill.begin() + y);
	}else{
		std::cout<<"Opcão Invalida"<<std::endl;
	}
	return;
}

void Personagem::display_skill(){
	if(get_nskill() == 0){
		std::cout<<"Voce nao possui habilidades ainda!"<<std::endl;
		return;
	}
	std::cout<<std::endl;
	std::cout<<"HABILIDADES:          (Dano/Stamina)"<<std::endl;
	for(int i = 0; this->skill.size() > i; i++){
		std::cout<<"#"<< i << this->skill[i].get_name()<<"  ("<< this->skill[i].get_damage() <<"/"<< this->skill[i].get_spend() <<")"<<std::endl;
	}
	return;

}
int Personagem::get_nskill(){
	return this->skill.size();
}

Habilidade Personagem::get_skill(int k){
	return this->skill[k];
}

// Funcoes de uso direto

void Personagem::add_armor(Armadura A){
	this->inventory.add_armor(A);
}

void Personagem::add_weapon(Arma A){
	this->inventory.add_weapon(A);
}

void Personagem::remove_armor(int id){
	this->inventory.remove_armor(id);
}

void Personagem::remove_weapon(int id){
	this->inventory.remove_weapon(id);
}

void Personagem::equip_armor(Armadura toequip){
	unequip_armor();
	this->armor.equip(toequip);
	set_defense(this->defense + this->armor.get_defense());
}

void Personagem::unequip_armor(){
	set_defense(this->defense - this->armor.get_defense());
	if(this->armor.get_id() != 0){
		this->inventory.add_armor(this->armor);
	}
	this->armor.unequip();
}

void Personagem::equip_weapon(Arma toequip){ // Ainda precisa fazer checagem de inventário ou direto da loja!!!
	unequip_weapon();
	this->weapon.equip(toequip);
	set_attack(this->attack + this->weapon.get_attack());
}

void Personagem::unequip_weapon(){
	set_attack(this->attack - this->weapon.get_attack());
	if(this->weapon.get_id() != 0){
		this->inventory.add_weapon(this->weapon);
	}
	this->weapon.unequip();
}

//void Personagem::equip_inventory_armor(int num){

void Personagem::display_stats(){
	std::string string1 = "     Guerreiro " + this->name;
	std::string string2 = "     Vida: " + std::to_string(this->life) + " | Stamina: " + std::to_string(this->stamina);
	std::string string3 = "     Ataque: " + std::to_string(this->attack) + " | Defesa: " + std::to_string(this->defense);
	std::string string4 = "     Moedas de ouro: " + std::to_string(this->get_gold());

	print_square(string1, string2, string3, string4);
}


