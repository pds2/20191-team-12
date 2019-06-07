#include "Batalha.h"
#include "mob.h"
#include "npc.h"
#include "boss.h"
#include "Personagem.h"
#include "Habilidade.h"
#include "FuncoesGerais.h"

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int batalha(Personagem &heroi, Mob &npc){
	int op;

	std::cout << "Prepare-se para a batalha!\n";
	std::cout << "Inimigo: " << npc.get_name() << "\nDano de ataque: " << npc.get_max_attack() << "\nDefesa: " << npc.get_defense() << "\n\n";
	do{
		std::cout << "Vida: " << heroi.get_life() << "    Vida Inimigo: " << npc.get_life() << "\n";
		std::cout << "Stamina: " << heroi.get_stamina() << "\n";
		std::cout << "-------------------------------------------------\n";
		std::cout << "| 1 - Atacar                      2 - Habildade |\n";
		std::cout << "|                                               |\n";
		std::cout << "| 3 - Inventario                  4 - Fugir     |\n";
		std::cout << "-------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);
		switch(op){
			case 1: atacar(heroi, npc);
					atacar_mob(heroi, npc);
					break;
			case 2: menu2(heroi, npc);
					break;
			case 3: menu3(heroi, npc);
					break;
			case 4: return 2; // Fugiu
		}
	}while(npc.get_life() > 0 && heroi.get_life() > 0);
	if(heroi.get_life() < 0){ // Herói morreu
		return 0;
	}
	if(npc.get_life() < 0){ // Inimigo morreu
		return 1;
	}
}

int true_damage(int ataque, float defesa){ // Desconta a defesa do ataque e retorna o dano real (taxa de defesa da armadura = 4*sqrt(defesa))
	defesa = 4*sqrt(defesa);
	int true_damage = ataque*(1-(defesa/100.0));
	return true_damage;
}

void atacar(Personagem& heroi, Mob& npc){ // Herói ataca o inimigo
	srand (time(NULL));
	int ataque = rand() % 11 + (heroi.get_attack()-5);
	float defesa = rand() % 11 + (npc.get_defense() - 5);
	npc.set_life(npc.get_life() - true_damage(ataque, defesa));
	std::cout << "Seu ataque causou " << true_damage(ataque, defesa) << " de dano!\n\n";
}

void atacar_mob(Personagem &heroi, Mob &npc){ // Inimigo ataca o herói
	srand (time(NULL));
	int ataque = rand() % 11 + npc.get_min_attack();
	float defesa = rand() % 11 + (heroi.get_defense() - 5);
	heroi.set_life(heroi.get_life() - true_damage(ataque, defesa));
	std::cout << "Você recebeu " << true_damage(ataque, defesa) << " de dano do inimigo!\n";
}

void menu2(Personagem &heroi, Mob &npc){ // Menu da opção 2
	int op;

	heroi.display_skill();
	checker(&op,0, heroi.get_nskill());			 //Checha as entradas
	atacar_hab(heroi, npc, heroi.get_skill(op));
	
	if(npc.get_life() > 0){							//Testa se Mob ainda vive
		if(npc.type() == 1){ 						//Testa o tipo da subclasse para diferenciar o ataque de resposta
		Boss chief = dynamic_cast<Boss&>(npc); 
		atacar_hab_boss(heroi, chief);
		}else{
			atacar_mob(heroi, npc);
		}		
	}

}

void menu3(Personagem &heroi, Mob &npc){ // Display do inventário de poções
	int op;
		std::cout << "-------------------------------------------------\n";
		std::cout << "| 1 - Poção de vida: " << heroi.get_life_pot_quantity() << "x                        |\n" << " 2 - Poção de stamina : " << heroi.get_stamina_pot_quantity() << "x                     |\n";
		std::cout << "-------------------------------------------------\n";
		checker(&op, 1, 2);
	switch(op){
		case 1: heroi.use_life_potion(); // Usa poção de vida
				break;
		case 2: heroi.use_stamina_potion(); // Usa poção de stamina
				break;
	}
	atacar_mob(heroi,npc);
}

void atacar_hab(Personagem &heroi, Mob &npc, Habilidade hab){ // Herói ataca habilidade no inimigo
	srand(time(NULL));
	int ataque = hab.get_damage();
	float defesa = rand() % 11 + (npc.get_defense() - 5);
	npc.set_life(npc.get_life() - true_damage(ataque,defesa));
	int gasto = heroi.get_stamina() - hab.get_spend();
	heroi.set_stamina(gasto);
	std::cout<<hab.get_name()<<" deu dano de "<< true_damage(ataque,defesa) << " no inimigo!"<<std::endl;
}

void atacar_hab_boss(Personagem& heroi, Boss& x){ // Boss ataca habilidade no herói
	srand(time(NULL));
	int ataque = x.get_hdamage();
	float defesa = rand() % 11 + (heroi.get_defense() - 5);
	heroi.set_life(heroi.get_life() - true_damage(ataque, defesa));
	std::cout<< x.get_name() <<" te causou um dano de "<< true_damage(ataque,defesa) <<" com uma habilidade"<< std::endl;
}
