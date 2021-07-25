#include <iostream>

using namespace std;

void permute(string s, int st, int en) {
    if (st == en) {
        cout << s << endl;
    }

    for (int i = st; i <= en; i++) {
        swap(s[i], s[st]);

        permute(s, st + 1, en);

        swap(s[i], s[st]);
    }
}

int main(void) {
    string s;
    cin >> s;

    permute(s, 0, s.size()-1);
}