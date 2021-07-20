#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    int n; 
    cin >> n;

    int toys[n];
    for (int i = 0; i < n; i++) cin >> toys[i];

    int i = 0, j = 0;
    int idx = -1, len = 0;
    unordered_map<int, int> hash;
    int count = 0;
    while (j < n) {
        // cout << i << endl;
        // if (hash.find(toys[j]) == hash.end()) count++;
        // else if (hash[toys[j]] == 0) count++;
        // hash[toys[j]]++;

        // if (count < 2) j++;
        // else if (count == 2) {
        //     if (j - i + 1 > len) {
        //         len = j - i +1;
        //         idx = i;
        //     }
        //     j++;
        // }
        // else {
        //     while (count > 2) {
        //         hash[toys[i]]--;
        //         if (hash[toys[i]] == 0) count--; 
        //         i++;
        //     }
        // }
        // cout << i << " " << j << endl;
        hash[toys[j]]++;

        if (hash.size() < 2) j++;
        else if (hash.size() == 2) {
            if (j - i + 1 > len) { 
                len = j - i +1;
                idx = i;
            }
            j++;
        }
        else  {
            while (hash.size() > 2) {
                hash[toys[i]]--;
                if (hash[toys[i]] == 0) hash.erase(toys[i]);
                i++;
            }
            j++;
        }
    }

    cout << len << endl;
}