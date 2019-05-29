#ifndef BOSS_H
#define BOSS_H

#include "mob.h"
#include "Habilidade.h"
#include <string>
//#include "armadura.h"


class Boss : public Mob{
	private:
		std::string name;
		float max_attack;
		float min_attack;
		float defense;
		float life;
		Habilidade skill;
		//Armadura armor;
		
	public:
		Boss(std::string, float, float, float, float);
		virtual float get_max_attack() override;
		virtual float get_min_attack() override;
		virtual float get_defense() override;
		virtual std::string get_name() override;
		virtual float get_life() override;
		//Armadura get_armor();
		int get_hdamage();
		int get_hspend();


		virtual void set_max_attack(float) override;
		virtual void set_min_attack(float) override;
		virtual void set_defense(float) override;
		virtual void set_life(float) override;	
		void set_skill(Habilidade);
		//void set_armor(Armadura &);

};

#endif