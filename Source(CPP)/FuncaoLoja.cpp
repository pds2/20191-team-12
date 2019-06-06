#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "Pocao.h"
#include "Inventario.h"
#include "Personagem.h"
#include "Arma.h"
#include "Armadura.h"
#include "FuncoesGerais.h"
#include "FuncaoLoja.h"
#include <vector>

// Textos
void present_store(){
	std::cout << "-Vendedor: Bem vindo a loja, aventureiro. Aqui e possivel comprar diversos itens para melhorar ou recuperar os atributos do seu personagem, tais como: \n";
}

void menu_store(){
	std::cout << "1 - Armas\n" << "2 - Armaduras\n" << "3 - Utilidades\n" << "4 - Sair\n";
	std::cout << "Sua escolha: " << std::endl;
}

void instruction_store(Personagem A){
	std::cout << "Digite o ID do item para comprar ou 0 para voltar." <<"\n";
	std::cout << "Voce tem " << std::to_string(A.get_gold()) << " de gold.\n";
}

void remaining_gold(Personagem A){
	if(A.get_gold() > 0){
		std::cout << "\n-Vendedor: Me disseram que voce ainda tem "<< A.get_gold() << " de gold. Deseja comprar mais alguma coisa?" << std::endl;
	} else {
		std::cout << "-Vendedor: Me parece que voce esta sem dinheiro, mas eu posso lhe deixar ver a loja novamente..." << std::endl;
	}
}

void buy_weapon(Personagem &A, std::vector<Arma> &weapons){
	int buy_id = -1;

	checker(&buy_id, 0, (weapons.back()).get_id());
	if(buy_id == 0){
		return;
	}

// Encontrando o item a ser comprado, funcionamento do loop depende a)da validação acima, b)da disposição de ID do arquivo de carregamento
	int i = 0;
	while(buy_id != weapons[i].get_id()){
		i++;
	}

// Checando se a compra pode ser feita;
	if(A.check_gold(weapons[i].get_price())){
		A.equip_weapon(weapons[i]);
		A.set_gold(A.get_gold() - weapons[i].get_price());
		std::cout << "Arma comprada!" << std::endl;
		std::cout << "Seu novo ataque e: " << A.get_attack() << std::endl;

	} else{
		int fala = rand() % 3;
		switch(fala){
			case 0: std::cout << "-Vendedor: Nao tente me enganar jovem aventureiro, voce nao tem dinheiro para comprar algo tao bom. Vou te dar mais uma chance, escolha outro item: " << std::endl; break;
			case 1: std::cout << "-Vendedor: Ora ora, parece que alguem esta tentando me enganar. Pare de brincadeiras e escolha algo a seu alcance: " << std::endl; break;
			case 2: std::cout << "-Vendedor: Vai ter que se contentar com algo mais barato. Escolha novamente: " << std::endl; break;
		}
		buy_weapon(A, weapons);
	}
}

void buy_armor(Personagem &A, std::vector<Armadura> &armors){
	int buy_id = -1;

	checker(&buy_id, 0, (armors.back()).get_id());
	if(buy_id == 0){
		return;
	}

// Encontrando o item a ser comprado, funcionamento do loop depende a)da validação acima, b)da disposição de ID do arquivo de carregamento
	int i = 0;
	while(buy_id != armors[i].get_id()){
		i++;
	}

// Checando se a compra pode ser feita;
	if(A.check_gold(armors[i].get_price())){
		A.equip_armor(armors[i]);
		A.set_gold(A.get_gold() - armors[i].get_price());
		std::cout << "Armadura comprada!" << std::endl;
		std::cout << "Sua nova defesa e: " << A.get_defense() << std::endl;

	} else{
		int fala = rand() % 3;
		switch(fala){
			case 0: std::cout << "-Vendedor: Nao tente me enganar jovem aventureiro, voce nao tem dinheiro para comprar algo tao bom. Vou te dar mais uma chance, escolha outro item: " << std::endl; break;
			case 1: std::cout << "-Vendedor: Ora ora, parece que alguem esta tentando me enganar. Pare de brincadeiras e escolha algo a seu alcance: " << std::endl; break;
			case 2: std::cout << "-Vendedor: Vai ter que se contentar com algo mais barato. Escolha novamente: " << std::endl; break;
		}
		buy_armor(A, armors);
	}
}

void buy_potion(Personagem &A, int price_on_potion){
	int item = -1;
	checker(&item,0,2);     

	if(item == 0){
		return;

	} else if(item == 1){
		if(A.check_gold() < price_on_potion){
			std::cout << "Pocoes sao realmente baratas, mas nao saem de graca. Volte quando juntar um pouco mais de gold.";
		} else{
			A.set_gold(A.get_gold - price_on_potion);
			A.set_life_pot_quantity(get_life_pot_quantity() + 1);
		}

	} else if(item == 2){
		if(A.check_gold() < price_on_potion){
			std::cout << "Pocoes sao realmente baratas, mas nao saem de graca. Volte quando juntar um pouco mais de gold.";
		} else{
			A.set_gold(A.get_gold - price_on_potion);
			A.set_stamina_pot_quantity(geT_stamina_pot_quantity() + 1);
		}
	}
}

void store_weapon(Personagem &A){
	std::ifstream file;
	file.open("../TESTES_TP5.5/weapons.txt"); // Fase de teste: especificar diretório do arquivo ao utilizar essa função

	std::vector<Arma> weapons;

	std::string line, field, ss, _name;
	int _id, _attack, _price;

// Criando as armas a partir dos parametros do .txt
	while (getline(file, line)){
		std::stringstream ss(line);
		getline(ss, field, ',');
		_id = stoi(field);
		getline(ss, _name, ',');
		getline(ss, field, ',');
		_attack = stoi(field);
		getline(ss, field, ',');
		_price = stoi(field);
 
	weapons.push_back(Arma(_id, _name, _attack, _price)); 
	}

// Mostrando as armas criadas
	int i = 0;
	for(i=0; i<weapons.size(); i++){
		weapons[i].display_weapon();
	}

// Recebendo compra ou cancelamento
	instruction_store(A);
	buy_weapon(A, weapons);
}

void store_armor(Personagem &A){
	std::ifstream file;
	file.open("../TESTES_TP5.5/armor.txt"); // Fase de teste: especificar diretório do arquivo ao utilizar essa função

	std::vector<Armadura> armors; 
	std::string line, field, ss, _name;
	int _id, _defense, _price;

	while (getline(file, line)){
		std::stringstream ss(line);
		getline(ss, field, ',');
		_id = stoi(field);
		getline(ss, _name, ',');
		getline(ss, field, ',');
		_defense = stoi(field);
		getline(ss, field, ',');
		_price = stoi(field);
 
		armors.push_back(Armadura(_id, _name, _defense, _price)); // Cria as armaduras a partir dos parametros do .txt
	}

	int i = 0;
	for(i=0; i<armors.size(); i++){ // Mostra as armas
		armors[i].display_armor();
	}

	instruction_store(A);
	buy_armor(A, armors);
}

void store_potions(Personagem &A){
	const int price_on_potion = 10;
	const int life_potion_effectivity = A.get_life_on_pot();
	const int stamina_potion_effectivity = A.get_stamina_on_pot();
	std::string string1 = "Id: 1 - Pocao de vida (" + std::to_string(life_potion_effectivity) + ")";
	std::string string2 = "Preco: " + std::to_string(price_on_potion());
	std::string string3 = "Id: 2 - Pocao de stamina(" + std::to_string(stamina_potion_effectivity) + ")";
	std::string string4 = "Preco: " + std::to_string(price_on_potion());
	print_square(string1, string2, string3, string4);

	instruction_store(A);
	buy_potion(A, price_on_potion);
	
}

void Funcao_Loja(Personagem &A){
	int escolha = 0;
	present_store();
	menu_store();
	checker(&escolha, 1, 4);
		
		while(escolha >= 1 && escolha <= 4){

			if(escolha == 1){
				std::cout << "\n-Vendedor:Escolha sabiamente sua arma:" << std::endl;
				store_weapon(A);
				
				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 4);

			} else if(escolha == 2){
				std::cout << "\n-Vendedor:Escolha sabiamente sua armadura:" << std::endl;
				store_armor(A);

				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 4);

			} else if(escolha == 3){
				std::cout << "\n-Vendedor: Pocoes sao otimas para recuperar sua vida e stamina, mas te deixam meio bebado, use com moderacao: " << std::endl;
				store_potions(A);

				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 4);

			} else if(escolha == 4){
				std::cout << "-Vendedor: Esses jovens..." << std::endl;
				return;
			}
		}
}

