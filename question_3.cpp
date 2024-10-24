// 3. Given an array and a positive integer k, find the first negative integer for each window (contiguous subarray) of size k. question_3.cpp
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printFirstNegativeInWindow(const vector<int>& arr, int k) {
    deque<int> negatives;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Remove elements out of the current window
        if (!negatives.empty() && negatives.front() == i - k) {
            negatives.pop_front();
        }
        // Add current element's index if it is negative
        if (arr[i] < 0) {
            negatives.push_back(i);
        }
        // Print the first negative integer for the current window
        if (i >= k - 1) {
            if (!negatives.empty()) {
                cout << arr[negatives.front()] << " ";
            } else {
                cout << "0 ";
            }
        }
    }
}

int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    printFirstNegativeInWindow(arr, k);
    return 0;
}
