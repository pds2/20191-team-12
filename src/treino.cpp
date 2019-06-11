#include <iostream>
#include <time.h>
#include <math.h>
#include "treino.h"
#include "Batalha.h"
#include "FuncoesGerais.h"
#include "Personagem.h"
#include "npc.h"
#include "jogo.h"


void treinar(Personagem &heroi, Npc &npc, int t_num, int fase_num){ //t_num = quantidade de numero de treino

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

	int op, result;
	srand (time(NULL));

	do{ 
		int gold = reward(fase_num, 2, heroi); //variação de gold em relação à fase
		result = batalha(heroi, enemies[t_num - 1]);
		if(result == 0){
			std::cout << "Voce envergonhou os 7 Deuses e seus pais. Voce perdeu o jogo..." << std::endl;
			pausar();
			exit(0);

		}											
		else if(result == 1){
			heroi.set_gold(heroi.get_gold() + gold);
			std::cout << "Parabens, voce matou uma pessoa! Voce recebeu " << gold << " moedas." << std::endl;
		}else{
			float lost_gold_percentage = 0.2;
			float lost_gold = (float)heroi.get_gold() * lost_gold_percentage;
			heroi.set_gold(heroi.get_gold() - (int)lost_gold);
			std::cout << "Voce jogou avioezinhos de dinheiro para distrair o inimigo e saiu correndo! Voce continua vivo, mas perdeu " << (int)lost_gold << " moedas." << std::endl;
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
