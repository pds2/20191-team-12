#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include<string>

#include "Inventario.h"//
//#include "Armadura.h"
//#include "Arma.h"


class Personagem{
    private:
        std::string object_name;
        int life;
        int deffense;
        int attack;
        int stamina; 
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

	  	void use_life_potion();
	    void use_stamina_potion();
	    int get_life_pot_quantity();
	    int get_stamina_pot_quantity();
	    void set_life_pot_quantity(int num);
	    void set_stamina_pot_quantity(int num);

	    int get_gold();
	    void set_gold(int num);
/*
      void equip_armor(Armadura toequip);
      void unequip_armor();
      void equip_weapon(Arma toequip);
      void unequip_weapon();

      void apply_armor_stats();
      void apply_weapon_stats();
*/
};

#endif // PERSONAGEM_H

