#ifndef MOB_H
#define MOB_H

#include <string>

class Mob{
	public:
		virtual float get_max_attack() = 0;
		virtual float get_min_attack() = 0;
		virtual float get_defense() = 0;
		//virtual float get_armor() = 0;
		virtual std::string get_name() = 0;
		virtual float get_life() = 0;

		virtual void set_max_attack(float) = 0;
		virtual void set_min_attack(float) = 0;
		virtual void set_defense(float) = 0;
		virtual void set_life(float) = 0;
		//virtual void set_armor() = 0;
};

#endif