#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Arma.h"
#include "Armadura.h"
#include <vector>

class Inventario{
	private:
    int gold;
   	std::vector<Armadura> unused_armor;
    std::vector<Arma> unused_weapons;
   
	public:
		Inventario();

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
};

#endif // INVENTARIO_H

