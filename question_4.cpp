// Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue. question_4.cpp
#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> temp;

    // Add half elements to the temporary queue
    for (int i = 0; i < n / 2; i++) {
        temp.push(q.front());
        q.pop();
    }

    // Interleave elements
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    interleaveQueue(q);

    cout << "Rearranged queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
