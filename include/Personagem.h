#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>

#include "Inventario.h"
#include "Armadura.h"
#include "Arma.h"
#include "Habilidade.h"

class Personagem{
  private:
    std::string name;
    int life;
    int defense;
    int attack;
    int stamina; 
    Inventario inventory; 
    Armadura armor;
    Arma weapon;
    std::vector<Habilidade> skill;

  public:
  	//Construtor
    Personagem(std::string _name);
    Personagem(std::string _name, int _life, int _defense, int _attack, int _stamina);
   	//Acesso Personagem
 	std::string get_name();
  	int get_life();
	void set_life(int life_change); 
	int get_defense();
	void set_defense(int def_change); 
	int get_attack();
	void set_attack(int attack_change);
  	int get_stamina();
  	void set_stamina(int stamina_change); 

    // Acesso Inventario
    int get_gold();
	void set_gold(int num);
	void display_inventory();
    bool check_gold(int price);
    std::vector<Armadura> get_inventory_armor();
    std::vector<Arma> get_inventory_weapon();
    int armor_inventory_position(int id);
    int weapon_inventory_position(int id);

    // Acesso Armadura e Arma
    std::string get_armor_name();
    int get_armor_defense();
    int get_armor_id();
    int get_armor_price();
    void display_armor();
    std::string get_weapon_name();
    int get_weapon_attack();
    int get_weapon_id();
    int get_weapon_price();
    void display_weapon();

    //Acesso a Habilidades
    void add_skill(Habilidade hab);
    void remove_skill(int y);
    void display_skill();
    int get_nskill();
    Habilidade get_skill(int); 

    // Funções de uso direto
	void add_armor(Armadura toequip);
    void add_weapon(Arma toequip);
    void remove_armor(int id);
    void remove_weapon(int id);
    void equip_armor(Armadura toequip);
    void unequip_armor();
    void equip_weapon(Arma toequip);
    void unequip_weapon();
   	void display_stats();
};

#endif // PERSONAGEM_H

