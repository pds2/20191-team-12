#ifndef FUNCAO_LOJA_H
#define FUNCAO_LOJA_H

#include <vector>
#include <fstream>
#include "Personagem.h"
#include "Arma.h"
#include "Armadura.h"

// Funções de texto
void present_store();
void menu_store();
void seller_random_fail_speech();
void confirmation_checkout();
void instruction_store(Personagem A);
void remaining_gold(Personagem A);

// Função de acesso
void reading_file(std::ifstream &file,  std::vector<std::string> &archives_name, std::vector<int> &archives_id, std::vector<int> &archives_price, std::vector<int> &archives_attribute);
std::vector<Arma> create_objects_weapon();
std::vector<Armadura> create_objects_armor();

// Funções de compra
void buy_weapon(Personagem &A, std::vector<Arma> &weapons);
void buy_armor(Personagem &A, std::vector<Armadura> &armors);
void buy_potions(Personagem &A, int price_on_potions);
void sell_armor(Personagem &A, std::vector<Armadura> inventory_armor);
void sell_weapon(Personagem &A, std::vector<Arma> inventory_weapon);

// Menus específicos
void store_weapon(Personagem &A);
void store_armor(Personagem &A);
void store_potions(Personagem &A);
void store_inventory(Personagem &A);


// Funcão Principal;
void Funcao_Loja(Personagem &A);

#endif

