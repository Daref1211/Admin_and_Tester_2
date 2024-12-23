#include "Menu.h"
#include "Emploeers.h"  
#include "Admin.h"
#include "Menu.h"  
#include "Quiz.h"
using namespace std;

Menu::Menu() {
    
}

void Menu::showLogo() {
    cout << "\033[031m" << " $$$$$$\\                                                   ##        $$\\               \n\033[0m";
    cout << "\033[031m" << "$$  __$$\\                                                           $$ |              \n\033[0m";
    cout << "\033[031m" << "$$ /  \\__| $$$$$$\\      $$$$$$$\\ $$\\   $$ | \\$$$$$$\\ $$ |\\$$$$$$$$\\   $$ |\\$$ |\\\n\033[0m";
    cout << "\033[031m" << "\\$$$$$$\\  $$  __$$\\   $$  _____| $$ |   $$ | $$   _ $$\\$$ |\\_$$  _|     $$ |  $$ |\n\033[0m";
    cout << "\033[031m" << " \\____$$\\ $$$$$$$$    $$  /       $$ |   $$ | $$ /  \_/  $$ |  $$ |       $$ |  $$ |\n\033[0m";
    cout << "\033[031m" << "$$\\   $$ | $$  ____   $$ |         $$ |   $$ | $$ |       $$ |  $$ | $$\\ $$ |  $$ |\n\033[0m";
    cout << "\033[031m" << "\\$$$$$$  | \\$$$$$$$\\  \\$$$$$$$\\\\$$$$$$ /  $$ |       $$ |  \\$$$$ |\\$$$$$$$ |\n\033[0m";
    cout << "\033[031m" << " \\______/   \\_______|   \\_______|\\______/  \\__|     \\$$ | \\_____/ \\____$$ |\n\033[0m";
    cout << "\033[031m" << "                                                                          $$\\ $$ |\n\033[0m";
    cout << "\033[031m"<< "                                                                        \\$$$$$$ |\n\033[0m";
    cout << "\033[031m" << "                                                                        \\______/ \n\033[0m";
}

bool Menu::Auth(string filename, string login, string pass, string& id)
{
    string tmp_login, tmp_pass, tmp_id;
    fstream file_read(filename, ios::in);
    bool protect = false;
    while (!file_read.eof()) {
        file_read >> tmp_login >> tmp_pass >> tmp_id;
        if (tmp_login == login && tmp_pass == pass) {
            id = tmp_id;
            protect = true;
            break;
        }
    }
    return protect;
}

void Menu::showMain() {

    string login, pass, id;
    int choice{};
    Menu menu;
    Quiz quiz;
    

    while (true) {
        cout << "Добро пожаловать!" << endl << endl << endl << endl;
        cout << "Выберите действие:" << endl << endl;
        cout << "1 ~ Показать логотип" << endl;
        cout << "2 ~ Авторизоваться" << endl;
        cout << "3 ~ Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            menu.showLogo();
            cout << endl << endl << endl;
            break;

        case 2:
            cout << "Введите ваш логин > ";
            cin >> login;
            cout << "Введите ваш пароль > ";
            cin >> pass;

            if (Auth("Emploeers_1_pass.txt", login, pass, id)) { 
                Emploeers employeers(id,
                    "Emploeers_1.txt",  
                    "Emploeers_2.txt", 
                    "Emploeers_3.txt"    
                );
                employeers.show();
                cout << endl << endl << endl;  
                quiz.start();
                quiz.displayResults();
            }
            else if (Auth("Emploeers_2_pass.txt", login, pass, id)) {
                Emploeers employeers(id,
                    "Emploeers_1.txt",  
                    "Emploeers_2.txt",   
                    "Emploeers_3.txt"  
                );
                employeers.show();
                cout << endl << endl << endl;
                quiz.start();
                quiz.displayResults();
            }
            else if (Auth("Emploeers_3_pass.txt", login, pass, id)) {
                Emploeers employeers(id,
                    "Emploeers_1.txt", 
                    "Emploeers_2.txt", 
                    "Emploeers_3.txt"  
                );
                employeers.show();
                cout << endl << endl << endl;  
                
                quiz.start();
                quiz.displayResults();
            }
            else if (Auth("Admin_pass.txt", login, pass, id)) {
                Admin admin(id);
                admin.show();
                cout << endl << endl << endl;
                quiz.showScore();
            }
            else {
                cout << "Ошибка: неверный логин или пароль!" << endl;
            }
            break;

        case 3:
            system("cls");
            cout << "Выход из программы." << endl;
            break;

        default:
            cout << "Ошибка: такого пункта нет в меню!" << endl;
            break;
        }

        system("pause");
        system("cls");
    }

}