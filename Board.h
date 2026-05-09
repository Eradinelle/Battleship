#pragma once
#include "Battleship.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Board
{
private:
	static const int ROWS = 10;
	static const int COLS = 10;

	string board[10][10];
	string privateBoard[10][10];

	int x, z;
	string allias;
	string message = " ";

	enum Difficulty {
		EASY = 1,
		NORMAL = 2,
		HARD = 3,
	} difficulty = EASY;

	int score = 100;
	int missCounter = 0;
	int hitCounter = 0;

	enum Drop {
		FOUND,
		NOT_FOUND,
		USED
	};
	Drop commonDrop = FOUND;
	Drop uncommonDrop = FOUND;
	Drop rareDrop = FOUND;
	int scoreMult = 1;

	bool bribe_fail = false;

	bool heating_up = false; //scoreMult == 2
	bool on_fire = false; //scoreMult == 3
	bool who_is_this_guy = false; //scoreMult == 5
	bool thank_you_for_the_corruption = false; //hit bribe on NORMAL
	bool the_greed_is_real = false; //hit bribe on HARD
	bool nice_plan = false; //if bribe fails on NORMAL, land the next hit
	bool no_one_gets_away = false; //if bribe fails on HARD, land the next hit
	bool precision_baby = false; //land a missile on NORMAL
	bool neptune = false; //land missile on HARD
	bool what_are_the_odds = false; //land 5 hits with napalm on EASY
	bool burn_orcs = false; //land 3 hits with napalm on NORMAL
	bool lend_lease_biatch = false; //land 4 hits with napalm on HARD
	bool feeling_cheeky = false; // don't use any drops on EASY
	bool didnt_need_em = false; //don't use any drops on NORMAL
	bool i_gots_this = false; //don't use any drops on HARD
	bool collector = false; //collect all drops on NORMAL
	bool master_collector = false; //collect all drops on HARD

	bool missile_achievement = false;
	bool napalm_achievement_easy = false;
	bool napalm_achievement_normal = false;
	bool napalm_achievement_hard = false;
	
	int achievCounter = 0;

public:
	bool end_game = false;
	void welcomeScreen();
	void mainMenu();
	void instructions();
	void selectDifficulty();
	void achievements_tab();
	void achievements_check();
	void printPrivateBoard();
	void missHit();
	void turn();
	void randomDrop(int a);
	bool bribe(int a);
	void missile(char c, int y);
	void napalm(char a, int b, char c);
	void check_napalm_achievement(int y, int count);
	bool check_game();
	char convertCoordinateToChar(int x);
	int convertCoordinateToInt(char a);
	void convertCoordinateToInt2(char a);
	void print_message(string msg);
	void placeShip(Battleship ship);

	int highScore;
	
	Board() {
		//constructor, initializes array with empty spaces
		setUpPrivateBoard();
		ifstream file("Battleship high score", ifstream::in);
		if (file.is_open()) {
			file >> highScore;
		}
		else {
			highScore = 0;
		}
	}
	void setUpPrivateBoard() {
		for (int r = 0; r < ROWS; r++)
		{
			for (int c = 0; c < COLS; c++)
			{
				board[r][c] = "[ ]";
				privateBoard[r][c] = "[ ]";
			}
		}
	}
};