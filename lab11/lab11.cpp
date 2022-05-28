#include "hero.h"
#include "monsters.h"
#include "battle.h"
#include "inventory.h"

using namespace std;
bool running = true;




int main() {
	//objects definitions
	Battle<int> Battle_sim;
	Hero character ("none", 0, 0, 0, 0, 0, 0, 1);

	Mage mage;
	Warrior warrior;
	Berserker berserker;
	Thief thief;

	Monsters monster1, monster2, monster3, monster4, monster5, monster6, monster7, monster8, monster9, monster10;
	Monsters monster[10] = { monster1, monster2, monster3, monster4, monster5, monster6, monster7, monster8, monster9, monster10 };

	Items eq1, eq2, eq3, eq4, eq5;
	Items eq[5] = { eq1,eq2,eq3,eq4,eq5 };

	LinkedList results;
	int attack_arr = 5;
	
	//assigning stats to 10 monsters
	for (int i = 0; i < 10; i++) {
		monster[i].Statistics_m();
	}

	//sorted cin's
	union {
		int choice;
		int choice1;
		int choice2; 
		int choice3;
		int choice4;
		int choice5;
	};

	//variables
	int free_points = 0;
	int proceed;
	int prof;
	int k = rand() % 10;
	int cap = 500;
	int test= 0;
	static int win_lottery = 0;
	int error = 0;
	

	cout << "_____________________________" << endl;
	cout << "Welcome to RPG Game!"<<endl;

	while (running) {

		//randomizing monsters stats
		if (k == 10) {
			k = 0;
			for (int i = 0; i < 10; i++) {
				monster[i].assign_random_stats();
				monster[i].Statistics_m();
			}
		}
		for (int i = 0; i < 10; i++) {
			monster[i].assign_random_stats();
			monster[i].Statistics_m();
		}
		//main UI
		cout << "_____________________________" << endl;
		cout << "1. Fight!" << endl << "2. Level up character" << endl << "3. Create character" << endl << "4. Save character" << endl << "5. Load character" << endl << "6. Inventory" << endl << "7. Bestiary" << endl << "8. Exit game" << endl;
		cout << "_____________________________" << endl;
		//cin >> choice;
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Illegal name used. Type integer again!" << endl << endl;
		}


		switch (choice) {

		//character creation
		case 3:
			Create_character(character, free_points, proceed, prof, mage, warrior, berserker, thief, attack_arr);
			Points(character, free_points, proceed, prof, mage, warrior, berserker, thief);

			if (proceed == 1) {
				character.Statistics();
				Character_stats_display(character);

				cout << endl << endl << "_____________________________" << endl;
				cout <<  "Do you wish to save your character?" << endl;
				cout << "_____________________________" << endl;
				cin >> choice1;
				if (choice1 == 1) {
					Character_save(character, cap, free_points, attack_arr);
				}

			}
			else if (proceed == 0) {
				character.strength = 0;
				character.dexterity = 0;
				character.endurance = 0;
				character.intelligence = 0;
				character.charisma = 0;
				character.name = "none";
			}
			break;

		//character save
		case 4:
			Character_save(character, cap, free_points, attack_arr);
			
			break;

		//character load
		case 5:
			Character_load(character, cap, free_points, eq, attack_arr);
			break;

		//dispaly mobs and save 10 of them to .txt
		case 7:
			Display_mobs(monster);

			cout << "Do you wish to save your monsters list?" << endl;
			cin >> choice2;

			if (choice2 == 1) {
				Monsters_save(monster);
			}
			break;
		
		//exit game
		case 8:
			exit(1);
			break;

		//battle
		case 1:
			//statement if no character selected. Deafult name is 'none'
			if (character.name == "none") {
				cout << endl << "Select your character first!" << endl;
				break;
			}

			character.Statistics();
			Battle_sim.display(character,monster,k,cap);

			//Battle simulator
			cout << "_____________________________" << endl << endl;
			cout << "1. Attack!" << endl << "2. Flee!" << endl;
			cout << "_____________________________" << endl;

			//if anything else than int typed
			while (!(cin >> choice3) || choice3 > 2 || choice3 < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error! Try again..." << endl << endl;
				break;
			}

			//flee
			if (choice3 == 2) {
				k++;
			}

			//fight and leveling
			else if (choice3 == 1) {
				Battle_sim.battle(results, character, monster, k, eq, attack_arr, win_lottery);
				Battle_sim.leveling(character, cap, free_points);
				save_items(character, eq, attack_arr);
				k++;
				if (win_lottery == 3) {
					cout << endl << "You found chest! Do you wish to open it?" << endl;
					while (!(cin >> choice4) || choice4 > 1 || choice4 < 0) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Error! Try again..." << endl << endl;
					}
					if (choice4 == 1) {
						srand((unsigned int)time(NULL));
						attack_arr = rand() % 5;
						drop_items(character, eq, attack_arr);
					}
					else if(choice4 == 0) { break; }
				}
				else if (win_lottery == 2 || win_lottery == 1) {
					cout << endl << "You found HP potion!" << endl;
					character.hp_potion_q++;
					cout << endl << "HP potions amount: " << character.hp_potion_q << endl;
				}
			}

			break;

		//leveling interface
		case 2:
			if (free_points == 0) {
				cout << "No free points avaiable!" << endl;
			}
			Points(character, free_points, proceed, prof, mage, warrior, berserker, thief);
			break;

		//inventory
		case 6:
			if (character.name == "none") {
				cout << "Select you character first!" << endl << endl;
				break;
			}
			cout << endl << endl << endl << "1. Armor" << "\n2. Sword" << "\n3. Staff" << "\n4. Potions" << "\n5. Search Yourself" << endl;
			while (!(cin >> choice5) || choice5 > 5 || choice5 < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error! Try again..." << endl << endl;
			}

			if (choice5 == 1) {
				error_armor(character, eq, attack_arr, error);
				if (error != 1) armor(character, eq, attack_arr);
			}
			else if (choice5 == 2) {
				error_sword(character, eq, attack_arr, error);
				if (error != 1) sword(character, eq, attack_arr);
			}
			else if (choice5 == 3) {
				error_staff(character, eq, attack_arr, error);
				if (error != 1) staff(character, eq, attack_arr);
			}
			else if (choice5 == 4) {
				error_potions(character, eq, attack_arr, error);
				if (error != 1) potions(character, eq, attack_arr);
			}
			else if (choice5 == 5) {
				int arr_size = 0;
				string name;
				int type;

				cout << "Enter items type: 1.armor 2.sword 3.staff " << endl;
				while (!(cin >> type) || type > 3 || type < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Error! Try again..." << endl << endl;
				}

				cout << "Enter Items name: " << endl;
				cin >> name;
				
				search(character, eq, arr_size, name,type, attack_arr);
			}
			break;
		//error statement -> UI restart
		default:
			cout << endl << endl << "Wrong integer entered, try again!" << endl;
			cin.clear();
			break;
		}
	}
	return 0;
}