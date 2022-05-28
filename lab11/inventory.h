#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <random>

using namespace std;

class Items_stats {
public:
	int hp_potion_q = 5;
	int sword_damage[6] = { 10,20,30,40,50,0 };
	int staff_damage[6] = { 10,20,30,40,50,0 };
	int armor_stats[6] = { 10,20,30,40,50,0 };
	int hp_potion_amount = 100;

	string sword_name[6] = { "Arm of zombie","Black Sword","Caliper of furious devil","Devils mace","Elegant rapier","Fire katana"};
	string staff_name[6] = { "Staff of Fire","Staff of Frost","Staff of doom","Angels staff","Staff of Lightnings","Legendary Staff" };
	string armor_name[6] = { "Leather armor","Plate armor","Ebony armor","White gold armor","Seraphins armor","Skin of god" };
	string hp_potion = "Health potion";

	virtual ~Items_stats() {};
};

class Items: public Items_stats {
public:
	Items() {
		this->hp_potion_q = 0;
		this->sword_damage[6];
		this->staff_damage[6];
		this->armor_stats[6];
	}

	Items(int hp_potion_q, int sword_damage[], int staff_damage[], int armor_stats[]) {
		this->hp_potion_q = hp_potion_q;
		this->sword_damage[6] = sword_damage[6];
		this->staff_damage[6] = staff_damage[6];
		this->armor_stats[6] = armor_stats[6];
	}
};
	

#endif