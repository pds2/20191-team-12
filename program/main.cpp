#include <iostream>
#include <jogo.h>
#include <Personagem.h>

#define CONTINUAR 1


int main(){
std::string name;

std::cout << "Bem Vindo ao universo de \33[1;32mGame of Thrones\33[m! Este jogo eh uma parodia criada pelos alunos de PDS II." << std::endl;
std::cout << "Derrote os sete reinos e domine Westeros! \nO nosso jogo eh bem realista. Aqui voce soh tem uma chance de ganhar, logo, se morrer o jogo acaba!!" << std::endl;
std::cout << "Escolha um nome para seu personagem:";
std::getline(std::cin, name);

Personagem player(name); //construtor

    Fase_1(player, 3);
    Fase_2(player, 4);
    }
