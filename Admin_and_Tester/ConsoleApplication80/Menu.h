
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Menu
{
private:

public:
	Menu();
	void showMain();
	void showLogo();
	bool Auth(string filename, string login, string pass, string& id);

};

