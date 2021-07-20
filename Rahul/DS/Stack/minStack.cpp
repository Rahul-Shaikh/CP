#include <iostream>
#include <stack>

using namespace std;


class MinStack {
    stack<int> s;
    int min_ele;

    public:
    int getMin() {return min_ele;}

    void push(int i) {
        if (i <= min_ele) {
            s.push(2*i-min_ele);
            min_ele = i;
        }
        else s.push(i);
    } 

    void pop() {
        if (s.top() < min_ele) {
            min_ele = 2*min_ele - s.top();
        }

        s.pop();
    }

    int top() {
        if (s.top() < min_ele) {
            return min_ele;
        }
        return s.top();
    }
};

int main(void) {
    MinStack s;
    s.push(5);
    s.push(10);
    cout << s.top() << " " << s.getMin() <<endl;
    s.push(1);
    cout << s.top() << " " << s.getMin() <<endl;
    s.pop();
    cout << s.top() << " " << s.getMin() <<endl;
    s.pop();
    cout << s.top() << " " << s.getMin() <<endl;
}