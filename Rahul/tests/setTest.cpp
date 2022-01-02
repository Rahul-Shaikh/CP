#include <iostream>
#include <functional>
#include <set>

using namespace std;

bool cmp(int i, int j) { return i> j; }

class MyCmp {
    public:
    bool operator() (int i, int j) {
        return i > j;
    }
};

int main(void)
{
    // set<int> s;
    // set<int, greater<int> > s;
    // set<int, cmp> s; ////////error
    // set<int, MyCmp> s;
    set<int, decltype(&cmp)> s(&cmp);

    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(3);

    for (set<int>::iterator i = s.begin(); i != s.end(); i++) cout << *i << " ";
    cout << endl;
}