#include <iostream>
#include <time.h>
#include "treino.h"
#include "Batalha.h"
#include "FuncoesGerais.h"
#include "Personagem.h"
#include "npc.h"


void treinar(Personagem &heroi, Npc &npc, int t_num, int vgold_min, int vgold_max){ //t_num = quantidade de numero de treino
																					//v_gold = variação da quantidade de gold
	 Npc enemies[t_num];
	 for(int i = 0;i < t_num; i++){
	 	enemies[i].set_life(npc.get_life());
	 	enemies[i].set_defense(npc.get_defense());
	 	enemies[i].set_max_attack(npc.get_max_attack());
	 	enemies[i].set_min_attack(npc.get_max_attack());
	 	enemies[i].set_name(npc.get_name());
	 }

	if(t_num == 0){
		std::cout << "Ta se achando a Daniela Tavares? Voce ja matou todos os soldados na area... " << std::endl;
		return;
	}	

	int op;
	srand (time(NULL));

	do{ 
		int gold = (rand() % vgold_max) + vgold_min; //gold varia entre a quantia máxima e minima passada
													//vgold_max e vgold_min aumentam de acordo com o passar das fases
		
		if(batalha(heroi, enemies[t_num - 1]) == 0){
			if(heroi.get_life() > 0){
				heroi.set_gold(heroi.get_gold() - gold);
				std::cout << "Voce envergonhou os 7 Deuses e seus pais. Voce perdeu " << gold << "moedas." << std::endl; 
			}
		}else{
			heroi.set_gold(heroi.get_gold() + gold);
			std::cout << "Parabens, voce matou uma pessoa! Voce recebeu " << gold << " moedas." << std::endl;
		}
		t_num--;

		if(t_num > 0){
			std::cout << "Treino concluido. Voce ja tem " << heroi.get_gold() << " moedas." << std::endl;
			std::cout << "Caso esteja entediado de matar soldados e queira sair do treino, digite 0" << std::endl;
			std::cout << "Caso nao sinta-se preparado, voce pode continuar lutando contra os soldados digitando 1." << std::endl;
		} else{
			std::cout << "Voce matou o ultimo soldado do vilarejo. Parece que temos um novo Montanha no reino..." << std::endl;
		}

		checker(&op, 0, 1); // validacao da escolha entre 0 - sair e 1 - continuar
		
		if (op == 0){
			std::cout << "Treino finalizado. Boa sorte na sua batalha, Guerreiro, voce vai precisar!" << std::endl;
			break;
		}
	
	}while ((t_num > 0) && (op == 1));
}
