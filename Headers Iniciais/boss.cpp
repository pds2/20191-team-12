#include "boss.h"
#include <string>
#include <iostream>

Boss::Boss(std::string n){
	this->name = n;
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

/*
Habilidade Boss::get_skill(){

}

void Boss::set_skill(Habilidade &x){
	
}

Armadura Boss::get_armadura(){
	
}

void Boss::set_armor(Armadura &x){
	
}
*/

void Boss::set_max_attack(float MaxAtk){
	this-> max_attack = MaxAtk;
}

void Boss::set_min_attack(float MinAtk){
	this-> min_attack = MinAtk;
}

void Boss::set_defense(float def){
	this-> defense = def;
}
