#ifndef BOSS_H
#define BOSS_H

#include "mob.h"
#include <string>
//#include "armadura.h"
//#include "habilidade.h"

class Boss : public Mob{
	private:
		std::string name;
		float max_attack;
		float min_attack;
		float defense;
		//Armadura armor;
		//Habilidade skill
	public:
		Boss(std::string);
		virtual float get_max_attack()override;
		virtual float get_min_attack()override;
		virtual float get_defense()override;
		virtual std::string get_name()override;
		//Armadura get_armor();
		//Habilidade get_skill();

		virtual void set_max_attack(float)override;
		virtual void set_min_attack(float)override;
		virtual void set_defense(float)override;
		//void set_armor(Armadura &);
		//void set_skill(Habilidade &);
};

#endif