#include <iostream>
#include "FuncoesGerais.h"
#include "FuncaoLoja.h"
#include "Personagem.h"
#include "jogo.h" //para utilizar a função exit_game();
#include "menu.h"
#include "npc.h"
#include "treino.h"

void show_init(){
    //codigo (pagina inicial do jogo)
}

void show_menu(Personagem &heroi, Npc &npc, int& t_num, int fase_num){ //Menu que aparecerá antes da batalha contra o boss
    
	int numero;

	std::cout << std::endl;
	std::cout << "+------------------------------------------+" << std::endl;
	std::cout << "| 0 - Seguir jornada |  1 - Treino         |" << std::endl;
	std::cout << "| 2 - Loja  		   |  3 - Sair do jogo   |" << std::endl;
	std::cout << "+------------------------------------------+" << std::endl;

	checker(&numero, 0, 3);

	if(numero == 0){
		return;
	} else if (numero == 1){
		treinar(heroi, npc, t_num, fase_num);
		return;
	} else if (numero == 2){
		Funcao_Loja(heroi);
		return;
	} else if (numero == 3){
		exit_game();
	}
}

void show_menu_h(){ // Menu entre a historia/dialogos
	
	int numero;
	
	std::cout << "----------------------------------------------\n";
	std::cout << "| 0 - Continuar    |    1 - Abandonar o jogo |\n";
	std::cout << "----------------------------------------------\n";
	
	checker(&numero, 0, 1);
	
	if(numero == 0){
		return;
	} else {
		exit_game();
	}
}
