
#include "Emploeers.h"  

Emploeers::Emploeers(const string& id, const string& file1, const string& file2, const string& file3) {
    this->id = id; 
    string tmp_id, tmp_name, tmp_firstname, tmp_age;
    bool found = false;  

    // Массив чтения из файлов  
    const string files[3] = { file1, file2, file3 };
  
    for (const auto& filename : files) {
        fstream read_db(filename);

        if (!read_db.is_open()) {
            cerr << "Ошибка открытия файла: " << filename << endl;
            continue; // Переход к следующему файлу если не удалось открыть текущий  
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
        cout << "Сотрудник с ID " << id << " не найден в указанных файлах." << endl;
    }
}

void Emploeers::show() {
    cout << "\nСотрудник!" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Firstname: " << firstname << endl;
    cout << "Age: " << age << endl;
}