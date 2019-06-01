#include <iostream>
#include <Personagem.h>
#include <fases.h>

using namespace std;

//declarar variaveis globais: vidas, personagem
//exibir menu de escolha e textinho
//coletar dados do jogador (escolher o nome)

int vidas = 3;
Personagem player;

cout << "Bem Vindo ao universo de Game of Thrones! Este jogo é uma paródia criada pelos alunos de PDS II. Sem fins lucrativos" << endl;
cout << "Escolha um nome para seu personagem:";
cin >> player.name;//ja chama o construtor passando o nome como parâmetro?


int main(){
    while(vidas > 0){
        get_stage_game(1);
        //funcao menu
        
    
    }
}