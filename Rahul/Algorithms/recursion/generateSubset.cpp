#include <iostream>

using namespace std;

void generate(string s, string ans, int i) {
    if ( i >= s.size()) {
        cout << ans << endl;
        return;
    }

    generate(s, ans + s[i], i+1);
    generate(s, ans, i+1);


}

int main(void) {
    string s;
    cin >> s;

    generate(s, "", 0);
    cout << "end" << endl;
}