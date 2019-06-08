#include <iostream>
#include "FuncoesGerais.h"
#include "FuncoesLoja.h"
#include "Personagem.h"

void show_init(){
    //codigo (pagina inicial do jogo)
}

void show_menu(Personagem &heroi, Npc &npc){
    
	int numero;

	std::cout << "-----------------------------------------------------\n";
	std::cout << "| 0 - Seguir jornada       |       1 - Treino       |\n";
	std::cout << "| 2 - Loja  				 |       3 - Mapa		  |\n";
	std::cout << "| 											      |\n";
	std::cout << "| 				4 - Sair do jogo			      |\n";
	std::cout << "-----------------------------------------------------\n";

	checker(&numero, 0, 4);

	if(numero == 0){
		return;
	} else if (numero == 1){
		treinar(heroi, npc, t_num, vgold_min, vgold_max);
	} else if (numero == 2){
		Funcao_Loja(heroi);
	} else if (numero == 3){
		//funcaoMapa;
		return;
	} else if (numero == 4){
		exit_game(&numero);
	}
	//codigo (loja x treinar x mapa x seguir jornada x sair do jogo)
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
		exit();
	}
}
