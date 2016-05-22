#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

bool isFunny(const string& s) {
    for (int i = 1; i < s.size(); i++) {
        if (std::abs((int)(s[i] - s[i - 1])) != std::abs((int)(s[s.size() - i - 1] - s[s.size() - i]))) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    string s;
    cin >> t; 
    while (t--) {
        cin >> s;
        if (isFunny(s)) {
            cout << "Funny" << endl;
        } else {
            cout << "Not Funny" << endl;
        }
    }
    return 0;
}
//https://www.hackerrank.com/challenges/funny-string
