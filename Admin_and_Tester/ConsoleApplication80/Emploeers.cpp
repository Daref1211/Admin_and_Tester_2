
#include "Emploeers.h"  

Emploeers::Emploeers(const string& id, const string& file1, const string& file2, const string& file3) {
    this->id = id; 
    string tmp_id, tmp_name, tmp_firstname, tmp_age;
    bool found = false;  

    // ������ ������ �� ������  
    const string files[3] = { file1, file2, file3 };
  
    for (const auto& filename : files) {
        fstream read_db(filename);

        if (!read_db.is_open()) {
            cerr << "������ �������� �����: " << filename << endl;
            continue; // ������� � ���������� ����� ���� �� ������� ������� �������  
        }

        while (read_db >> tmp_id >> tmp_name >> tmp_firstname >> tmp_age) {
            if (tmp_id == id) {
                name = tmp_name;
                firstname = tmp_firstname;
                age = tmp_age;
                found = true;
                break;
            }
        }
        if (found) {
            break; 
        }
    } 
    if (!found) {
        cout << "��������� � ID " << id << " �� ������ � ��������� ������." << endl;
    }
}

void Emploeers::show() {
    cout << "\n���������!" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Firstname: " << firstname << endl;
    cout << "Age: " << age << endl;
}