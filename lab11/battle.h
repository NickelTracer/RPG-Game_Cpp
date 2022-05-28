#pragma once
#ifndef BATTLE_H
#define BATTLE_H

#include <random>
#include <thread>

//node structure
struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = NULL;
	}

	//Add new element at the end of the list
	void push_back(int newElement) {
		Node* newNode = new Node();
		newNode->data = newElement;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			newNode->next = head;
		}
		else{
			Node* temp = head;

			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
		}
	}

	//Delete first node of the list
	void pop_front() {
		if (head != NULL) {
			if (head->next == head) {
				head = NULL;
			}
			else {
				Node* temp = head;
				Node* firstNode = head;

				while (temp->next != head) {
					temp = temp->next;
				}
				head = head->next;
				temp->next = head;
				free(firstNode);
			}
		}
	}

	//display the content of the list
	void PrintList() {
		int cnt1 = 1;
		Node* temp = head;
		if (temp != NULL) {
			cout << "Last battles results: \n";

			while (true) {
				if (temp->data == 1) {
					cout <<cnt1<< ".Win\t";
					if (cnt1 == 5) cout << "\n";
				}
				if (temp->data == 0) {
					cout << cnt1 << ".Lost\t";
					if (cnt1 == 5) cout << "\n";
				}

				cnt1++;
				temp = temp->next;
				if (temp == head) {
					break;
				}
			}
			cout << endl;
		}
		else {
			cout << "The list is empty\n";
		}
	}
};

//template class of battle simulator
template <class T>
class Battle: public Hero, public Monsters {
	T var;

public:
	Battle(){}

	void display(Hero& character, Monsters monster[], int& k, int& cap);
	void battle(LinkedList& results, Hero& character, Monsters monster[], int& k, Items eq[], int& attack_arr, static int& win_lottery);
	void leveling(Hero& character, int& cap, int& free_points);
};

//battle simulator
//stats of hero and monster
template <class T>
void Battle<T>::display(Hero& character, Monsters monster[], int& k, int& cap) {

	cout << "Level of " << character.name << ": " << character.level;
	cout << "\nXP: " << character.exp << "/" << cap << endl;

	cout << "\nStrength: " << character.strength << "\t\t\tAttack: " << character.Attack;
	cout << "\nDexterity: " << character.dexterity << "\t\t\tDamage Reduction: " << character.Damage_reduction;
	cout << "\nEndurance: " << character.endurance << "\t\t\tHP: " << character.HP;
	cout << "\nIntelligence: " << character.intelligence << "\t\t\tMagic Attack: " << character.Magic_attack;
	cout << "\nCharisma: " << character.charisma << "\t\t\tCritical Attack: " << character.Critical_attack << endl << endl;

	cout << "________________________________________________________________" << endl << endl;

	cout << "Your enemy is: " << monster[k].monster_name[k] << endl << endl;
	cout << "Strength: " << monster[k].strength << "\t\t\tAttack: " << monster[k].Attack_m << endl;
	cout << "Dexterity: " << monster[k].dexterity << "\t\t\tDamage Reduction: " << monster[k].Damage_reduction_m << endl;
	cout << "Endurance: " << monster[k].endurance << "\t\t\tHP: " << monster[k].HP_m << endl;
	cout << "Intelligence: " << monster[k].intelligence << "\t\t\tMagic Attack: " << monster[k].Magic_attack_m << endl;
	cout << "Charisma: " << monster[k].charisma << "\t\t\tCritical Attack: " << monster[k].Critical_attack_m << endl;
}

//battle simulator
template<class T>
void Battle<T>::battle(LinkedList& results, Hero& character, Monsters monster[], int& k, Items eq[], int& attack_arr, static int& win_lottery) {
	int attack_type;
	int win;
	static int cnt = 0;

	int a = 0;
	int attacks_arr[2] = { monster[k].Attack_m, monster[k].Magic_attack_m };

	//hero attack, choose between physical and magical attack
	while (character.HP > 0 && monster[k].HP_m > 0) {
		srand((unsigned int)time(NULL));
		int Critical = (rand() % 2) * character.Critical_attack;
		int Critical_m = (rand() % 2) * monster[k].Critical_attack_m;

		int bonus_sword_attack = character.sword_damage[attack_arr];
		int bonus_staff_attack = character.staff_damage[attack_arr];
		int bonus_defence = character.armor_stats[attack_arr];

		//attack type
		cout << endl << "YOUR TURN" << endl << "1. Physical Attack" << endl << "2. Magical Attack" << endl << "3. Use HP potion (miss your turn)" << endl;
		while (!(cin >> attack_type) || attack_type > 3 || attack_type < 1 || (attack_type == 3 && character.hp_potion_q == 0)) {
			if (character.hp_potion_q == 0) {
				cout << "No more HP potions!";
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	
			cout << " Try again!" << endl << endl;
		}

		cout << endl << endl;
		
		//physical attack
		if (attack_type == 1) {
			cout << "_____________________________" << endl;
			if (Critical > 0) {
				cout << "Critical Attack!" << endl;
			}
			cout << "You deal " << character.Attack + Critical << " damage!"<<endl;
			monster[k].HP_m = (monster[k].HP_m + monster[k].Damage_reduction_m) - (character.Attack + Critical + bonus_sword_attack);
			cout << "Monster damage reduction: " << monster[k].Damage_reduction_m << endl;
			cout << monster[k].monster_name[k] << "s HP left: " << monster[k].HP_m << endl;
			cout << "Bonus attack: " << bonus_sword_attack << endl;
			cout << "_____________________________" << endl;
		}

		//magical attack
		else if (attack_type == 2) {
			cout << "_____________________________" << endl;
			if (Critical > 0) {
				cout << "Critical Attack!" << endl;
			}
			cout << "You deal " << character.Magic_attack + Critical << " damage!" << endl;
			monster[k].HP_m = (monster[k].HP_m + monster[k].Damage_reduction_m) - (character.Magic_attack + Critical + bonus_staff_attack);
			cout << "Monster damage reduction: " << monster[k].Damage_reduction_m << endl;
			cout << monster[k].monster_name[k] << "s HP left: " << monster[k].HP_m << endl;
			cout << "Bonus attack: " << bonus_staff_attack << endl;
			cout << "_____________________________" << endl;
		}

		//use HP potion
		else if (attack_type == 3 && character.hp_potion_q > 0) {
			cout << "_____________________________" << endl;
			character.HP = character.HP + character.hp_potion_amount;
			character.hp_potion_q--;

			cout << endl << character.name << " uses HP potion!" << endl << "HP left: " << character.HP << " (+" << character.hp_potion_amount << ")";
			cout << endl << "HP potions left: " << character.hp_potion_q << endl;
			cout << "_____________________________" << endl;
		}

		//in case if monster hp = 0 --> Win condition
		if (monster[k].HP_m <= 0) {
			cout << endl << endl << endl << endl << "\t\t\t\tYou won!" ;
			cout << endl << "\t\t\t\tExperience gained: 450" << endl << endl << endl << endl;
			character.exp = character.exp + 450;

			//list of 10 last battles
			win = 1;
			cnt++;
			if (cnt > 10) {
				results.pop_front();
			}
			results.push_back(win);
			results.PrintList();

			//win item lottery
			srand((unsigned int)time(NULL));
			win_lottery = rand() % 4;

			break;
		}
		//monster attack, random physical and magical attack
		else {
			
			//delay
			this_thread::sleep_for(chrono::seconds(0));
			cout << endl << endl << "OPPONENT TURN" << endl << "_____________________________" << endl;

			if (Critical_m > 0) {
				cout << "Critical Attack!" << endl;
			}
			character.HP = (character.HP + character.Damage_reduction + bonus_defence) - (attacks_arr[a] + Critical_m);
			cout << monster[k].monster_name[k] << " dealt " << attacks_arr[a] << " damage!" << endl;
			cout << "Player damage reduction: " << character.Damage_reduction << endl;
			cout << character.name << "s HP left: " << character.HP << endl;
			cout << "Bonus defence: " << bonus_defence << endl;
			cout << "_____________________________" << endl;
			a++;
		}

		//in case if hero hp = 0 --> Fail condition
		if (character.HP <= 0) {
			cout <<endl<<endl<<endl<<endl<< "\t\t\t\tYou died!";
			cout << endl << "\t\t\t\tExperience lost: 375" << endl << endl << endl << endl;
			//experience distribution
			character.exp = character.exp - 375;

			if (character.exp <= 0) {
				character.exp = 0;
			}
			
			//list of 10 last battles
			win = 0;
			cnt++;
			if (cnt > 10) {
				results.pop_front();
			}

			results.push_back(win);
			results.PrintList();

			//win item lottery
			srand((unsigned int)time(NULL));
			win_lottery = rand() % 8;

			break;
		}

		//for monster random attacks
		if (a == 2) {
			a = 0;
		}
	}
}

//leveling
template<class T>
void Battle<T>::leveling(Hero& character, int& cap, int& free_points) {
	int rest;
	if (character.exp >= cap) {
		cout << endl << endl << "Level up!" << endl << endl;

		rest = character.exp - cap;
		character.exp = rest;
		character.level++;
		cap = cap + 625;
		free_points++;
		cout << "Skill points avaiable: " << free_points << endl;
	}
}
#endif