#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<char> set;
    
    string seq;
    getline(cin, seq);

    for (char str : seq) {
        if (ispunct(str)) {
            set.insert(str);
        }

    }

    for (char str : set) {
        cout << str << " ";
    }

    return 0;
}

