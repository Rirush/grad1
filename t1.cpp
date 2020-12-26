#include <fstream>
#include <set>
#include <vector>
#include <string>

using namespace std;

struct Word {
    string w;
    multiset<char> c;
};

int main() {
    ifstream in("t1.in");
    ofstream out("t1.out");
    vector<Word> words;

    string w;
    while(in >> w) {
        multiset<char> c;
        for(char ch : w) {
            c.insert(ch);
        }

        words.push_back(Word{w,c});
    }
    
    vector<bool> analyzed(words.size());
    for(int i = 0; i < words.size(); i++) {
        if(analyzed[i]) {
            continue;
        }
        analyzed[i] = true;
        bool found = false;
        vector<string> collisions;
        collisions.push_back(words[i].w);
        for(int j = 0; j < words.size(); j++) {
            if(analyzed[j]) {
                continue;
            }
            if(words[i].c == words[j].c) {
                found = true;
                analyzed[j] = true;
                collisions.push_back(words[j].w);
            }
        }
        if(found) {
            for(string s : collisions) {
                out << s << endl;
            }
            out << endl;
        }
    }
}