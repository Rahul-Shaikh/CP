#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> rstack, mstack;

public:
    int getMin() { return mstack.top(); }
    
    void pop() {
        if (rstack.top() == mstack.top()) {
            mstack.pop();
        }
        rstack.pop();
    }

    void push(int i) {
        if (mstack.empty()) mstack.push(i);
        else if (mstack.top() >= i) mstack.push(i);
        
        rstack.push(i);
    }

    int top() {return rstack.top();}
};

int main(void) {
    MinStack ms;
    ms.push(9);
    ms.push(2);
    ms.push(8);
    cout << ms.top() << " " << ms.getMin() << endl;
    ms.push(1);
    cout << ms.top() << " " << ms.getMin() << endl;
    ms.push(10);
    ms.push(9);
    cout << ms.top() << " " << ms.getMin() << endl;
    ms.pop();
    ms.pop();
    ms.pop();
    cout << ms.top() << " " << ms.getMin() << endl;
}