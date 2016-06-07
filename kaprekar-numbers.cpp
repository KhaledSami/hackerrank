// https://www.hackerrank.com/challenges/kaprekar-numbers

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string TrimString(string str) {
    str.erase(0, str.find_first_not_of('0'));
    return str;
}
bool IsKaprekar(long long num) {
    string num_square = std::to_string(num * num);
    int d = std::to_string(num).size();
    auto right = TrimString(num_square.substr(num_square.size() - d));
    auto left = TrimString(num_square.substr(0, num_square.size() - d));
    long long left_value = left.empty() ? 0 : std::stoll(left);
    long long right_value = right.empty() ? 0 : std::stoll(right);
    return (left_value + right_value == num);
}
int main() {
    int q, h;
    cin >> q >> h;
    bool valid = false;
    string sep = "";
    for (int i = q ; i <= h ; i++) {
        if (IsKaprekar(i)) {
            cout << sep << i;
            sep = " ";
            valid = true;
        }
    }
    if (!valid) {
        cout << "INVALID RANGE";
    }
    return 0;
}
