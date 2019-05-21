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
	int get_gold();
	void set_gold();

	int get_pot_life(Pocao *C);
	int get_pot_stamina(Pocao *C);
	int get_pot_quantity2(Pocao *C);
	void set_pot_quantity2(Pocao *C, int num2);
	int get_gold2();
	void set_gold2(int num2);
	Pocao* get_life_pointer();
	Pocao* get_stamina_pointer();
	
};

#endif // INVENTARIO_H

