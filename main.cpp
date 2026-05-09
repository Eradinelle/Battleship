#include <iostream>
#include "Board.h"
#include "Battleship.h"
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

void play_game() {
	system("color 02");

	// seed the random value generator
	srand(time(NULL));

	Board b;


	Battleship Frigatte("F");
	Battleship Submarine("S");
	Battleship Destroyer("D");
	Battleship BattleShip("B");
	Battleship AircraftCarrier("A");

	b.placeShip(Frigatte);
	b.placeShip(Submarine);
	b.placeShip(Destroyer);
	b.placeShip(BattleShip);
	b.placeShip(AircraftCarrier);

	b.welcomeScreen();
	b.mainMenu();

	do {
		b.printPrivateBoard();
		cout << endl;
		b.missHit();

	} while (!b.check_game());

	b.end_game = true;
	b.achievements_check();
	cout << endl << "YOU'VE WON!" << endl << endl;

	system("pause");

	ofstream file("Battleship high score", ofstream::trunc);
	file << b.highScore;
}


int main() {

	do {
		play_game();
	} while (true);

	return 0;
}