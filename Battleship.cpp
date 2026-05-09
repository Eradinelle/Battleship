#include "Battleship.h"
#include <iostream>
#include <string>

using namespace std;

Battleship::Battleship(const char* a)
{
	type = a;
}

//this function returns the int size of each ship based on the char that each ship starts with
int Battleship::getSize() {
	switch (type[0]) {
	case 'F':
		return 2;
		break;
	case 'S':
		return 3;
		break;
	case 'D':
		return 3;
		break;
	case 'B':
		return 4;
		break;
	case 'A':
		return 5;
		break;
	}
}
const char* Battleship::getType() { 
	return type;
}
