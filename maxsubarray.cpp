#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int GetMaxNonContiguous(const vector<int>& numbers) {
    int answer = 0;
    int max_negative_value = numeric_limits<int>::min();
    bool positive_found = false;
    for (const auto& num : numbers) {
        if (num >= 0) {
            answer += num;
            positive_found = true;
        } else {
            max_negative_value = max(max_negative_value, num);
        }
    }
    return positive_found? answer : max_negative_value;
}

int GetMaxSubArraySum(const vector<int>& numbers) {
    int max_sum = numeric_limits<int>::min();
    int cur_sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (cur_sum + numbers[i] >= 0) {
            cur_sum += numbers[i];
            max_sum = max(max_sum, cur_sum);
        } else {
            max_sum = max(max_sum, numbers[i]);
            cur_sum = 0;
        }
    }
    return max_sum;
}
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        int max_subarray_sum = GetMaxSubArraySum(numbers);
        int max_non_contiguous = GetMaxNonContiguous(numbers);
        printf("%d %d\n", max_subarray_sum, max_non_contiguous);
    }
    return 0;
}
// https://www.hackerrank.com/challenges/maxsubarray
