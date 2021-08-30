/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* prev = NULL, *head = NULL;
    void convert(Node* root) {
        if (!root) return;
        
        convert(root->left);
        
        if (!prev) {
            head = root;
        }
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        convert(root->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        convert(root);
        if (!root) return NULL;
        head->left = prev;
        prev->right = head;
        // while (curr) {
        //     cout << curr->val << " ";
        //     prev = curr;
        //     curr = curr->right;
        // }
        // cout << endl;
        // while (prev) {
        //     cout << prev->val << " ";
        //     prev = prev->left;
        // }
        // cout << endl;
        return head;
    }
};