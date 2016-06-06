// https://www.hackerrank.com/challenges/the-time-in-words

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const string numbers [] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string GetTheNumber(int x) {
    if (x < 20) {
        return numbers[x];
    }
    return "twenty" + (x - 20 > 0 ? " " + numbers[x - 20] : "");
}
string GetTime(int h, int m) {
    if (m == 0) {
        return numbers[h] + " o' clock";
    }
    if (m == 15) {
        return "quarter past " + numbers[h];
    }
    if (m == 30) {
        return "half past " + numbers[h];
    }
    if (m == 45) {
        return "quarter to " + numbers[h + 1];   
    }
    return GetTheNumber(m < 30 ? m : 60 - m) + (m == 1 ? " minute" : " minutes") + (m < 30 ? " past "  : " to ") +             numbers[m < 30 ? h : h + 1];    
}
int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    cout << GetTime(h, m);
    return 0;
}
