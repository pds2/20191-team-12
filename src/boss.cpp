#include "boss.h"
#include "Habilidade.h"
#include <string>
#include <iostream>

Boss::Boss(std::string n, float MaxAtk, float MinAtk, float def, float lf){
	this -> name = n;
	this -> max_attack = MaxAtk;
	this -> min_attack = MinAtk;
	this -> defense = def;
	this -> life = lf;
}


std::string Boss::get_name(){
	return this->name;
}

float Boss::get_max_attack(){
	return this-> max_attack;
}

float Boss::get_min_attack(){
	return this-> min_attack;
}

float Boss::get_defense(){
	return this-> defense;
}

float Boss::get_life(){
	return this-> life;
}

int Boss::type(){
	return 1;
}

int Boss::get_hdamage(){
	return this-> skill.get_damage();
}
int Boss::get_hspend(){
	return this-> skill.get_spend();
}

void Boss::set_skill(Habilidade k){
	this->skill = Habilidade(k.get_name(),k.get_damage(),k.get_spend());
}

void Boss::set_max_attack(float MaxAtk){
	this-> max_attack = MaxAtk;
}

void Boss::set_min_attack(float MinAtk){
	this-> min_attack = MinAtk;
}

void Boss::set_defense(float def){
	this-> defense = def;
}
 void Boss::set_life(float lf){
 	this-> life = lf;
 }