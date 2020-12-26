#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("t9.in");
    ofstream out("t9.out");

    if(!in.is_open()) {
        cout << "Невозможно открыть входной файл";
        return 0;
    }
    if(!out.is_open()) {
        cout << "Невозможно открыть выходной файл";
        return 0;
    }

    int n;
    in >> n;
    if(!in.good()) {
        cout << "Невозможно прочитать размер массива";
        return 0;
    }

    vector<int> k;
    for(int i = 0; i < n; i++) {
        int ki;
        in >> ki;
        if(!in.good()) {
            cout << "Невозможно прочитать элемент массива";
            return 0;
        }
        if(none_of(k.begin(), k.end(), [ki](int i){ return i == ki; })) {
            k.push_back(ki);
        }
    }
    for(int v : k) {
        out << v << " ";
    }
}