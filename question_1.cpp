// question_1.cpp
#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
    } else {
        int temp = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(temp);
    }
}

// Function to reverse the stack
void reverseStack(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s, temp);
    }
}

int main() {
    stack<int> s;
    s.push(28);
    s.push(29);
    s.push(30);
    s.push(31);

    reverseStack(s);

    cout << "Reversed stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
