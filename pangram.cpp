#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    const int alpha_size = 26;
    bool alpha[alpha_size];
    string str;
    getline(cin, str);
    for (const auto& c : str) {
        alpha[tolower(c) - 'a'] = true;
    }
    bool pangram = true;
    for (int i = 0; i < alpha_size; i++) {
        if (alpha[i] == false) {
            pangram = false;
            break;
        }
    }
    cout << (pangram? "pangram" : "not pangram");
    
    return 0;
}
