#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> s) {
    if (s.empty()) return;
    int e = s.top();
    s.pop();
    printStack(s);
    cout << e << " ";
    s.push(e);
}

void insert(stack<int> &s, int e) {
    if (s.empty() || s.top() <= e) {
        s.push(e);
        return;
    }

    int temp = s.top();
    s.pop();
    insert(s, e);
    s.push(temp);
}

void sortStack(stack<int> &s) {
    if (s.empty()) return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insert(s, temp);
}

int main(void) {
    int n;
    cin >> n;

    stack<int> s;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.push(temp);
    }
    sortStack(s);
    printStack(s);
    cout << endl;
}