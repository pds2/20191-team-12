#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Pocao.h"
//#include "Arma.h"
//#include "Armadura.h"

class Inventario{
protected:
    int gold;
   	Pocao life_pot;
   	Pocao stamina_pot;
    //std::vector<Arma> unused_weapons;
    //std::vector<Armadura> unused_armor;
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
};

#endif // INVENTARIO_H

