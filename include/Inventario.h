#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Pocao.h"
#include "Arma.h"
#include "Armadura.h"
#include <vector>

class Inventario{
	protected:
    int gold;
   	Pocao life_pot;
   	Pocao stamina_pot;
   	std::vector<Armadura> unused_armor;
    std::vector<Arma> unused_weapons;
   
	public:
		Inventario();

		int get_life();
		int get_stamina();
		int get_life_quantity();
		int get_stamina_quantity();
		void set_life_quantity(int num);
		void set_stamina_quantity(int num);
		int get_gold();
		void set_gold(int num);

		void add_armor(Armadura A);
		void add_weapon(Arma A);
		int armor_inventory_position(int id);
		int weapon_inventory_position(int id);
		void remove_armor(int id);
		void remove_weapon(int id);
		std::vector<Armadura> get_full_unused_armor();
		std::vector<Arma> get_full_unused_weapon();
			
		void display_inventory();
		Armadura get_x_armor(int num);
		Arma get_x_weapon(int num);
};

#endif // INVENTARIO_H

