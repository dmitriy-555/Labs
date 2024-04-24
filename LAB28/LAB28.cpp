#include <iostream>
#include <map>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    map<string, string> dictionary{
        {"яблоко", "elma"},
        {"стол", "masa"},
        {"книга", "kitap"},
        {"машина", "araba"},
        {"солнце", "güneş"},
        {"дом", "ev"},
        {"вода", "su"},
        {"цветок", "çiçek"},
        {"кошка", "kedi"},
        {"собака", "köpek"},
        {"звезда", "yıldız"},
        {"дерево", "ağaç"},
        {"небо", "gökyüzü"},
        {"рука", "el"},
        {"нос", "burun"},
        {"глаз", "göz"},
        {"рот", "ağız"},
        {"ухо", "kulak"},
        {"нога", "ayak"},
        {"книжка", "kitapçık"} // Добавлено одно слово для достижения 20 слов
    };

    cout << "Русско-турецкий словарь:" << endl;
    for (const auto& pair : dictionary) {
        cout << pair.first << " - " << pair.second << endl;
    }

    cout << endl << "Введите слово для перевода с русского на турецкий:" << endl;
    string russianWord;
    cin >> russianWord; // Считываем всю строку, включая пробелы
    cout << russianWord;
    auto it = dictionary.find(russianWord);
    if (it != dictionary.end()) {
        cout << "Перевод слова \"" << russianWord << "\": " << it->second << endl;
    }
    else {
        cout << "Слово \"" << russianWord << "\" не найдено в словаре." << endl;
    }

    return 0;
}
