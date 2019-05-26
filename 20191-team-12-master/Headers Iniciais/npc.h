#ifndef NPC_H
#define NPC_H

#include "mob.h"
#include <string>

class Npc : public Mob{
	private:
		std::string name;
		float max_attack;
		float min_attack;
		float defense;
		float life;
		//float armor;
	public:
		Npc(std::string, float, float, float);
		Npc(std::string);
		virtual float get_max_attack() override;
		virtual float get_min_attack() override;
		virtual float get_defense() override;
		//virtual float get_armor() override;
		virtual std::string get_name() override;
		virtual float get_life() override;

		virtual void set_max_attack(float) override;
		virtual void set_min_attack(float) override;
		virtual void set_defense(float) override;
		virtual void set_life(float) override;
		//virtual void set_armor(float ) override;
};

#endif