#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include<string>

#include "Inventario.h"
//#include "Armadura.h"
//#include "Arma.h"


class Personagem{
    private:
        std::string object_name;
        int life;
        int deffense;
        int attack;
        int stamina; // (ou mana?)
    protected:
        Inventario inventory;
        //Armadura armor;
        //Arma weapon;
    public:
    	Personagem(std::string _obj_name, int _life, int _defense, int _attack, int _stamina);
   	
	std::string get_object_name();
    	void set_object_name(std::string name_change);
    	int get_life();
  	void set_life(int life_change);
  	int get_deffense();
  	void set_deffense(int def_change);
  	int get_attack();
  	void set_attack(int attack_change);
  	int get_stamina();
  	void set_stamina(int stamina_change);

  	Inventario* gip(); // get_inventory_pointer();

	void use_life_potion(Inventario *B);
	void use_stamina_potion(Inventario *B);
	int get_life_pot_quantity(Inventario *B);
	int get_stamina_pot_quantity(Inventario *B);
	void set_life_pot_quantity(Inventario *B, int num1);
	void set_stamina_pot_quantity(Inventario *B, int num1);

	int get_gold1(Inventario *B);
	void set_gold1(Inventario *B, int num1);
};

#endif // PERSONAGEM_H

