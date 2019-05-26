#include "Habilidade.h"
#include <string>

Habilidade::Habilidade(std::string nome, int dano, int gasto){
	this->damage = dano;
	this-> spend = gasto;
	this-> name = nome;
}

int Habilidade::get_damage(){
	return this->damage;
}

int Habilidade::get_spend(){
	return this->spend;
}
std::string Habilidade::get_nome(){
	return this-> name;
}