
#include <iostream>  
#include <fstream>  
using namespace std;

class Emploeers {
private:
    string id;
    string name;
    string firstname;
    string age;

public:
    // ����������� ��� ������ ���������� �� ID � ���������� ������  
    Emploeers(const string& id, const string& file1, const string& file2, const string& file3);
    void show();
};
