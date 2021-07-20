#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    string p;
    cin >> p;
    int n = s.size();
    int k = p.size();

    unordered_map<char, int> hash;
    for (char c: p) hash[c]++;
    int count = hash.size();

    int i = 0, j = 0;
    int ans = 0;
    while (j < n) {
        if (hash.find(s[j]) != hash.end()) {
            hash[s[j]]--;
            if (!hash[s[j]]) count--;
        }

        if (j-i+1 < k) j++;
        else if (j-i+1 == k) {
            if (count == 0) ans++;

            if (hash.find(s[i]) != hash.end()) {
                if (!hash[s[i]]) count++;
                hash[s[i]]++;
            }
            i++, j++;
        }
    }

    cout << ans << endl;
}