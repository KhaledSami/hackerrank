https://www.hackerrank.com/challenges/encryption

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    int rows = sqrt(s.size());
    int cols = rows;
    if (rows * cols < s.size()) {
        cols++;
    }
    if (rows * cols < s.size()) {
        rows++;
    }
    string sep = "";
    for (int i = 0; i < cols; i++) {
        string word = "";
        int idx = i;
        while (idx < s.size()) {
            word += s[idx];
            idx += cols;
        }
        cout << sep << word;
        sep = " ";
    }
    return 0;
}
