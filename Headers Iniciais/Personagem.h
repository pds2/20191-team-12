#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include<string>

#include "Inventario.h"
#include "Armadura.h"
#include "Arma.h"


class Personagem{
  private:
    std::string name;
    std::string casa;
    int life;
    int defense;
    int attack;
    int stamina; 
    Inventario inventory; 
    Armadura armor;
    Arma weapon;

  public:
  	//Construtor
    Personagem(std::string _obj_name, std::string _casa, int _life, int _defense, int _attack, int _stamina, Inventario _inventory, Armadura _armor, Arma _weapon);

   	//Acesso Personagem
 		std::string get_name();
  	std::string get_casa();
  	int get_life();
		void set_life(int life_change); // soma, não substitui o valor;
		int get_defense();
		void set_defense(int def_change); // soma, não substitui o valor;
		int get_attack();
		void set_attack(int attack_change); // soma, não substitui o valor;
  	int get_stamina();
  	void set_stamina(int stamina_change); // soma, não substitui o valor;

    //Acesso Pocoes
    int get_life_pot_quantity();
    int get_stamina_pot_quantity();
    void set_life_pot_quantity(int num);
    void set_stamina_pot_quantity(int num);

    // Acesso Inventario
    int get_gold();
	  void set_gold(int num);
	  void display_inventory();

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

    // Funções de uso direto
    void use_life_potion();
	  void use_stamina_potion();
	  void add_armor(Armadura toequip);
    void add_weapon(Arma toequip);
	  void equip_armor(Armadura toequip);
    void unequip_armor();
    void equip_weapon(Arma toequip);
    void unequip_weapon();
   	void display_stats();
};

#endif // PERSONAGEM_H

