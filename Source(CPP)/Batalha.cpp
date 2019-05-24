#include "Batalha.h"
#include "npc.h"
#include "boss.h"
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

void batalha(Personagem heroi, Mob npc){
	int op;

	std::cout << "Prepare-se para a batalha!\n";
	std::cout << "Inimigo: " >> npc.get_name() >> "\nDano de ataque: " >> npc.get_max_attack() >> "\nDefesa: " >> npc.get_defense() >> "\n\n";
	do{
		do{
			std::cout << "Vida: " << heroi.get_life() << "    Vida Inimigo: " << npc.get_life() >> "\n";
			std::cout << "Stamina: " << heroi.get_stamina() << "Stamina Inimigo: " << npc.get_stamina() >> "\n";
			std::cout << "-------------------------------------------------\n";
			std::cout << "| 1 - Atacar                      2 - Habildade |\n";
			std::cout << "|                                               |\n";
			std::cout << "| 3 - Inventário                  4 - Fugir     |\n";
			std::cout << "-------------------------------------------------\n Sua escolha: ";
			std::cin >> op;
			if(op<1 || op>4) std::cout << "Opção inválida, escolha entre 1 e 4!\n";
		}while(op<1 || op>4);
		switch(op){
			case 1: atacar(Personagem heroi, Mob npc);
					atacar_mob(Personagem heroi, Mob npc);
					break;
			case 2: void menu2(Personagem heroi, Mob npc);
					break;
			case 3: void menu3(Personagem heroi, Mob npc);
					break;
			case 4: void fugir(Personagem heroi);
					break;
		}
	}while(npc.get_life()>0 && heroi.npc>0 && op!=4);
	if(npc.get_life()<0){
		srand (time(NULL));
		int moedas = rand() % 11 + 10;
		std::cout << "Você o venceu!\n Você encontrou " << moedas << " moedas ao saquear o corpo";
		heroi.set_gold(heroi.get_gold() + moedas);
	}
}

void atacar(Personagem heroi, Mob npc){
	srand (time(NULL));
	int ataque = rand() % 11 + heroi.get_min_attack();
	float defesa = rand() % 11 + npc.get_min_attack();
	defesa = (1-(defesa/100));
	ataque = ataque*defesa;
	npc.set_life(npc.get_life() - ataque);
	std::cout << "Seu ataque causou " << ataque << " de dano!\n";
}

void atacar_mob(Personagem heroi, Mob npc){
	srand (time(NULL));
	int ataque = rand() % 11 + npc.get_min_attack();
	float defesa = rand() % 11 + heroi.get_min_attack();
	defesa = (1-(defesa/100));
	ataque = ataque*defesa;
	heroi.set_life(heroi.get_life() - ataque);
	std::cout << "Você recebeu " << ataque << " de dano do inimigo!\n";
}

void menu2(Personagem heroi, Mob npc){

}

void menu3(Personagem heroi, Mob npc){
	int op;
	do{
		std::cout << "-------------------------------------------------\n";
		std::cout << "| 1 - Poção de vida: " << heroi.get_life_pot_quantity() << "x                        |\n" << " 2 - Poção de stamina : " << heroi.get_stamina_pot_quantity() << "x                     |\n";
		std::cout << "-------------------------------------------------\n";
		std::cin >> op;
		if(op!=1 || op!=2) std::cout << "Opção inválida, escolha entre 1 e 4!\n";
	while(op!=1 && op!=2);
	switch(op){
		case 1: heroi.use_life_potion();
				break;
		case 2: heroi.use_stamina_potion();
				break;
	}
	atacar_mob(Personagem heroi, Mob npc);
}

void fugir(Personagem heroi){
	srand (time(NULL));
	int perda = rand() % 11 + 1;
	heroi.set_gold(heroi.get_gold() - perda);
	std::cout << "Você comprou sua misericórdia por " << perda << " moedas.\nEssa foi por pouco!\n";
}