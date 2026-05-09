#include <iostream>
#include <string>
#include "board.h"
#include <windows.h>

using namespace std;

bool check_input(string s);
bool check_missile_input(string i);
bool check_napalm_input(string k);
bool check_end_input(string g);
bool check_menu_input(string g);
void space();

void Board::welcomeScreen() {

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-------------------------------------------WELCOME TO UKRAINIAN BATTLESHIP----------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                  |    |    |                             |    |    |                 \n"
		 << "                                 )_)  )_)  )_)                           )_)  )_)  )_)                \n"
		 << "                                )___))___))___)\\                        )___))___))___)\\              \n"
		 << "                               )____)____)_____)\\\\                     )____)____)_____)\\\\            \n"
		 << "                             _____|____|____|____\\\\\\__               _____|____|____|____\\\\\\__        \n"
		 << "-----------------------------\\  *  *  *  *  *  /---------------------\\  *  *  *  *  *  /--------------------------------\n"
		 << "           ^^^^        ^^^^^ ^^^^^^^^^^^^^^^^^^^^^     ^^^       ^^^^^ ^^^^^^^^^^^^^^^^^^^^^      ^^^^        ^^          \n"
		 << "   ^^^^^                ^^^^      ^^^^     ^^^    ^^              ^^^^      ^^^^     ^^^    ^^          ^^^         ^^^  \n"
		 << "            ^^^^^            ^^^^      ^^^            ^^^^             ^^^^      ^^^            ^^           ^^^    \n";
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	system("pause");
	system("cls");
	space();
}

void Board::mainMenu() {

	space();
	string choice;

	cout << "1. New Game" << endl;
	cout << "2. Instructions" << endl;
	cout << "3. Difficulty" << endl;
	cout << "4. Achievements" << endl;
	cout << "5. Exit to Desktop" << endl << endl;
	
	cout << "Input: ";
	cin >> choice;
	while (!check_menu_input(choice)) {
		cout << "Please enter valid input: ";
		cin >> choice;
	}
	if (choice[0] == '1') {
		if (allias.empty()) {
			system("cls");
			space();
			cout << "Enter your username: ";
			cin.ignore();
			getline(cin, allias);
		}
		else {
			system("cls");
			space();
			setUpPrivateBoard();
			Battleship Frigatte("F");
			Battleship Submarine("S");
			Battleship Destroyer("D");
			Battleship BattleShip("B");
			Battleship AircraftCarrier("A");

			placeShip(Frigatte);
			placeShip(Submarine);
			placeShip(Destroyer);
			placeShip(BattleShip);
			placeShip(AircraftCarrier);
		}
	}
	else if (choice[0] == '2') {
		system("cls");
		space();
		instructions();
	}
	else if (choice[0] == '3') {
		system("cls");
		space();
		selectDifficulty();
		mainMenu();
	}
	else if (choice[0] == '4') {
		system("cls");
		achievements_tab();

	}
	else if (choice[0] == '5') {
		cout << "Goodbye!" << endl;
		exit(EXIT_SUCCESS);
	}
	system("cls");
}

void Board::instructions() {

	cout << "========================================================================================================================" << endl;
	cout << "================================= | |\\  | ___ --- | \\  | | / \\ --- |  /\\ |\\  | ___ =====================================" << endl;
	cout << "================================= | | \\ | |__  |  | /  | | |    |  | | | | \\ | |__ =====================================" << endl;
	cout << "================================= | |  \\| __|  |  | \\  \\_/ \\ /  |  | \\/  |  \\| __| =====================================" << endl;
	cout << "========================================================================================================================" << endl << endl;

	string choice;

	cout << "1. Story" << endl;
	cout << "2. Controls" << endl;
	cout << "3. Special Weapons" << endl;
	cout << "4. Difficulties" << endl;
	cout << "5. Main Menu" << endl << endl;
	
	cout << "Input: ";

	cin >> choice;
	while (!check_menu_input(choice)) {
		cout << "Please enter valid input: ";
		cin >> choice;
	}

	if (choice[0] == '1') {
		cout << endl << "STORY" << endl;
		cout << "***************************************************************************************************************\n";
		cout << "*    Welcome to the command center. From here you can control the artillery at our fleet's disposal.          *\n";
		cout << "* The Russian naZi fleet has blockaded the key port city of Odessa.                                           *\n";
		cout << "*	  We have positioned our defences to reach the enemy, but our radar is being jammed and a terrible fog has *\n";
		cout << "* obstructed our view. Enemy shelling has hit some of our more advanced systems, but we are working on those  *\n";
		cout << "* repairs. Keep the enemy at bay and we'll soon have access to our heat-seeking missile Neptune and if you    *\n";
		cout << "* take out enough of their air defence capabilities, we'll be able to request a napalm strike.                *\n";
		cout << "***************************************************************************************************************\n\n";

		system("pause");
		system("cls");
		space();
		instructions();
	}

	if (choice[0] == '2') {
		cout << endl << "CONTROLS:" << endl;
		cout << "***************************************************************************************************************\n";
		cout << "*    The enemy coordinates are mapped on a X * Y grid. Type them in and hit Enter to launch artillery.        *\n";
		cout << "* When special weapons are available, type in their corresponding button and hit Enter to engage that system. *\n";
		cout << "* Remember, you will not be able to disengage those systems.                                                  *\n";
		cout << "* One more thing, if you miss 15 times in a row, the enemy will determine the command post's location and we  *\n";
		cout << "* will all perish. So be sure to use strategy when engaging the enemy                                         *\n";
		cout << "***************************************************************************************************************\n\n";

		system("pause");
		system("cls");
		space();
		instructions();
	}

	if (choice[0] == '3') {
		cout << endl << "SPECIAL WEAPONS:" << endl;
		cout << "************************************************************************************************************** \n";
		cout << "*     Special weapons unlock at different rates, depending on the selected difficulty, have varying dr       *\n";
		cout << "* chances, and are exponentially nerfed with increasing difficulty. Once unlocked, the drop chance will be   *\n";
		cout << "* halved.                                                                                                    *\n";
		cout << "*                                                                                                            *\n";
		cout << "* Bribe ('k' to use): After heavily demoralizing enemy officers will successful attacks, one of them might   *\n";
		cout << "* reachout to offer information in return for a generous donation of 100 points to his wallet's cause. Be    *\n";
		cout << "* wary though, many are not trustworthy and might just take your money and flee.                             *\n";
		cout << "*                                                                                                            *\n";
		cout << "* Heat-seeking missile ('l' to use): Once enough enemy artillary has been taken out for our repair crew to   *\n";
		cout << "* get this system back online, you will be able to use a precision rocket 4-9x as accurate as our standard   *\n";
		cout << "* weapons. It will scout the surrounding area of your initial coordinate and hit the first target it finds.  *\n";
		cout << "*                                                                                                            *\n";
		cout << "* Napalm strike ('m' to use): Finally, with enough enemy defence capabilities rendered dysfunctional, we can *\n";
		cout << "* safely deploy a napalm strike to eliminate the remaining forces. The fire will affect targets in a liniar  *\n";
		cout << "* fashion and force them to evacuate the ships.                                                              *\n";
		cout << "**************************************************************************************************************\n\n";

		system("pause");
		system("cls");
		space();
		instructions();
	}

	if (choice[0] == '4') {
		cout << endl << "DIFFICULTIES:" << endl;
		cout << "**************************************************************************************************************\n";
		cout << "*     Easy: All special weapons unlocked at start.                                                           *\n";
		cout << "* Bribe: After use, has a 12.5%  drop rate. Entire field available to bribe.                                 *\n";
		cout << "* Heat-Seeking Missile: After use, has a 10% drop rate. Missile's range is 3x3                               *\n";
		cout << "* Napalm Strike: After use, has a 7.1% drop rate. Napalm's range is 5 spaces.                                *\n";
		cout << "*                                                                                                            *\n";
		cout << "*     Normal: Special weapons drop chance unlocked after sufficient targets have been destroyed.             *\n";
		cout << "* Bribe: After 3 targets have been destroyed, has a 20% drop rate. 10% drop rate after use. Random half of   *\n";
		cout << "* the field is available to bribe.                                                                           *\n";
		cout << "* Heat-Seeking Missile: After 5 targets have been destroyed, has a 14.2% drop rate. 7.1% drop rate after     *\n";
		cout << "* use. Missile's range is 3x2.                                                                               *\n";
		cout << "* Napalm Strike: After 8 targets have been destroyed, has a 10% drop rate. 5% drop rate after use. Napalm's  *\n";
		cout << "* range is 4 spaces.                                                                                         *\n";
		cout << "*                                                                                                            *\n";
		cout << "*     Hard: Special weapons drop chance unlocked after sufficient targets have been destroyed. Only 10       *\n";
		cout << "* consecutive misses allowed.                                                                                *\n";
		cout << "* Bribe: After 5 targets have been destroyed, has a 14.2% drop rate. 7.1% after use. Random quarter of the   *\n";
		cout << "* field is available to bribe.                                                                               *\n";
		cout << "* Heat-Seeking Missile: After 7 targets have been destroyed, has a 10% drop rate. 5% drop rate after use.    *\n";
		cout << "* Missile's range is 2x2.                                                                                    *\n";
		cout << "* Napalm Strike: After 10 targets have been destroyed, has a 6.6% drop rate. 3.3% drop rate after use.       *\n";
		cout << "* Napalm's range is 3 spaces.                                                                                *\n";
		cout << "**************************************************************************************************************\n";

		system("pause");
		system("cls");
		space();
		instructions();
	}

	if (choice[0] == '5') {
		system("cls");
		space();
		mainMenu();
	}
}

void Board::selectDifficulty() {
	int dif;
	cout << "1. Easy" << endl;
	cout << "2. Normal" << endl;
	cout << "3. Hard" << endl << endl;

	cout << "Input: ";
	cin >> dif;
	while (dif < 1 || dif > 3) {
		cout << "Please enter valid input: ";
		cin >> dif;
	}
	difficulty = (Difficulty)dif;
	if (difficulty == 1) {
		cout << endl << "Easy difficulty selected\n\n";
		system("pause");
	}
	if (difficulty == 2) {
		cout << endl << "Normal difficulty selected\n\n";
		system("pause");
		commonDrop = NOT_FOUND;
		uncommonDrop = NOT_FOUND;
		rareDrop = NOT_FOUND;
		system("cls");
	}
	else if (difficulty == 3) {
		cout << endl << "Hard difficulty selected\n\n";
		system("pause");
		commonDrop = FOUND;
		uncommonDrop = NOT_FOUND;
		rareDrop = NOT_FOUND;
		system("cls");
	}
}

void Board::achievements_check() {

	scoreMult == (2) ? heating_up = true, achievCounter++ : false;
	scoreMult == (3) ? on_fire = true, achievCounter++ : false;
	scoreMult == (5) ? who_is_this_guy = true, achievCounter++ : false;
	if (end_game == true && difficulty == 1 && commonDrop == FOUND && uncommonDrop == FOUND && rareDrop == FOUND) {
		feeling_cheeky = true;
		achievCounter++;
	}
	if (end_game == true && difficulty == 2 && commonDrop == FOUND && uncommonDrop == FOUND && rareDrop == FOUND) {
		didnt_need_em = true;
		achievCounter++;
	}
	if (end_game == true && difficulty == 3 && commonDrop == FOUND && uncommonDrop == FOUND && rareDrop == FOUND) {
		i_gots_this = true;
		achievCounter++;
	}
	if (end_game == true && difficulty == 2 &&  commonDrop == FOUND && uncommonDrop == FOUND && rareDrop == FOUND) {
		collector = true;
		achievCounter++;
	}
	if (end_game == true && difficulty == 3 &&  commonDrop == FOUND && uncommonDrop == FOUND && rareDrop == FOUND) {
		master_collector = true;
		achievCounter++;
	}
}

void Board::achievements_tab() {

	string status;

	cout << "Completed: " << achievCounter << "/17\n\n";

	heating_up == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Heating up: " << status;
	cout << "(2 hits in a row)\n\n";

	on_fire == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "On Fire!: " << status;
	cout << "(3 hits in a row)\n\n";

	who_is_this_guy == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Who is This Guy?!: " << status;
	cout << "(5 hits in a row)\n\n";

	thank_you_for_the_corruption == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Thank You For the Corruption: " << status;
	cout << "Successfully bribe an enemy oficer on NORMAL)\n\n";

	the_greed_is_real == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "The Greed is Real: " << status;
	cout << "(Successfully bribe an enemy officer on HARD)\n\n";

	nice_plan == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Nice Plan: " << status;
	cout << "(Land a hit after an enemy officer runs away with the bribe on NORMAL)\n\n";

	no_one_gets_away == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "No One Gets Away: " << status;
	cout << "(Land a hit after an enemy officer runs away with the bribe on HARD)\n\n";

	precision_baby == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Precision, baby: " << status;
	cout << "(Land a missile hit on NORMAL)\n\n";

	neptune == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Neptune: " << status;
	cout << "(Land a missile hit on HARD)\n\n";

	what_are_the_odds == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "What are the Odds: " << status;
	cout << "(Land 5 hits with one Napalm Strike on EASY)\n\n";

	lend_lease_biatch == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Lend-Lease, Biatch: " << status;
	cout << "(Land 4 hits with one Napalm Strike on NORMAL)\n\n";

	burn_orcs == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Burn, Orcs: " << status;
	cout << "(Land 3 hits with one Napalm Strike on HARD)\n\n";

	feeling_cheeky == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Feeling Cheeky: " << status;
	cout << "(Don't use any special weapons on EASY)\n\n";

	didnt_need_em == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Didn't Need 'Em: " << status;
	cout << "(Don't use any special weapons on NORMAL)\n\n";

	i_gots_this == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "I Gots This: " << status;
	cout << "(Don't use any special weapons on HARD)\n\n";

	collector == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Collector: " << status;
	cout << "(End the game with every special weapon available on NORMAL)\n\n";

	master_collector == (true) ? status = "Unlocked\n" : status = "Locked\n";
	cout << "Master Collector: " << status;
	cout << "(End the game with every special weapon available on HARD)\n\n";

	system("pause");

	system("cls");
	mainMenu();

}

void Board::printPrivateBoard() {
	space();
	print_message(message);
	cout << allias << ": " << score << endl;
	cout << "High score: " << highScore << endl;
	cout << "Misses: " << missCounter << endl;
	cout << "Bribe('k' to use): ";
	if (commonDrop == 0) {
		cout << "Available" << endl;
	}
	else {
		cout << "Not available" << endl;
	}
	cout << "Heat-seeking missile('l' to use): ";
	if (uncommonDrop == 0) {
		cout << "Available" << endl;
	}
	else {
		cout << "Not available" << endl;
	}
	cout << "Napalm strike('m' to use): ";
	if (rareDrop == 0) {
		cout << "Available" << endl;
	}
	else {
		cout << "Not available" << endl;
	}

	cout << "   A  B  C  D  E  F  G  H  I  J"; //prints header for the board, with the letters being the x axis
	cout << endl;
	for (int x = 0; x < 10; x++) {
		cout << x + 1;
		if (x != 9) {
			cout << " "; //prints out the y axis of numbers with a space escept for 10
		}

		for (int y = 0; y < 10; y++) {
			cout << privateBoard[x][y]; //prints out the empty board for the rest
		}
		cout << endl;
	}
}


void Board::missHit() {
	string j;

	cout << "Enter attack coordinates or use a drop('n' to exit/'x' main menu): ";
	cin >> j;

	if (j[0] == 'n') {
		cout << "Goodbye!" << endl;
		exit(EXIT_SUCCESS);
	}
	if (j[0] == 'x') {
		system("cls");
		if (difficulty == 1) {
			commonDrop = FOUND;
			uncommonDrop = FOUND;
			rareDrop = FOUND;
		}
		else {
			commonDrop = NOT_FOUND;
			uncommonDrop = NOT_FOUND;
			rareDrop = NOT_FOUND;
		}
		
		score = 0;
		missCounter = 0;
		scoreMult = 1;
		mainMenu();
	}
	while (!check_input(j)) {
		cout << "Please enter valid input: ";
		cin >> j;
	}

	if (j.length() == 1) {
		if (j[0] == 'k') {
			if (commonDrop == FOUND && score >= 100) {
				system("cls");
				message = "Bribe used!";
				printPrivateBoard();
				Sleep(750);
				if (!bribe(difficulty)) {
					Sleep(750);
					system("cls");
					message = "The enemy officer has run away with the bribe!!!";
					printPrivateBoard();
				}
				commonDrop = USED;
				score -= 100;
			}
			else {
				system("cls");
				commonDrop == (FOUND) ? message =  "Not enough funds for the bribe!" : message = "No corrupt officer found yet!";
			}
		}
		else if (j[0] == 'l') {
			if (uncommonDrop == FOUND) {
				string q;
				cout << "Enter heat-seeking missile coordinates: ";
				cin >> q;
				if (q[0] == 'n') {
					cout << "Goodbye!" << endl;
					exit(EXIT_SUCCESS);
				}
				while (!check_missile_input(q)) {
					cout << "Please enter valid input: ";
					cin >> q;
				}
				system("cls");
				missile(q[0], q[1] - '0');
				achievements_check();
				uncommonDrop = USED;
			}
			else {
				system("cls");
				message = "Heat-seeking missile not online yet!";
			}
		}
		else if (j[0] == 'm') {
			if (rareDrop == FOUND) {
				string a;
				cout << "Enter napalm starting coordinate and direction with a letter (l = left, r = right, u = up, d = down): ";
				cin >> a;
				if (a[0] == 'n') {
					cout << "Goodbye!" << endl;
					exit(EXIT_SUCCESS);
				}
				while (!check_napalm_input(a)) {
					cout << "Please enter valid input: ";
					cin >> a;
				}
				system("cls");
				if (a.length() == 3) {
					napalm(a[0], a[1] - '0', a[2]);
				}
				else {
					napalm(a[0], 10, a[3]);
				}
				achievements_check();
				rareDrop = USED;
			}
			else {
				system("cls");
				message = "Not safe to launch napalm strike yet!";
			}
		}
	}
	else {
		convertCoordinateToInt2(j[0]);
		x = stoi(j.substr(1));
		message = " ";
		turn();
	}
}

void Board::turn() {
	if (board[x - 1][z] == "[ ]") {
		privateBoard[x - 1][z] = "[O]";
		board[x - 1][z] = "[O]";
		missCounter += 1;
		scoreMult = 1;
		if (missCounter == 15) {
			string c;
			cout << "You lose!" << endl;
			cout << "Play again? y/n: ";
			cin >> c;
			if (c[0] == 'n') {
				cout << "Goodbye!" << endl;
				exit(EXIT_SUCCESS);
			}
			while (!check_end_input(c)) {
				cout << "Please enter valid input: ";
				cin >> c;
			}
			if (c[0] == 'y') {
				system("cls");
				space();
				achievements_check();
				if (difficulty == 1) {
					commonDrop = NOT_FOUND;
					uncommonDrop = FOUND;
					rareDrop = FOUND;
				}
				else {
					commonDrop = NOT_FOUND;
					uncommonDrop = NOT_FOUND;
					rareDrop = NOT_FOUND;
				}
				
				mainMenu();
				highScore = score;
				score = 0;
				missCounter = 0;
				scoreMult = 1;
			}
		}
	}
	else {
		if (privateBoard[x - 1][z] != "[X]" && privateBoard[x - 1][z] != "[O]") {
			privateBoard[x - 1][z] = "[X]";
			score += (25 * scoreMult);
			scoreMult += 1;
			hitCounter += 1;
			missCounter = 0;
			if (bribe_fail == true) {
				message = "You've killed the corrupt officer!";
				bribe_fail = false;
				difficulty == (2) ? nice_plan = true, achievCounter++ : no_one_gets_away = true, achievCounter++;
				if (nice_plan) {
					cout << "Achievement unlocked: Nice Plan\n";
					Sleep(750);
				}
				if (no_one_gets_away) {
					cout << "Achievement unlocked: No One Gets Away\n";
					Sleep(750);
				}
				system("pause");
			}
			randomDrop(difficulty);
			achievements_check();
		}
		
		else {
			if (board[x - 1][z] == "[O]") {
				cout << "Target already hit!" << endl;
				Sleep(750);
			}
			else {
				cout << "Target already hit!" << endl;
				Sleep(750);
			}
		}
	}

	system("cls");
	space();
}

void Board::randomDrop(int a) {
	if (a == 1) {
		if (commonDrop == NOT_FOUND && hitCounter >= 2 && (rand() % 4) == 2) {
			commonDrop = FOUND;
			if (commonDrop == USED && (rand() % 8) == 2) {
				commonDrop = FOUND;
			}
		}

		else if (uncommonDrop == NOT_FOUND && hitCounter >= 4 && (rand() % 5) == 3) {
			uncommonDrop = FOUND;
			if (uncommonDrop == USED && (rand() % 10) == 2) {
				uncommonDrop = FOUND;
			}

		}
		else if (rareDrop == NOT_FOUND && hitCounter >= 7 && (rand() % 7) == 4) {
			rareDrop = FOUND;
			if (rareDrop == USED && (rand() % 14) == 2) {
				rareDrop = FOUND;
			}
		}
	}
	if (a == 2) {
		if (commonDrop == NOT_FOUND && hitCounter >= 3 && (rand() % 5) == 2) {
			commonDrop = FOUND;
			if (commonDrop == USED && (rand() % 10) == 2) {
				commonDrop = FOUND;
			}
		}
		else if (uncommonDrop == NOT_FOUND && hitCounter >= 5 && (rand() % 7) == 3) {
			uncommonDrop = FOUND;
			if (uncommonDrop == USED && (rand() % 14) == 2) {
				uncommonDrop = FOUND;
			}

		}
		else if (rareDrop == NOT_FOUND && hitCounter >= 8 && (rand() % 10) == 4) {
			rareDrop = FOUND;
			if (rareDrop == USED && (rand() % 20) == 2) {
				rareDrop = FOUND;
			}
		}
	}
	if (a == 3) {
		if (commonDrop == NOT_FOUND && hitCounter >= 5 && (rand() % 7) == 2) {
			commonDrop = FOUND;
			if (commonDrop == USED && (rand() % 14) == 2) {
				commonDrop = FOUND;
			}
		}
		else if (uncommonDrop == NOT_FOUND && hitCounter >= 7 && (rand() % 10) == 3) {
			uncommonDrop = FOUND;
			if (uncommonDrop == USED && (rand() % 20) == 2) {
				uncommonDrop = FOUND;
			}

		}
		else if (rareDrop == NOT_FOUND && hitCounter >= 10 && (rand() % 15) == 4) {
			rareDrop = FOUND;
			if (rareDrop == USED && (rand() % 30) == 2) {
				rareDrop = FOUND;
			}
		}
	}
}

bool Board::bribe(int a) {
	if (a == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[0]" && privateBoard[i][j] != "[X]") {
					message = "Coordinate found at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
					return true;
				}
			}
		}
	}

	else if (a == 2) {
		if (rand() % 2) {
			for (int i = 5; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[0]" && privateBoard[i][j] != "[X]") {
						message = "Coordinate found at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
						thank_you_for_the_corruption = true;
						return true;
					}
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++) {
				for (int j = 5; j < 10; j++) {
					if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[0]" && privateBoard[i][j] != "[X]") {
						message = "Coordinate found at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
						thank_you_for_the_corruption = true;
						return true;
					}
				}
			}
		}
	}

	else if (a == 3) {
		if ((rand() % 4) == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[0]" && privateBoard[i][j] != "[X]") {
						message = "Coordinate found at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
						the_greed_is_real = true;
						return true;
					}
				}
			}
		}
		else if (rand() % 4 == 2) {
			for (int i = 5; i < 10; i++) {
				for (int j = 5; j < 10; j++) {
					if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[0]" && privateBoard[i][j] != "[X]") {
						message = "Coordinate found at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
						the_greed_is_real = true;
						return true;
					}
				}
			}
		}
		else if (rand() % 4 == 3) {
			for (int i = 5; i < 10; i++) {
				for (int j = 0; j < 5; j++) {
					if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[0]" && privateBoard[i][j] != "[X]") {
						message = "Coordinate found at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
						the_greed_is_real = true;
						return true;
					}
				}
			}
		}
		else if (rand() % 4 == 4) {
			for (int i = 0; i < 5; i++) {
				for (int j = 5; j < 10; j++) {
					if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[0]" && privateBoard[i][j] != "[X]") {
						message = "Coordinate found at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
						the_greed_is_real = true;
						return true;
					}
				}
			}
		}
	}

	bribe_fail = true;
	return false;
}

void Board::missile(char c, int y) {

	int x = convertCoordinateToInt(c);
	y--;

	if (difficulty == 1) {
		for (int i = y - 1; i < (y + 2); i++) {
			if (i >= 0 && i < 10) {
				for (int j = x - 1; j < (x + 2); j++) {
					if (j >= 0 && j < 10) {
						if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[X]" && privateBoard[i][j] != "[O]") {
							privateBoard[i][j] = "[X]";		
							message = "Target hit at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
							score += (50 * scoreMult);
							scoreMult += 1;
							missCounter = 0;
							return;
						}
						else {
							//cout << "No target found by missile at " << convertCoordinateToChar(j) << (i + 1) << endl;
							if (privateBoard[i][j] != "[X]") {
								privateBoard[i][j] = "[O]";
								board[i][j] = "[O]";
							}
						}
					}
				}
			}
		}
	}

	else {
		for (int i = y - 1; i < (y + 1); i++) {
			if (i >= 0 && i < 10) {
				for (int j = x - 1; j < (x + 2); j++) {
					if (j >= 0 && j < 10) {
						if (board[i][j] != "[ ]" && board[i][j] != "[O]" && privateBoard[i][j] != "[X]" && privateBoard[i][j] != "[O]") {
							privateBoard[i][j] = "[X]";
							message = "Target hit at " + string(1, (convertCoordinateToChar(j))) + to_string(++i);
							score += (50 * scoreMult);
							scoreMult += 1;
							missCounter = 0;

							if (!missile_achievement) {
								difficulty == (2) ? precision_baby = true, achievCounter++ : neptune = true, achievCounter++;
								if (precision_baby) {
									cout << "Achievement unlocked: Precision, baby\n";
									Sleep(750);
								}
								else if (neptune) {
									cout << "Achievement unlocked: Neptune\n";
									Sleep(750);
								}
							}

							missile_achievement = true;
							return;
						}
						else {
							//cout << "No target found by missile at " << convertCoordinateToChar(j) << (i + 1) << endl;
							if (privateBoard[i][j] != "[X]") {
								privateBoard[i][j] = "[O]";
								board[i][j] = "[O]";
							}
						}
					}
				}
			}
		}
	}
}

void Board::check_napalm_achievement(int y, int count) {
	if (y == 5 && y == count) {
		if (!napalm_achievement_easy) {
			what_are_the_odds = true;
			napalm_achievement_easy = true;
			cout << "Achievement unlocked: What are the Odds\n";
			Sleep(750);
			achievCounter++;
		}
	}
	else if (y == 4 && y == count) {
		if (!napalm_achievement_normal) {
			lend_lease_biatch = true;
			napalm_achievement_normal = true;
			cout << "Achievement unlocked: Lend-Lease, Biatch\n";
			Sleep(750);
			achievCounter++;
		}
	}
	else if (y == 3 && y == count) {
		if (!napalm_achievement_hard) {
			burn_orcs = true;
			napalm_achievement_hard = true;
			cout << "Achievement unlocked: Burn, Orcs\n";
			Sleep(750);
			achievCounter++;
		}
	}
}

void Board::napalm(char a, int b, char c) {

	int x = convertCoordinateToInt(a);
	int y = 5;
	int count = 0;

	if (difficulty == 2) {
		y--;
	}

	if (difficulty == 3) {
		y -= 2;
	}

	switch (c) {
	case 'u':
		if ((b - y) < 0) {
			do {
				y--;
			} while ((b - y) < 0);
		}
		for (int i = (b - 1); i >= (b - y); i--) {
			if (board[i][x] != "[ ]" && board[i][x] != "[O]") {
				privateBoard[i][x] = "[X]";
				count++;
				score += (100 * scoreMult);
				scoreMult += 1;
				missCounter = 0;
			}
			else {
				privateBoard[i][x] = "[O]";
				board[i][x] = "[O]";
			}
		}

		check_napalm_achievement(y, count);
		count = 0;

		break;
	case 'd':
		if ((b + y - 1) > 10) {
			do {
				y--;
			} while ((b + y - 1) > 10);
		}
		for (int i = (b - 1); i < (b - 1 + y); i++) {
			if (board[i][x] != "[ ]" && board[i][x] != "[O]") {
				privateBoard[i][x] = "[X]";
				count++;
				score += (100 * scoreMult);
				scoreMult += 1;
				missCounter = 0;
			}
			else {
				privateBoard[i][x] = "[O]";
				board[i][x] = "[O]";
			}
		}
		check_napalm_achievement(y, count);
		count = 0;

		break;
	case 'l':
		if ((x - y + 1) < 0) {
			do {
				y--;
			} while ((x - y + 1) < 0);
		}
		for (int i = (x); i >= (x - y + 1); i--) {
			if (board[b - 1][i] != "[ ]" && board[b - 1][i] != "[O]") {
				privateBoard[b - 1][i] = "[X]";
				count++;
				score += (100 * scoreMult);
				scoreMult += 1;
				missCounter = 0;
			}
			else {
				privateBoard[b - 1][i] = "[O]";
				board[b - 1][i] = "[O]";
			}
		}
		check_napalm_achievement(y, count);
		count = 0;

		break;
	case 'r':
		if ((x + y) > 10) {
			do {
				y--;
			} while ((x + y) > 10);
		}
		for (int i = (x); i < (x + y); i++) {

			if (board[b - 1][i] != "[ ]" && board[b - 1][i] != "[O]") {
				privateBoard[b - 1][i] = "[X]";
				count++;
				score += (100 * scoreMult);
				scoreMult += 1;
				missCounter = 0;
			}
			else {
				privateBoard[b - 1][i] = "[O]";
				board[b - 1][i] = "[O]";
			}
		}
		check_napalm_achievement(y, count);
		count = 0;

		break;
	}
}

bool Board::check_game() {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (privateBoard[i][j] == "[X]")
				count++;
		}
	}

	return count == 17;
}

bool check_input(string s) {
	if (s.length() == 1) {
		switch (s[0]) {
		case 'x':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
			break;
		default:
			return false;
		}
	}
	else if (s.length() < 2 || s.length() > 3) {
		return false;
	}

	else if (s[0] < 'a' || s[0] > 'n') {
		return false;
	}

	else if (s[1] < '1' || s[1] > '9') {
		return false;
	}
	if (s.length() == 3 && (s[1] != '1' || s[2] != '0')) {
		return false;
	}

	return true;
}

bool check_menu_input(string g) {

	if (g.length() != 1) {
		return false;
	}
	switch (g[0]) {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
		break;
	default:
		return false;
	}
	return true;
}

bool check_end_input(string g) {
	if (g.length() != 1) {
		return false;
	}
	switch (g[0]) {
	case 'y':
	case 'n':
		break;
	default:
		return false;
	}
	return true;
}

bool check_missile_input(string i) {
	if (i.length() != 2) {
		return false;
	}
	else if (i[0] < 'a' || i[0] > 'j') {
		return false;
	}
	else if (i[1] < '1' || i[1] > '9') {
		return false;
	}
	if (i.length() == 3 && (i[1] != '1' || i[2] != '0')) {
		return false;
	}
	return true;
}

bool check_napalm_input(string k) {
	if (k.length() != 3 && k.length() != 4) {
		return false;
	}
	else if (k[0] < 'a' || k[0] > 'j') {
		return false;
	}
	else if (k[1] < '1' || k[1] > '9') {
		return false;
	}
	if (k.length() == 4 && (k[1] != '1' || k[2] != '0')) {
		return false;
	}
	switch (k[k.length()-1]) {
	case 'r':
	case 'l':
	case 'u':
	case 'd':
		break;
	default:
		return false;
	}

	return true;
}

char Board::convertCoordinateToChar(int x) {
	char charvalue = (char(x) + 65);
	return charvalue;
}

int Board::convertCoordinateToInt(char a) {
	int x = 0;
	switch (a) {
	case 'a':
		x = 0;
		break;
	case 'b':
		x = 1;
		break;
	case 'c':
		x = 2;
		break;
	case 'd':
		x = 3;
		break;
	case 'e':
		x = 4;
		break;
	case 'f':
		x = 5;
		break;
	case 'g':
		x = 6;
		break;
	case 'h':
		x = 7;
		break;
	case 'i':
		x = 8;
		break;
	case 'j':
		x = 9;
		break;
	}
	return x;
}

void Board::convertCoordinateToInt2(char a) {
	switch (a) {
	case 'a':
		z = 0;
		break;
	case 'b':
		z = 1;
		break;
	case 'c':
		z = 2;
		break;
	case 'd':
		z = 3;
		break;
	case 'e':
		z = 4;
		break;
	case 'f':
		z = 5;
		break;
	case 'g':
		z = 6;
		break;
	case 'h':
		z = 7;
		break;
	case 'i':
		z = 8;
		break;
	case 'j':
		z = 9;
		break;
	}
}

void space() {
	cout << " \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Board::print_message(string msg) {
	message = msg;
	cout << "Battle log: " << message << endl;
}

void Board::placeShip(Battleship ship) {
	int a = ship.getSize(); //assigns ship size to variable a

	int verticalOrientation;
	bool available;
	int row, col;
	do { //loop will run until the random values of row and col do not collide with an occupied space
		available = true;
		row = rand() % 10;
		col = rand() % (10 - a);

		// randomize veritical and horizontal setting
		verticalOrientation = rand() % 2;
		if (verticalOrientation)
		{
			for (int i = 0; i < a; i++)
			{
				if (board[row][i + col] != "[ ]") // "[ ]" represents an empty space on the board
				{
					available = false; //will break out of loop and start over with a new random value if current coordinates collide
					break;
				}
			}
		}
		else {

			swap(row, col); //swaps row and col to invert orientation
			for (int i = 0; i < a; i++)
			{
				if (board[i + row][col] != "[ ]") // "[ ]" represents an empty space on the board
				{
					available = false;
					break; //same bounds checking code for the other orientation, but with reversed indexes
				}
			}
		}

	} while (!available);

	if (verticalOrientation) {
		for (int i = 0; i < a; i++)
		{
			if (i + col > 9) {
				cout << "out of bounds" << endl;
				exit(EXIT_SUCCESS); 	//this is to exit the program if we encounter boundary errors, but we shouldn't
			}
			board[row][i + col] = "[" + string(ship.getType()) + "]";
		}	//prints the ship's assigned letter to represent occupied space by that ship
	}
	else {
		for (int i = 0; i < a; i++)
		{
			if (i + row > 9) {
				cout << "out of bounds" << endl;
				exit(EXIT_SUCCESS);
			}
			board[i + row][col] = "[" + string(ship.getType()) + "]";
		}
	}
}