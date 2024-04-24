#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void readMatrix(int matrix[5][9], const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Невозможно открыть файл! ");
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!(file >> matrix[i][j])) {
                throw runtime_error("Невозможно читать из файла! ");
            }
        }
    }
    file.close();
}

void processMatrix(int matrix[5][9]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (matrix[i][j] > 0) {
                matrix[i][j] = -matrix[i][j];
            }
            else {
                matrix[i][j] = 0; 
            }
        }
    }
}

void printMatrix(const int matrix[5][9]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void writeMatrix(const int matrix[5][9], const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Невозможно записать в файл! ");
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "rus");
    int matrix[5][9];

    try {
        readMatrix(matrix, "input_matrix.txt");

        processMatrix(matrix);

        cout << "Обработанная матрица:" << endl;
        printMatrix(matrix);

        writeMatrix(matrix, "output_matrix.txt");
    }
    catch (const runtime_error e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1; 
    }

    return 0;
}
