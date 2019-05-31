#ifndef FUNCAO_LOJA_H
#define FUNCAO_LOJA_H

#include <vector>

// Funções de texto
void present_store();
void menu_store();
void instruction_store(Personagem A);
void remaining_gold(Personagem A);

// Função de compra
void buy_weapon(Personagem &A, std::vector<Arma> &weapons);
void buy_armor(Personagem &A, std::vector<Armadura> &armors);


// Menus específicos
void store_weapon(Personagem &A);
void store_armor(Personagem &A);
void store_potions(Personagem &A);

// Funcão Principal;
void Funcao_Loja(Personagem &A);

#endif

