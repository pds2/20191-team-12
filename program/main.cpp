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


using namespace std;

//declarar variaveis globais: vidas, personagem
//exibir menu de escolha e textinho
//coletar dados do jogador (escolher o nome)

int vidas = 3;
std::string name;

cout << "Bem Vindo ao universo de Game of Thrones! Este jogo é uma paródia criada pelos alunos de PDS II." << endl;
cout << "Derrote os sete reinos e domine Westeros!" << endl;
cout << "Escolha um nome para seu personagem:";
cin >> name;
Personagem(name); //construtor

int main(){
    while(vidas > 0){
        get_stage_game(1);
        //funcao menu
    }
}
