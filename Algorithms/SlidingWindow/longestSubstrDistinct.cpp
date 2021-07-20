#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    int i = 0, j = 0, prev_j = -1;
    int idx = -1, len = 0;
    unordered_map<char, int> hash;
    bool flag = 0;
    while (j < s.size()) {
        hash[s[j]]++;

        if (hash.size() < j - i + 1) {
            hash.erase(s[i]);
            i++;
        }
        else if (hash.size() == j-i+1) {
            if (j-i+1 > len) {
                len = j-i+1;
                idx = i;
            }
            j++;
        }
    }

    cout << s.substr(idx, len);
}