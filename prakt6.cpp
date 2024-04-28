#include <iostream>
#include <vector>
#include <locale>
#include <Windows.h>
#pragma execution_character_set("utf-8")
#include <limits>

using namespace std;

class Student {
private:
    vector<string> group;
    vector<string> disciplines;
    int SdanRab;//сданные работы
    int dolgi;

public:
    Student(vector<string> group, vector<string> disciplines, int SdanRab, int dolgi) {
        this->group = group;
        this->disciplines = disciplines;
        this->SdanRab = SdanRab;
        this->dolgi = dolgi;
    }

    void addSdanRab() {
        SdanRab++;
    }

    void addDolgi() {
        dolgi++;
    }

    int getSdanRab() {
        return SdanRab;
    }

    int getDolgi() {
        return dolgi;
    }

    void removeGroup() {
        group.clear();
    }
};

class Prepod {
private:
    vector<string> group;
    vector<string> disciplines;
public:
    Prepod(vector<string> group, vector<string> disciplines) {
        this->group = group;
        this->disciplines = disciplines;
    }

    void checkStudent(Student& student) {
        if (student.getSdanRab() < 5) {
            cout << "Студент сдал менее 5 работ и должен быть удален из группы" << endl;
            student.removeGroup();
        }
    }
};

class MPT {
private:
    int kolvostud = 0;
    int kolvorabot = 0;

    void dobavlStudent() {
        kolvostud += 1;
    }
    void dobavlksdanrabotam() {
        kolvorabot += 1;
    }
    void dobavknesdanrabota() {
        kolvorabot -= 1;
    }
};

int main()
{
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF-8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF-8
    bool pravda = true;
    cout << "Добро пожаловать в мпт" << endl;
    string group;
    cout << "Введите группу: " << endl;
    cin >> group;

        int number;//количество групп
        cout << "Введите количество дисциплин, которые ведет преподаватель" << endl;
        cin >> number;

    vector<string> disciplines;
    for (int i = 0; i < number; i++) {
        string discipline;
        cout << "Введите дисциплину" << endl;
        cin >> discipline;
        disciplines.push_back(discipline);//закидываю переменную в вектор
    }
    int kolvostud = 0;
    int kolvorabot = 0;
    Student student({ group }, disciplines, 0, 0);
    Prepod prepod({ group }, disciplines);
    MPT mpt;

    while (pravda) {
        int vybor;
        cout << "Выберите действие\n1. Количество студентов на паре\n2. Добавить студента в группу\n3. Посмотреть кол-во работ\n4. Добавить сданную/не сданную работу\n5. Выход\n"; //валидация
        cin >> vybor;
        if (vybor == 1) {
            cout << "Количество студентов на паре: " << kolvostud << endl;
        }
        else if (vybor == 2) {
            int dobavkol;
            cout << "Сколько студентов хотите добавить?\n";
            cin >> dobavkol;
            kolvostud += dobavkol;
            cout << "Студент добавлен в группу" << endl;
        }
        else if (vybor == 3) {
            cout << "Количество работ: " << kolvorabot << endl;
            if (kolvorabot == -5) {
                kolvostud -= 1;
                cout << "Студент удален за неуспеваемость\n";
            }
        }
        else if (vybor == 4) {
            int dobavraboti;
            cout << "Вы хотите добавить сданную или не сданную работу?\n1 - сданная\n2 - не сданная\n";
            cin >> dobavraboti;
            switch (dobavraboti) {
                case 1:
                int dobavkol;
                cout << "Сколько работ сданных работ хотите добавить?\n";
                cin >> dobavkol;
                kolvorabot += dobavkol;
                cout << "Сданная работа добавлена\n";
                case 2:
                cout << "Сколько работ не сданных работ хотите добавить?\n";
                cin >> dobavkol;
                kolvorabot -= dobavkol;
                cout << "Несданная работа добавлена\n";
                default:
                    cout << "Другая цифра нужна\n" << endl;
                    break;
            }
        }
        else if (vybor == 5) {
            pravda = false;
        }
        else {
            cout << "Неверный выбор, введите число от 1 до 5\n";
        }
    }
}
