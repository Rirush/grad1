#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream out("t5.out");
    if(!out.is_open()) {
        cout << "Невозможно открыть выходной файл";
        return 0;
    }
    vector<int> sums;

    for(int t = 1; t < 10; t++) {
        for(int p = 1; p < 10; p++) {
            for(int d = 1; d < 10; d++) {
                for(int y = 0; y < 10; y++) {
                    for(int r = 0; r < 10; r++) {
                        int sum = (t * 100 + y * 10 + r) + (p * 100 + y * 10 + r);
                        if(sum == (d * 100 + y * 10 + r) * 8) {
                            if(none_of(sums.begin(), sums.end(), [sum](int i){ return i == sum; })) {
                                out << sum << endl;
                                sums.push_back(sum);
                            }
                        }
                    }
                }
            }
        }
    }
}