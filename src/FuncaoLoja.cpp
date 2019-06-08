#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <time.h>

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
	std::cout << "1 - Armas\n" << "2 - Armaduras\n" << "3 - Pocoes\n" << "4- Vender seus itens\n" << "5 - Sair" << std::endl;
	std::cout << "Sua escolha: " << std::endl;
}

void seller_random_fail_speech(){
	srand (time(NULL));
	int fala = rand() % 3;
		switch(fala){
			case 0: std::cout << "-Vendedor: Nao tente me enganar jovem aventureiro, voce nao tem dinheiro para comprar algo tao bom. Vou te dar mais uma chance, escolha outro item: " << std::endl; break;
			case 1: std::cout << "-Vendedor: Ora ora, parece que alguem esta tentando me enganar. Pare de brincadeiras e escolha algo a seu alcance: " << std::endl; break;
			case 2: std::cout << "-Vendedor: Vai ter que se contentar com algo mais barato. Escolha novamente: " << std::endl; break;
		}
}

void confirmation_checkout(){
	std::cout << "Voce tem certeza que quer vender esse item?" << std::endl;
	std::cout << "1 - Sim\n2 - Nao" << std::endl;
	std::cout << "Sua escolha: " << std::endl;
}

void instruction_store(Personagem A){
	std::cout << "Digite o ID do item para comprar ou 0 para voltar." << std::endl;
	std::cout << "Voce tem " << std::to_string(A.get_gold()) << " moedas." << std::endl;
}

void instruction_store_sell(){
	std::cout << "Digite o ID do item para vender ou 0 para voltar." << std::endl;
}

void remaining_gold(Personagem A){
	if(A.get_gold() > 0){
		std::cout << "\n-Vendedor: Me disseram que voce ainda tem "<< A.get_gold() << " moedas. Deseja comprar mais alguma coisa?" << std::endl;
	} else {
		std::cout << "-Vendedor: Me parece que voce esta sem moedas, mas eu posso lhe deixar ver a loja novamente..." << std::endl;
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
		seller_random_fail_speech();
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
		seller_random_fail_speech();
		buy_armor(A, armors);
	}
}

void buy_potion(Personagem &A, int price_on_potion){
	int item = -1;
	checker(&item,0,2);     

	if(item == 0){
		return;

	} else if(item == 1){
		if(A.check_gold(price_on_potion)){
			A.set_gold(A.get_gold() - price_on_potion);
			A.set_life_pot_quantity(A.get_life_pot_quantity() + 1);
		} else{
			std::cout << "-Vendedor: Pocoes sao realmente baratas, mas nao saem de graca. Volte quando juntar mais moedas." << std::endl;
			
		}

	} else if(item == 2){
		if(A.check_gold(price_on_potion)){
			A.set_gold(A.get_gold() - price_on_potion);
			A.set_stamina_pot_quantity(A.get_stamina_pot_quantity() + 1);
		} else{
			std::cout << "-Vendedor: Pocoes sao realmente baratas, mas nao saem de graca. Volte quando juntar mais moedas." << std::endl;
		}
	}
}

void sell_armor(Personagem &A, std::vector<Armadura> inventory_armor){
	int item = -1;
	int confirmation = -1;
	int expected_maximum_id = 1000;
	checker(&item, 0, expected_maximum_id);

	if(item == 0){
		return;
	}

	if(A.armor_inventory_position(item) != -1){

		confirmation_checkout();
		checker(&confirmation, 1, 2);
		if(confirmation == 1){
			A.set_gold(A.get_gold() + inventory_armor[A.armor_inventory_position(item)].get_price());
			A.remove_armor(item);
			std::cout << "-Vendedor: Aqui estao suas " << inventory_armor[A.armor_inventory_position(item)].get_price() << " moedas.";
		} else{
			std::cout << "-Vendedor: Eu sou uma piada pra voce?" << std::endl;
		}
	} else{
		std::cout << "Voce nao tem este item no inventario. Tente novamente!" << std::endl;
		instruction_store_sell();
		sell_armor(A, inventory_armor);
	}
}

void sell_weapon(Personagem &A, std::vector<Arma> inventory_weapon){
	int item = -1;
	int confirmation = -1;
	int expected_maximum_id = 1000;
	checker(&item, 0, expected_maximum_id);

	if(item == 0){
		return;
	}

	if(A.weapon_inventory_position(item) != -1){
		confirmation_checkout();
		checker(&confirmation, 1, 2);
		if(confirmation == 1){
			inventory_weapon[A.weapon_inventory_position(item)].display_weapon();
			A.set_gold(A.get_gold() + inventory_weapon[A.weapon_inventory_position(item)].get_price());
			A.remove_weapon(item);
			std::cout << "-Vendedor: Aqui estao suas " << inventory_weapon[A.weapon_inventory_position(item)].get_price() << " moedas";
		} else{
			std::cout << "-Vendedor: Eu sou uma piada pra voce?" << std::endl;
		}
	} else{
		std::cout << "Voce nao tem este item no inventario. Tente novamente!" << std::endl;
		instruction_store_sell();
		sell_weapon(A, inventory_weapon);
	}
}

void store_weapon(Personagem &A){
	std::ifstream file;
	file.open("../src/weapons.txt"); // Fase de teste: especificar diretório do arquivo ao utilizar essa função

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
	file.open("../src/armor.txt"); // Fase de teste: especificar diretório do arquivo ao utilizar essa função

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
	std::string string2 = "Preco: " + std::to_string(price_on_potion);
	std::string string3 = "Id: 2 - Pocao de stamina(" + std::to_string(stamina_potion_effectivity) + ")";
	std::string string4 = "Preco: " + std::to_string(price_on_potion);
	print_square(string1, string2, string3, string4);

	instruction_store(A);
	buy_potion(A, price_on_potion);
	
}

void store_inventory(Personagem &A){
	std::cout << "-Vendedor: Voce pode vender: \n0 - Sair\n1 - Armaduras\n2 - Armas\n" << std::endl;
	std::cout << "Sua escolha: " << std::endl;

	int i = 0, escolha;
	checker(&escolha, 0, 2);

	if(escolha == 0){
		std::cout << "-Vendedor: Mas ja mudou de ideia? Esses jovens..." << std::endl;
		return;

	} else if(escolha == 1){
		std::vector<Armadura> inventory_armor = A.get_inventory_armor();

		if(inventory_armor.size() <= 0){
			std::cout << "Voce nao tem armaduras para vender..." << std::endl;
		} else{
			for(i=0; i<inventory_armor.size(); i++){
				inventory_armor[i].set_price(inventory_armor[i].get_price() * 0.50);
				inventory_armor[i].display_armor();
			}
			instruction_store_sell();
			sell_armor(A, inventory_armor);
		}
		
	} else if(escolha == 2){
		std::vector<Arma> inventory_weapon = A.get_inventory_weapon();

		if(inventory_weapon.size() <= 0){
			std::cout << "Voce nao tem armas para vender..." << std::endl;
		} else{
			for(i=0; i<inventory_weapon.size(); i++){
				inventory_weapon[i].set_price(inventory_weapon[i].get_price() * 0.50);
				inventory_weapon[i].display_weapon();
			}
			instruction_store_sell();
			sell_weapon(A, inventory_weapon);
		}
		
	}
}

void Funcao_Loja(Personagem &A){
	int escolha = 0;
	present_store();
	menu_store();
	checker(&escolha, 1, 5);
		
		while(escolha >= 1 && escolha <= 5){

			if(escolha == 1){
				std::cout << "\n-Vendedor:Escolha sabiamente sua arma:" << std::endl;
				store_weapon(A);
				
				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 5);

			} else if(escolha == 2){
				std::cout << "\n-Vendedor:Escolha sabiamente sua armadura:" << std::endl;
				store_armor(A);

				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 5);

			} else if(escolha == 3){
				std::cout << "\n-Vendedor: Pocoes sao otimas para recuperar sua vida e stamina, mas te deixam meio bebado, use com moderacao: " << std::endl;
				store_potions(A);

				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 5);

			} else if(escolha == 4){
				std::cout << "-Vendedor: Eu estou sempre comprando itens de aventureiros como voce..." << std::endl;
				store_inventory(A);

				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 5);

			} else if(escolha == 5){
				std::cout << "-Vendedor: Esses jovens..." << std::endl;
				return;
			}
		}
}

