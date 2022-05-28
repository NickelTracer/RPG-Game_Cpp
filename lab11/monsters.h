#pragma once
#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <random>

using namespace std;

/* Class of Monsters interface */
class Monster_interface {
public:
	int HP_m = 0;
	int Attack_m = 0;
	int Critical_attack_m = 0;
	int Damage_reduction_m = 0;
	int Magic_attack_m = 0;

	virtual ~Monster_interface() {};
	virtual void Statistics_m() = 0;
};


//class randomizing statistics
class Monsters : public Monster_interface, public Hero {
public:
	string monster_name[10] = { "Basilisk","Slime","Behemoth","Hydra","Undead","Ghost","Bandit","Werewolf","Spriggan","Fire Elemental" };

	Monsters() {
		srand((unsigned int)time(NULL));
		assign_random_stats();
	}

	void assign_random_stats() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(0, 10);

		this->strength = distr(gen);
		this->dexterity = distr(gen);
		this->endurance = distr(gen);
		this->intelligence = distr(gen);
		this->charisma = distr(gen);
	}

	virtual void Statistics_m() {
		HP_m = 400 + endurance * 4;
		Attack_m = 15 + strength * 4;
		Critical_attack_m = 30 + charisma * 3;
		Damage_reduction_m = 10 + dexterity * 4;
		Magic_attack_m = 20 + intelligence * 5;
	}
};

void Display_mobs(Monsters monster[]);
void Monsters_save(Monsters monster[]);
#endif