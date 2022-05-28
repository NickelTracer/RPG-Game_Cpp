#include "hero.h"
#include "inventory.h"


//SAVE CURRENT ITEMS TO TXT
void save_items(Hero& character, Items eq[], int& attack_arr) {
	//save swords
	ofstream sword{ ".//Items//" + character.name + "_swords.txt" };
	auto cout_buff = cout.rdbuf();
	cout.rdbuf(sword.rdbuf());

	cout << character.sword_name[attack_arr] << endl << character.sword_damage[attack_arr] << endl;

	cout.rdbuf(cout_buff);

	//save staffs
	ofstream staff{ ".//Items//" + character.name + "_staffs.txt" };
	cout.rdbuf(staff.rdbuf());

	cout << character.staff_name[attack_arr] << endl << character.staff_damage[attack_arr] << endl;

	cout.rdbuf(cout_buff);

	//save armors
	ofstream armor{ ".//Items//" + character.name + "_armors.txt" };
	cout.rdbuf(armor.rdbuf());

	cout << character.armor_name[attack_arr] << endl << character.armor_stats[attack_arr] << endl;

	cout.rdbuf(cout_buff);

	//save potions
	ofstream potions{ ".//Items//" + character.name + "_potions.txt" };
	cout.rdbuf(potions.rdbuf());

	cout << character.hp_potion_q << endl << character.hp_potion_q << endl;

	cout.rdbuf(cout_buff);
}

//ITEM DROP LOTTERY
void drop_items(Hero& character, Items eq[], int& attack_arr) {
	int choice5;
	int item = 0;
	srand((unsigned int)time(NULL));
	item = rand() % 3; 


	switch (item) {
		//SWORD LOTTERY
	case 0:
		cout << endl << endl << "You found " << eq[0].sword_name[attack_arr];
		cout << endl << eq[0].sword_name[attack_arr] << " Damage: " << eq[0].sword_damage[attack_arr] << endl;

		cout << "Do you wish to equip it?" << endl;
		while (!(cin >> choice5) || choice5 > 1 || choice5 < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error! Try again..." << endl << endl;
		}
		if (choice5 == 1) { 
			character.sword_name[attack_arr];
			character.sword_damage[attack_arr];
		
			ofstream ofs{ ".//Items//" + character.name + "_swords.txt" };
			auto cout_buff = cout.rdbuf();
			cout.rdbuf(ofs.rdbuf());

			cout << character.sword_name[attack_arr] << endl << character.sword_damage[attack_arr] << endl;

			cout.rdbuf(cout_buff);
		}
		else if (choice5 == 0) { 
			ifstream inputFile;
			inputFile.open(".//Items//" + character.name + "_swords.txt");

			inputFile >> character.sword_name[attack_arr];
			inputFile >> character.sword_damage[attack_arr];
	
			inputFile.close();
		}
		break;


		//STAFF LOTTERY
	case 1:
		cout << endl << endl << "You found " << eq[0].staff_name[attack_arr];
		cout << endl << eq[0].staff_name[attack_arr] << " Damage: " << eq[0].staff_damage[attack_arr] << endl;

		cout << "Do you wish to equip it?" << endl;
		while (!(cin >> choice5) || choice5 > 1 || choice5 < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error! Try again..." << endl << endl;
		}
		if (choice5 == 1) {
			character.staff_name[attack_arr];
			character.staff_damage[attack_arr];

			ofstream ofs{ ".//Items//" + character.name + "_staffs.txt" };
			auto cout_buff = cout.rdbuf();
			cout.rdbuf(ofs.rdbuf());

			cout << character.staff_name[attack_arr] << endl << character.staff_damage[attack_arr] << endl;

			cout.rdbuf(cout_buff);
		}
		else if (choice5 == 0) {
			ifstream inputFile;
			inputFile.open(".//Items//" + character.name + "_staffs.txt");

			inputFile >> character.staff_name[attack_arr];
			inputFile >> character.staff_damage[attack_arr];

			inputFile.close();
		}
		break;


	//ARMOR LOTTERY
	case 2:
		cout << endl << endl << "You found " << eq[0].armor_name[attack_arr];
		cout << endl << eq[0].armor_name[attack_arr] << " Damage: " << eq[0].armor_stats[attack_arr] << endl;

		cout << "Do you wish to equip it?" << endl;
		while (!(cin >> choice5) || choice5 > 1 || choice5 < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error! Try again..." << endl << endl;
		}
		if (choice5 == 1) {
			character.armor_name[attack_arr];
			character.armor_stats[attack_arr];

			ofstream ofs{ ".//Items//" + character.name + "_armors.txt" };
			auto cout_buff = cout.rdbuf();
			cout.rdbuf(ofs.rdbuf());

			cout << character.armor_name[attack_arr] << endl << character.armor_stats[attack_arr] << endl;

			cout.rdbuf(cout_buff);
		}
		else if (choice5 == 0) {
			ifstream inputFile;
			inputFile.open(".//Items//" + character.name + "_armors.txt");

			inputFile >> character.armor_name[attack_arr];
			inputFile >> character.armor_stats[attack_arr];

			inputFile.close();
		}
		break;

	deafult:
		cout << endl << "Error!" << endl;
		break;
	}
}


//DISPLAY ITEMS
void armor(Hero& character, Items eq[], int& attack_arr) {
	cout << endl << endl << "Your armor: " << character.armor_name[attack_arr] << endl << "Damage reduction: " << character.armor_stats[attack_arr] << endl;
	cout << endl << endl;
}
void sword(Hero& character, Items eq[], int& attack_arr) {
	cout << endl << endl << "Your sword: " << character.sword_name[attack_arr] << endl << "Additional damage: " << character.sword_damage[attack_arr] << endl;
	cout << endl << endl;
}
void staff(Hero& character, Items eq[], int& attack_arr) {
	cout << endl << endl << "Your staff: " << character.staff_name[attack_arr] << endl << "Additional damage: " << character.staff_damage[attack_arr] << endl;
	cout << endl << endl;
}
void potions(Hero& character, Items eq[], int& attack_arr) {
	cout << endl << endl << "Your potions: " << character.hp_potion_q << endl << "Each heals: " << character.hp_potion_amount << endl;
	cout << endl << endl;
}

//ERROR NOTIFICATIONS
void error_armor(Hero& character, Items eq[], int& attack_arr, int& error) {
	if (character.armor_stats[attack_arr] == 0) {
		cout << endl << "You dont have armor!" << endl << endl;
		error = 1;
	}
}
void error_sword(Hero& character, Items eq[], int& attack_arr, int& error) {
	if (character.sword_damage[attack_arr] == 0) {
		cout << endl << "You dont have sword!" << endl << endl;
		error = 1;
	}
}
void error_staff(Hero& character, Items eq[], int& attack_arr, int& error) {
	if (character.staff_damage[attack_arr] == 0) {
		cout << endl << "You dont have staff!" << endl << endl;
		error = 1;
	}
}
void error_potions(Hero& character, Items eq[], int& attack_arr, int& error) {
	if (character.hp_potion_q == 0) {
		cout << endl << "You dont have potions!" << endl << endl;
		error = 1;
	}
}

//SEARCH FOR ITEMS
void search(Hero& character, Items eq[], int arr_size, string& name, int type, int& attack_arr) {

	if (character.armor_name[arr_size] == name && type == 1 && character.armor_name[arr_size] == character.armor_name[attack_arr]) {
		cout << endl << endl << "Your armor: " << character.armor_name[arr_size] << endl << "Damage reduction: " << character.armor_stats[arr_size] << endl;
		cout << endl << endl;
	}
	else if (character.sword_name[arr_size] == name && type == 2 && character.sword_name[arr_size] == character.sword_name[attack_arr]) {
		cout << endl << endl << "Your sword: " << character.sword_name[arr_size] << endl << "Additional damage: " << character.sword_damage[arr_size] << endl;
		cout << endl << endl;
	}
	else if (character.staff_name[arr_size] == name && type == 3 && character.staff_name[arr_size] == character.staff_name[attack_arr]) {
		cout << endl << endl << "Your staff: " << character.staff_name[arr_size] << endl << "Additional damage: " << character.staff_damage[arr_size] << endl;
		cout << endl << endl;
	}
	else if (arr_size >= 6) {
		cout << "Item not found" << endl;
	}
	else {
		arr_size++;
		search(character, eq, arr_size, name, type, attack_arr);
	}
}