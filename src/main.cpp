#include <iostream>
#include "jogo.h"
#include "Personagem.h"

#define CONTINUAR 1


int main(){
    std::string name;

    std::cout << "Bem Vindo ao universo de \33[1;32mGame of Thrones\33[m! Este jogo eh uma parodia criada pelos alunos de PDS II." << std::endl;
    std::cout << "Derrote os sete reinos e domine Westeros! \nO nosso jogo eh bem realista. Aqui voce soh tem uma chance de ganhar, logo, se morrer o jogo acaba!!" << std::endl;
    std::cout << "Escolha um nome para seu personagem:";
    std::getline(std::cin, name);

    Personagem player(name); //construtor
    int t_num;

    t_num = 3;
    Fase_1(player, t_num);
    t_num = 4;
    Fase_2(player, t_num);
    t_num = 5;
    Fase_3(player, t_num);
    t_num = 6;
    Fase_4(player, t_num);
    t_num = 7;
    Fase_5(player, t_num);
    t_num = 8;
    Fase_6(player, t_num);
    t_num = 9;
    Fase_7(player, t_num);
}
