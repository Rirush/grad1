#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream in("t10.in");
    ofstream out("t10.out");

    if(!in.is_open()) {
        cout << "Невозможно открыть входной файл";
        return 0;
    }
    if(!out.is_open()) {
        cout << "Невозможно открыть выходной файл";
        return 0;
    }

    string code;
    int input;
    in >> input;
    if(!in.good()) {
        cout << "Невозможно прочитать число";
        return 0;
    }
    do {
        if(input % 4 == 0) {
            code = 'D' + code;
            input = (input - 1) / 4;
        } else {
            code = (char)('A' + ((input - 1) % 4)) + code;
            input = input / 4;
        }
    } while(input > 0);
    out << code;
}