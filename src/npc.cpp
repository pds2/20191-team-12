#include "npc.h"
#include <string>
#include <iostream>

Npc::Npc(){
	this-> max_attack = 0;
	this-> min_attack = 0;
	this-> defense = 0;
	this-> life = 0;
}

Npc::Npc(std::string n){
	this->name = n;
}

Npc::Npc(std::string n, float atk_max, float atk_min, float def, float lf){
	this-> name = n;
	this-> max_attack = atk_max;
	this-> min_attack = atk_min;
	this->defense = def;
	this-> life = lf;
	//this->armor = arm;
}

std::string Npc::get_name(){
	return this->name;
}

float Npc::get_max_attack(){
	return this-> max_attack;
}

float Npc::get_min_attack(){
	return this-> min_attack;
}

float Npc::get_defense(){
	return this-> defense;
}
float Npc::get_life(){
	return this-> life;
}

int Npc::type(){
	return 0;
}

void Npc::set_life(float lf){
	this-> life = lf;
}
void Npc::set_max_attack(float MaxAtk){
	this-> max_attack = MaxAtk;
}

void Npc::set_min_attack(float MinAtk){
	this-> min_attack = MinAtk;
}

void Npc::set_defense(float def){
	this-> defense = def;
}

void Npc::set_name(std::string n){
	this-> name = n;
}
