#pragma once
#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <random>
#include "inventory.h"

using namespace std;

/* Class of Hero interface */
class Hero_interface {
public:
	int HP = 0;
	int Attack = 0;
	int Critical_attack = 0;
	int Damage_reduction = 0;
	int Magic_attack = 0;

	virtual ~Hero_interface() {};
	virtual void Statistics() = 0;
};

/* Class stroring hero stats */
class Hero : public Hero_interface, public Items_stats {
public:
	string name;
	int strength;
	int dexterity;
	int endurance;
	int intelligence;
	int charisma;
	int exp;
	int level;


	friend struct Mage;
	friend struct Warrior;
	friend struct Berserker;
	friend struct Thief;

	friend class Items_stats;

	Hero() {
		this->name = "";
		this->strength = 0;
		this->dexterity = 0;
		this->endurance = 0;
		this->intelligence = 0;
		this->charisma = 0;
		this->exp = 0;
		this->level = 0;
	}

	Hero(string name, int strength, int dexterity, int endurance, int intelligence, int charisma, int exp, int level) {
		this->name = name;
		this->strength = strength;
		this->dexterity = dexterity;
		this->endurance = endurance;
		this->intelligence = intelligence;
		this->charisma = charisma;
		this->exp = exp;
		this->level = level;
	}

	virtual void Statistics()override {
		HP = 500 + endurance * 4;
		Attack = 20 + strength * 5;
		Critical_attack = 40 + charisma * 4;
		Damage_reduction = 15 + dexterity * 5;
		Magic_attack = 25 + intelligence * 6;
	}
};

struct Mage {
	void add_boost(Hero& character) {
		int bonus = 2;
		character.intelligence += bonus;
	}
};
struct Warrior {
	void add_boost(Hero& character) {
		int bonus = 2;
		character.endurance += bonus;
	}
};
struct Berserker {
	void add_boost(Hero& character) {
		int bonus = 2;
		character.strength += bonus;
	}
};
struct Thief {
	void add_boost(Hero& character) {
		int bonus = 2;
		character.dexterity += bonus;
	}
};



void Create_character(Hero& character, int& free_points, int& proceed, int& prof, Mage& mage, Warrior& warrior, Berserker& berserker, Thief& thief, int& attack_arr);
void Points(Hero& character, int& free_points, int& proceed, int& prof, Mage& mage, Warrior& warrior, Berserker& berserker, Thief& thief);
void Character_stats_display(Hero character);
void Character_save(Hero character, int& cap, int& free_points, int& attack_arr);
void Character_load(Hero& character, int& cap, int& free_points, Items eq[], int& attack_arr);

void drop_items(Hero& character, Items eq[], int& attack_arr);
void save_items(Hero& character, Items eq[], int& attack_arr);

void armor(Hero& character, Items eq[], int& attack_arr);
void sword(Hero& character, Items eq[], int& attack_arr);
void staff(Hero& character, Items eq[], int& attack_arr);
void potions(Hero& character, Items eq[], int& attack_arr);

void error_armor(Hero& character, Items eq[], int& attack_arr, int& error);
void error_sword(Hero& character, Items eq[], int& attack_arr, int& error);
void error_staff(Hero& character, Items eq[], int& attack_arr, int& error);
void error_potions(Hero& character, Items eq[], int& attack_arr, int& error);

void search(Hero& character, Items eq[], int arr_size, string& name, int type, int& atttack_arr);
#endif