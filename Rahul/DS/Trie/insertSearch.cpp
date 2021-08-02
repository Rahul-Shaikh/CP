#include <iostream>
#include <cstring>
#include <vector>

#define ALPHA_SIZE 26
using namespace std;

class TrieNode {
    public:
    TrieNode* children[ALPHA_SIZE];
    bool isEndOfWord;
    TrieNode() {
        for (int i = 0; i < ALPHA_SIZE; i++) children[i] = NULL;
        isEndOfWord = false;
    }
};

class Trie {
    TrieNode* head;

public:
    Trie() {
        head =  new TrieNode;
    }

    void recurDelete(TrieNode* head) {
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (head->children[i]) {
                recurDelete(head->children[i]);
            }
        }
        delete head;
    }

    ~Trie() {
        recurDelete(head);
    }

    void insert(string s) {
        TrieNode* itr = head;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i]-'a';
            if (!itr->children[idx]) {
                itr->children[idx] = new TrieNode;
            }
            itr = itr->children[idx];
        }

        itr->isEndOfWord = true;
    }

    bool search(string s) {
        TrieNode* itr = head;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i]-'a';
            if (!itr->children[idx]) return false;
            itr = itr->children[idx];
        }

        return itr->isEndOfWord;
    }
};

int main(void) {
    string vals[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    
    Trie tr;
    for (string s: vals) {
        tr.insert(s);
    }

    tr.search("the")? cout << "Yes\n" :
                         cout << "No\n";
    tr.search("these")? cout << "Yes\n" :
                           cout << "No\n";
    tr.search("their")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}