#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node* left, *right;

    Node(int n) {
        val = n;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {
    Node* root;


    Node* eraseUtil(Node* root, int n) {
        if (!root) return root;

        if (n > root->val) {
            root->right = eraseUtil(root->right, n);
        }
        else if (n < root->val) {
            root->left = eraseUtil(root->left, n);
        }
        else {
            if (isLeaf(root)) {
                delete root;
                return NULL;
            }
            else if (!root->right) {
                Node* temp = root;
                root = root->left;
                delete temp;
                return root;
            } else if (!root->left) {
                Node* temp = root;
                root = root->right;
                delete temp;
                return root;
            } else {
                Node* succ, *succParent;
                succ = root->right;
                succParent = root;
                while (succ->left) {
                    succParent = succ;
                    succ = succ->left;
                }

                if (succParent == root) {
                    succParent->right = succ->right;
                }else {
                    succParent->left = succ->right;
                }

                root->val = succ->val;
                delete succ;
                return root;
            }
        }
        return root;
    }

    void inorderUtil(Node* curr) {
        if (!curr) return;

        inorderUtil(curr->left);
        cout << curr->val << " ";
        inorderUtil(curr->right);

    }

    Node* searchUtil(Node* curr, int n) {
        if (!curr) return NULL;

        if (curr->val == n) return curr;
        if (n > curr->val) return searchUtil(curr->right, n);
        else return searchUtil(curr->left, n);
    }

    bool isLeaf(Node* root) {
        if (!root) return false;
        if (!root->left && !root->right) return true;
        return false;
    }

    Node* insertUtil(int n, Node* root) {
        if (!root) return new Node(n);

        if (root->val == n) return NULL;
        else if (root->val < n) root->right = insertUtil(n, root->right);
        else root->left = insertUtil(n, root->left);

        return root;
    }

public:
    BinarySearchTree(int n) { root = new Node(n); }

    void inorder() {
        inorderUtil(root);
        cout << endl;
    }

    void postorderIter() {
        stack<Node*> s;

        if (!root) {
            cout << "Tree empty\n";
            return;
        }

        Node* curr = root;
        while (true) {
            while (curr) {
                s.push(curr);
                s.push(curr);
                curr = curr->left;
            }

            if (s.empty()) break;
            curr = s.top();
            s.pop();
            if (!s.empty() && curr == s.top()) curr = curr->right;
            else {
                cout << curr->val << " ";
                curr = NULL;
            }
        }
        cout << endl;
    }

    void postorderIterReverse() {
        stack<Node*> s;

        if (!root) {
            cout << "Tree empty\n";
            return;
        }

        s.push(root);
        
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();

            cout << node->val << " ";
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }

        cout << endl;
    }
    
    void preorderIter() {
        stack<Node*> s;
        if (!root) {
            cout << "Tree empty\n";
            return;
        }

        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();

            cout << node->val << " ";

            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }

        cout << endl;
    }

    void inorderIter() {
        stack<Node*> s;
        if (!root) {
            cout << "Tree Empty\n";
            return;
        }

        Node* curr = root;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
        cout << endl;
    }

    void morrisInorder() {
        if (!root) return;
        Node* pre;
        Node* curr = root;
        while (curr) {
            if (!curr->left) {
                cout << curr->val << " ";
                curr = curr->right;
            } else {
                pre = curr->left;
                while (pre->right && pre->right != curr) pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    cout << curr->val << " ";
                    curr = curr->right;
                }
            }
        }
        cout << endl;
    }

    void morrisPreorder() {
        if (!root) return;
        Node* pre;
        Node* curr = root;
        while (curr) {
            if (!curr->left) {
                cout << curr->val << " ";
                curr = curr->right;
            } else {
                pre = curr->left;
                while (pre->right && pre->right != curr) pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = curr;
                    cout << curr->val << " ";
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
        cout << endl;
    }

    
    void insert(int n) {
        insertUtil(n, root);
    }

    bool search(int n) {
        return (searchUtil(root, n) != NULL);
    }

    void erase(int n) {
        eraseUtil(root, n);
    }
};


int main(void) {
    BinarySearchTree t(5);
    t.insert(1);
    t.insert(2);
    t.insert(6);
    t.insert(8);

    t.inorderIter();
    t.morrisInorder();
    t.preorderIter();
    t.morrisPreorder();
    t.postorderIter();
    t.postorderIterReverse();
}