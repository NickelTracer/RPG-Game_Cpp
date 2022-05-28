#include "hero.h"
#include "monsters.h"

//Character creation
void Create_character(Hero& character, int& free_points, int& proceed, int& prof, Mage& mage, Warrior& warrior, Berserker& berserker, Thief& thief, int& attack_arr) {

	character.strength = 0;
	character.dexterity = 0;
	character.endurance = 0;
	character.intelligence = 0;
	character.charisma = 0;

	character.armor_name[6];
	character.armor_stats[6];
	character.sword_name[6];
	character.sword_damage[6];
	character.staff_name[6];
	character.staff_damage[6];
	character.hp_potion_q = 5;

	cout << endl << endl << endl << "_____________________________" << endl;
	cout << "Welcome to character creation!" << endl << "Select name for your character: " << endl;
	cout << "_____________________________" << endl;

	while (!(cin >> character.name) || (character.name == "none")) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Illegal name used. Try again!" << endl << endl;
	}

	//proffesion selection and boosters
	cout << "_____________________________" << endl;
	cout << endl << endl << "Choose your profession : " << endl;


	while (cout << "1.Mage\t\t(+2 intelligence) \n2.Warrior\t(+2 endurance) \n3.Berserker\t(+2 strength) \n4.Thief\t\t(+2 dexterity)" << endl && !(cin >> prof) || (prof > 4) || prof < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid integer entered. Try again!" << endl << endl;
	}

	cout << "_____________________________" << endl;
	if (prof == 1) {
		mage.add_boost(character);
		cout << "Welcome " << character.name << " The Mage!";
	}
	else if (prof == 2) {
		warrior.add_boost(character);
		cout << "Welcome " << character.name << " The Warrior!";
	}
	else if (prof == 3) {
		berserker.add_boost(character);
		cout << "Welcome " << character.name << " The Berserker!";
	}
	else if (prof == 4) {
		thief.add_boost(character);
		cout << "Welcome " << character.name << " The Thief!";
	}
	else {
		cout << "Error, try again!";
		proceed = 0;
	}
	cout << endl << "_____________________________" << endl;
	cout << "\nYou've got 10 points to spent on Strenght, Dexterity, Endurance, Intelligence, Charisma, spent them now!" << endl;

	free_points = 10;
}

	//points distribution
	void Points(Hero & character, int& free_points, int& proceed, int& prof, Mage & mage, Warrior & warrior, Berserker & berserker, Thief & thief){
		int strength = 0;
		int dexterity = 0;
		int endurance = 0;
		int intelligence = 0;
		int charisma = 0;

		while (free_points > 0 ) {

		
		//cout << "Free points left: " << free_points;
		//cout << endl << "Strength: ";
		//cin >> strength;
		while (cout << "Free points left: " << free_points << endl << "Strength: " && !(cin >> strength) || strength < 0 || strength > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid integer entered. Try again!" << endl << endl;
		}
		free_points = free_points - strength;
		if (free_points <= 0) {
 			break;
		}

		while (cout << "Free points left: " << free_points << endl << "Dexterity: " && !(cin >> dexterity) || dexterity < 0 || dexterity > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid integer entered. Try again!" << endl << endl;
		}
		free_points = free_points - dexterity;
		if (free_points <= 0) {
			break;
		}

		while (cout << "Free points left: " << free_points << endl << "Endurance: " && !(cin >> endurance) || endurance < 0 || endurance > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid integer entered. Try again!" << endl << endl;
		}
		free_points = free_points - endurance;
		if (free_points <= 0) {
			break;
		}

		while (cout << "Free points left: " << free_points << endl << "Intelligence: " && !(cin >> intelligence) || intelligence < 0 || intelligence > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid integer entered. Try again!" << endl << endl;
		}
		free_points = free_points - intelligence;
		if (free_points <= 0) {
			break;
		}

		while (cout << "Free points left: " << free_points << endl << "Charisma: " && !(cin >> charisma) || charisma < 0 || charisma > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid integer entered. Try again!" << endl << endl;
		}
		free_points = free_points - charisma;
		if (free_points <= 0 ) {
			break;
		}
	}

	//Error statement
	if (free_points != 0) {
		cout << "Oops, something went wrong! Try again.." << endl;

		free_points = free_points + strength;
		free_points = free_points + dexterity;
		free_points = free_points + endurance;
		free_points = free_points + intelligence;
		free_points = free_points + charisma;
		proceed = 0;
	}
	else if (free_points == 0) {
		
		character.strength = character.strength + strength;
		character.dexterity = character.dexterity + dexterity;
		character.endurance = character.endurance + endurance;
		character.intelligence = character.intelligence + intelligence;
		character.charisma = character.charisma + charisma;
		proceed = 1;
	}
}


//display statistics of Hero
void Character_stats_display(Hero character) {
	cout << endl << endl << "_____________________________" << endl;
	cout << "Character creation finished!" << "\nStatistics of " << character.name << ": ";
	cout << "\nStrength: " << character.strength << "\t\t\tAttack: " << character.Attack;
	cout << "\nDexterity: " << character.dexterity << "\t\t\tDamage Reduction: " << character.Damage_reduction;
	cout << "\nEndurance: " << character.endurance << "\t\t\tHP: " << character.HP;
	cout << "\nIntelligence: " << character.intelligence << "\t\t\tMagic Attack: " << character.Magic_attack;
	cout << "\nCharisma: " << character.charisma << "\t\t\tCritical Attack: " << character.Critical_attack;
	cout << endl << "_____________________________" << endl;
}

//save character to file named exactly like character
void Character_save(Hero character, int& cap, int& free_points, int& attack_arr) {

	ofstream ofs{ ".//Characters//" + character.name + ".txt" };
	auto cout_buff = cout.rdbuf();
	cout.rdbuf(ofs.rdbuf());

	cout << character.level << endl << character.exp << endl << character.strength << endl << character.dexterity << endl << character.endurance << endl << character.intelligence << endl << character.charisma << endl << cap << endl << free_points << endl << attack_arr;

	cout.rdbuf(cout_buff);
}

//load character by typing your character name
void Character_load(Hero& character, int& cap, int&free_points, Items eq[], int& attack_arr) {
	cout << "_____________________________" << endl;
	const filesystem::path path{ ".//Characters//" };

	remove(".//Characters//none.txt");
	for (auto const& dir_entry : filesystem::directory_iterator{ path }) {
		if (dir_entry.is_regular_file() && dir_entry.path().string().ends_with(".txt")) {
			cout << dir_entry.path().filename().replace_extension() << '\n';
		}
	}
	cout << "_____________________________" << endl;

	ifstream inputFile;
		while (1) {
			cout << "Enter your character: " << std::endl;
			cin >> character.name;
			if (!(character.name != "exit")) exit(1);
			string filename = "./Characters/";
			string display = character.name;
			display.append(".txt");
			filename.append(display);

			inputFile.open(filename.c_str());
			if (!inputFile) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				filename.clear();
				cout << "\nSave file does not exist, try again!\n" << endl;
			}
			else {
				break;
			}
		}

	//stats
	inputFile >> character.level;
	inputFile >> character.exp;
	inputFile >> character.strength;
	inputFile >> character.dexterity;
	inputFile >> character.endurance;
	inputFile >> character.intelligence;
	inputFile >> character.charisma;
	inputFile >> cap;
	inputFile >> free_points;
	inputFile >> attack_arr;
	attack_arr;

	inputFile.close();

	cout << endl << endl << "_____________________________" << endl;
	cout << "\nStatistics of " << character.name << ": ";
	cout << "\nLevel: " << character.level;
	cout << "\nExperience: " << character.exp << "/" << cap;
	cout << "\n\nStrength: " << character.strength;
	cout << "\nDexterity: " << character.dexterity;
	cout << "\nEndurance: " << character.endurance;
	cout << "\nIntelligence: " << character.intelligence;
	cout << "\nCharisma: " << character.charisma;
	cout << endl << "_____________________________" << endl;

	//swords
	inputFile.open(".//Items//" + character.name + "_swords.txt");

	inputFile >> character.sword_name[attack_arr];
	inputFile >> character.sword_damage[attack_arr];

	inputFile.close();

	//staffs
	inputFile.open(".//Items//" + character.name + "_staffs.txt");

	inputFile >> character.staff_name[attack_arr];
	inputFile >> character.staff_damage[attack_arr];

	inputFile.close();

	//armors
	inputFile.open(".//Items//" + character.name + "_armors.txt");

	inputFile >> character.armor_name[attack_arr];
	inputFile >> character.armor_stats[attack_arr];

	inputFile.close();

	//potions
	inputFile.open(".//Items//" + character.name + "_potions.txt");

	inputFile >> character.hp_potion_q;

	inputFile.close();
}