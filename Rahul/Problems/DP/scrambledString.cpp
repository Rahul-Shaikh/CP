#include <iostream>
#include <cstring>
#include <unordered_map>
#include <set>


using namespace std;

bool solve(string s1, string s2, unordered_map<string, bool> &hash) {
    if (s1.size() != s2.size()) return false;

    if (s1.compare(s2) == 0) return true;

    if (s1.size() <= 1) return false;

    int n = s1.size();
    bool flag = false;
    for (int i = 1; i <= s1.size()-1; i++) {
        bool cond1 = solve(s1.substr(0, i), s2.substr(0, i), hash) && solve(s1.substr(i), s2.substr(i), hash);
        bool cond2 = solve(s1.substr(0, i), s2.substr(n-i), hash) && solve(s1.substr(i), s2.substr(0, n-i), hash); 

        if (cond1 || cond2) {
            flag = true;
            break;
        }
    }

    return flag;

}

int main(void) {
    string str1, str2;
    cin >> str1 >> str2;

    unordered_map<string, bool> hash;
    cout << solve(str1, str2, hash) << endl;
}