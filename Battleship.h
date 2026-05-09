#pragma once
#include <iostream>
#include <string>


using namespace std;

class Battleship
{
private:
	const char* type;

public:
	Battleship(const char* a);
	int getSize();
	const char* getType();

};
