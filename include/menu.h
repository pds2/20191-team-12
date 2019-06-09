#ifndef MENU_H
#define MENU_H

#include "FuncoesGerais.h"
#include "FuncaoLoja.h"
#include "Personagem.h"
#include "jogo.h" 
#include "npc.h"
#include "treino.h"

void show_init();

void show_menu(Personagem &heroi, Npc &npc, int t_num, int fase_num);

void show_menu_h();

#endif