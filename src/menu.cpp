#include <iostream>
#include "FuncoesGerais.h"

void show_init(){
    //codigo (pagina inicial do jogo)
}

void show_menu(){
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
