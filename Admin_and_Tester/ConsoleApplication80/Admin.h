#pragma once
#include <iostream>
#include <fstream>
#include "Quiz.h"
using namespace std;
class Admin
{
	string id;
	string name, firstname;
	string age;
public:

	Admin(string id);
	void show();
};

