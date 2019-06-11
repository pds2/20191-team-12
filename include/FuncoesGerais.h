#ifndef FUNCOES_GERAIS_H
#define FUNCOES_GERAIS_H

#include <string>
#include "Personagem.h"
#include "boss.h"
#include "npc.h"

#define n_enemies 3


void pausar();
bool exit_game();
void quiz(int n, Personagem &player);
void add_skill_pers(Personagem &player, int fase);
void add_skill_boss(Boss &boss, int fase);
void checker(int *variavel, int p1, int p2);
std::string adjust_square(std::string to_print, int num);
void print_square(std::string to_print1, std::string to_print2, std::string to_print3, std::string to_print4); // square_size padrão = 35
void exit();
int reward(int fase_num, int multiplicador, Personagem &player);

#endif
