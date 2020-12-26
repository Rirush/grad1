#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Word {
    string w;
    string c;
};

bool operator<(const Word &l, const Word &r) {
    return l.c < r.c;
}

int main() {
    ifstream in("t1.in");
    ofstream out("t1.out");
    vector<Word> words;

    if(!in.is_open()) {
        cout << "Невозможно открыть входной файл";
        return 0;
    }
    if(!out.is_open()) {
        cout << "Невозможно открыть выходной файл";
        return 0;
    }

    string w;
    while(in >> w) {
        if(!in.good()) {
            cout << "Ошибка чтения из файла";
            return 0;
        }
        string c = w;
        sort(c.begin(), c.end());
        words.push_back(Word{w,c});
    }
    sort(words.begin(), words.end());

    bool found = false;
    for(int i = 1; i < words.size(); i++) {
        if(words[i-1].c == words[i].c) {
            out << words[i-1].w << endl;
            found = true;
        } else if(found) {
            out << words[i-1].w << endl << endl;
            found = false;
        }
    }
    if(found) {
        out << words[words.size()-1].w << endl;
    }
}