#include "Habilidade.h"
#include <string>

Habilidade::Habilidade(std::string nome, int dano, int gasto){
	this-> damage = dano;
	this-> spend = gasto;
	this-> name = nome;
}
Habilidade::Habilidade(){
	this-> damage = 0;
	this-> spend = 0;
	this-> name = "Habilidade Nula";
}

int Habilidade::get_damage(){
	return this->damage;
}

int Habilidade::get_spend(){
	return this->spend;
}
std::string Habilidade::get_name(){
	return this-> name;
}

void Habilidade::set_nome(std::string n){
	this-> name = n;
}

void Habilidade::set_damage(int d){
	this-> damage = d;
}

void Habilidade::set_spend(int s){
	this-> spend = s;
}