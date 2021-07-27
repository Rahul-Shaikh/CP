#include <iostream>

using namespace std;

void printAns(string s, string ans, int i) {
    if (s.size() == 0) return;

    if (i == s.size()-1) {
        ans.push_back(s[i]);
        cout << ans << endl;
        return;
    }

    ans.push_back(s[i]);
    printAns(s, ans, i+1);
    ans.push_back('_');
    printAns(s, ans, i+1);
}

int main(void) {
    string s;
    cin >> s;

    printAns(s, "", 0);
}