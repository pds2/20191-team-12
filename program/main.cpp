#include <iostream>
#include "Arma.h"
#include "Armadura.h"
#include "Batalha.h"
#include "boss.h"
#include "fases.h"
#include "FuncaoLoja.h"
#include "FuncoesGerais.h"
#include "mob.h"
#include "npc.h"
#include "Habilidade.h"
#include "Inventario.h"
#include "treino.h"
#include "Personagem.h"
#include "Pocao.h"

#define CONTINUAR 1


int main(){
int c, vidas = 3;

std::string name;

std::cout << "Bem Vindo ao universo de Game of Thrones! Este jogo é uma paródia criada pelos alunos de PDS II." << endl;
std::cout << "Derrote os sete reinos e domine Westeros!" << endl;
std::cout << "Escolha um nome para seu personagem:";
std::cin >> name;
Personagem(name); //construtor


    while(vidas > 0 && c == CONTINUAR){
        if(get_stage_game(&i) == FALSE){
             vidas--;
        }
        exit(&c);
    }
    
    return 0;
}
