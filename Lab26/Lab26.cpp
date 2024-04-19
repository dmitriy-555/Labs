#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string Name;
    string Color;
};

bool compareStudents(Student p1, Student p2) {
    return p1.Name < p2.Name;
}

int main() {
    setlocale(LC_ALL, "rus");

    ifstream inputFile("inputFile.txt");
    if (!inputFile) {
        cerr << "Ошибка: невозможно открыть файл!" << endl;
        return 0;
    }

    vector<Student> students;

    string Name, Color;
    while (inputFile >> Name >> Color) {
        Student st = { Name, Color };
        students.push_back(st);
    }

    inputFile.close();

    sort(students.begin(), students.end(), compareStudents);

    ofstream outputFile("outputFile.txt");
    for (int i = 0; i < students.size(); i++) {
        outputFile << "ФИО: " << students[i].Name << ", цвет волос: " << students[i].Color << endl;
    }

    return 0;
}
