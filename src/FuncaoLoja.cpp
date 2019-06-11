#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <math.h>

#include "Inventario.h"
#include "Personagem.h"
#include "Arma.h"
#include "Armadura.h"
#include "FuncoesGerais.h"
#include "FuncaoLoja.h"
#include <vector>

// Funcoes de texto

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

// Função de acesso

void reading_file(std::ifstream &file,  std::vector<std::string> &archives_name, std::vector<int> &archives_id, std::vector<int> &archives_price, std::vector<int> &archives_attribute){

std::string line, field, ss, _name;
int _id, _attribute, _price;

	while (getline(file, line)){
		std::stringstream ss(line);
		getline(ss, field, ',');
		_id = stoi(field);
		getline(ss, _name, ',');
		getline(ss, field, ',');
		_attribute = stoi(field);
		getline(ss, field, ',');
		_price = stoi(field);

		archives_name.push_back(_name);
		archives_id.push_back(_id);
		archives_attribute.push_back(_attribute);
		archives_price.push_back(_price);
	}
}

std::vector<Arma> create_objects_weapon(){
	std::vector<std::string> archives_name;
	std::vector<int> archives_id;
	std::vector<int> archives_price;
	std::vector<int> archives_attribute;

	std::ifstream file;
    file.open("../20191-team-12/Files/weapons.txt");
	reading_file(file, archives_name, archives_id, archives_price, archives_attribute);

	std::vector<Arma> weapon_store_vector;
	for(int i= 0; i < archives_id.size(); ++i){
		weapon_store_vector.push_back(Arma(archives_id[i], archives_name[i], archives_attribute[i], archives_price[i]));
	}

	file.close();
	return weapon_store_vector;    
}

std::vector<Armadura> create_objects_armor(){
	std::vector<std::string> archives_name;
	std::vector<int> archives_id;
	std::vector<int> archives_price;
	std::vector<int> archives_attribute;

	std::ifstream file;
	file.open("../20191-team-12/Files/armor.txt");
	reading_file(file, archives_name, archives_id, archives_price, archives_attribute);

	std::vector<Armadura> armor_store_vector;
	for(int i= 0; i < archives_id.size(); ++i){
		armor_store_vector.push_back(Armadura(archives_id[i], archives_name[i], archives_attribute[i], archives_price[i]));
	}
	return armor_store_vector;
}

// Funções de compra e venda

void buy_weapon(Personagem &A, std::vector<Arma> &weapons){
	int buy_id = -1;

	checker(&buy_id, 0, (weapons.back()).get_id());
	if(buy_id == 0){
		return;
	}

	int i = 0;
	while(buy_id != weapons[i].get_id()){
		i++;
	}

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

	int i = 0;
	while(buy_id != armors[i].get_id()){
		i++;
	}

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
	int base_size = 50;
	int item = -1;
	checker(&item,0,4);   

	if(item == 0){
		return;
	}

	if(item == 1){
		int potion_size = 50;
		int real_price = price_on_potion * (potion_size/base_size);

		if(A.check_gold(real_price)){
			A.set_gold(A.get_gold() - real_price);
			A.set_life(A.get_life() + potion_size);
			std::cout << "Sua nova vida eh " << A.get_life() << std::endl;
		} else{
			std::cout << "-Vendedor: Pocoes sao realmente baratas, mas nao saem de graca. Volte quando juntar mais moedas." << std::endl;
		}

	} else if(item == 2){
		int potion_size = 50;
		int real_price = price_on_potion * (potion_size/base_size);
		if(A.check_gold(real_price)){
			A.set_gold(A.get_gold() - real_price);
			A.set_stamina(A.get_stamina() + potion_size);
			std::cout << "Sua nova stamina eh " << A.get_stamina() << std::endl;
		} else{
			std::cout << "-Vendedor: Pocoes sao realmente baratas, mas nao saem de graca. Volte quando juntar mais moedas." << std::endl;
		}

	} else if(item == 3){
		int potion_size = 200;
		int real_price = price_on_potion * (potion_size/base_size);
		if(A.check_gold(real_price)){
			A.set_gold(A.get_gold() - real_price);
			A.set_life(A.get_life() + potion_size);
			std::cout << "Sua nova vida eh " << A.get_life() << std::endl;
		} else{
			std::cout << "-Vendedor: Tente comprar uma pocao menor ou va juntar mais moedas." << std::endl;
		}

	} else if(item == 4){
		int potion_size = 200;
		int real_price = price_on_potion * (potion_size/base_size);
		if(A.check_gold(real_price)){
			A.set_gold(A.get_gold() - real_price);
			A.set_stamina(A.get_stamina() + potion_size);
			std::cout << "Sua nova stamina eh " << A.get_stamina() << std::endl;
		} else{
			std::cout << "-Vendedor: Tente comprar uma pocao menor ou va juntar mais moedas." << std::endl;
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
			std::cout << "-Vendedor: Aqui estao suas " << inventory_armor[A.armor_inventory_position(item)].get_price() << " moedas.";
			A.remove_armor(item);
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
			std::cout << "-Vendedor: Aqui estao suas " << inventory_weapon[A.weapon_inventory_position(item)].get_price() << " moedas";
			A.remove_weapon(item);
		} else{
			std::cout << "-Vendedor: Eu sou uma piada pra voce?" << std::endl;
		}
	} else{
		std::cout << "Voce nao tem este item no inventario. Tente novamente!" << std::endl;
		instruction_store_sell();
		sell_weapon(A, inventory_weapon);
	}
}

// Menus Específicos

void store_weapon(Personagem &A){
	int i = 0;

	std::vector<Arma> weapons = create_objects_weapon();
	for(i=0; i<weapons.size(); i++){
		weapons[i].display_weapon();
	}
	instruction_store(A);
	buy_weapon(A, weapons);
}

void store_armor(Personagem &A){
	int i = 0;

	std::vector<Armadura> armors = create_objects_armor();
	for(i=0; i<armors.size(); i++){ // Mostra as armas
		armors[i].display_armor();
	}

	instruction_store(A);
	buy_armor(A, armors);
}

void store_potions(Personagem &A){
	int price_on_potion = 15;
	int x_times_bigger_size = 4;

	std::string string1 = "Id: 1 - Pocao de vida (50)";
	std::string string2 = "Preco: " + std::to_string(price_on_potion);
	std::string string3 = "Id: 2 - Pocao de stamina(50)";
	std::string string4 = "Preco: " + std::to_string(price_on_potion);
	print_square(string1, string2, string3, string4);

	std::string string5 = "Id: 3 - Pocao de vida(200)";
	std::string string6 = "Preco: " + std::to_string(price_on_potion * x_times_bigger_size);
	std::string string7 = "Id: 4 - Pocao de stamina(200)";
	std::string string8 = "Preco: " + std::to_string(price_on_potion * x_times_bigger_size);
	print_square(string5, string6, string7, string8);

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
				std::cout << "\n-Vendedor: Eu estou sempre comprando itens de aventureiros como voce..." << std::endl;
				store_inventory(A);

				remaining_gold(A);
				menu_store();
				checker(&escolha, 1, 5);

			} else if(escolha == 5){
				std::cout << "\n-Vendedor: Esses jovens...\n" << std::endl;
				return;
			}
		}
}

