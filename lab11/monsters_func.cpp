#include "hero.h"
#include "monsters.h"

//Display 5 out of 10 random mobs with random stats
void Display_mobs(Monsters monster[]) {

	for (int i = 0; i < 5; i++) {

		cout << "Monster" << i + 1 << ": " << endl;
		cout << "_____________________________" << endl;
		cout << monster[i].monster_name[rand() % 10] << endl;
		cout << "Strength: " << monster[i].strength << "\t\t\tAttack: " << monster[i].Attack_m << endl;
		cout << "Dexterity: " << monster[i].dexterity << "\t\t\tDamage Reduction: " << monster[i].Damage_reduction_m << endl;
		cout << "Endurance: " << monster[i].endurance << "\t\t\tHP: " << monster[i].HP_m << endl;
		cout << "Intelligence: " << monster[i].intelligence << "\t\t\tMagic Attack: " << monster[i].Magic_attack_m << endl;
		cout << "Charisma: " << monster[i].charisma << "\t\t\tCritical Attack: " << monster[i].Magic_attack_m << endl;
		cout << "_____________________________" << endl << endl;
	}
}

//Save randomly generated stats of 5 random mobs
void Monsters_save(Monsters monster[]) {

	ofstream ofs{ ".//Monsters//Monsters_list.txt" };
	auto cout_buff = cout.rdbuf();
	cout.rdbuf(ofs.rdbuf());

	for (int i = 0; i < 5; i++) {
		cout << monster[i].strength << endl << monster[i].dexterity << endl << monster[i].endurance << endl << monster[i].intelligence << endl << monster[i].charisma << endl;
	}
	cout.rdbuf(cout_buff);
}