#include <iostream>
#include <jogo.h>
#include <Personagem.h>

#define CONTINUAR 1


int main(){
int c;
std::string name;

std::cout << "Bem Vindo ao universo de Game of Thrones! Este jogo eh uma parodia criada pelos alunos de PDS II." << endl;
std::cout << "Derrote os sete reinos e domine Westeros! O nosso jogo eh bem realista. Aqui voce soh tem uma chance" << endl;
std::cout << "Escolha um nome para seu personagem:";
std::cin >> name;

Personagem(name); //construtor
int n = 1;

    while(c == CONTINUAR){
        get_stage_game(&n, player);
    }
    return 0;
}
