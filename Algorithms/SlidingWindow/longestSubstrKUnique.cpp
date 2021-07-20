#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    int k;
    cin >> k;

    string s;
    cin >> s;

    unordered_map<int, int> hash;
    int count = 0;
    int i = 0, j = 0;
    int idx = -1, len = 0;
    while (j < s.size()) {
        if (hash.find(s[j]) == hash.end()) {
            count++;
        }
        else if (hash[s[j]] == 0) count++;
        hash[s[j]]++;

        if (count < k) j++;
        else if (count == k) {
            if (j - i + 1 > len) {
                len = j - i + 1;
                idx = i;
            }
            // cout << idx << " " << len <<  endl;
            j++;
        } else {
            while (count > k) {
                hash[s[i]]--;
                if (hash[s[i]] == 0) count--;
                i++;
            }
            j++;
        }
    }
    if (idx != -1) cout << s.substr(idx, len) <<  endl;
        else cout << "NA" << endl;
}