#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int n) {data = n; next = NULL;}
};

class LinkedList {
    Node* head;
    int size;

public:
    Node* getItr() { return head; }
    LinkedList() {head = NULL; size = 0;}
    LinkedList(int n) {
        head = (Node*)malloc(sizeof(Node));
        head->data = n;
        head->next = NULL;
        size= 1;
    }

    void push_front(int n) {
        Node* temp = new Node(n);
        temp->next = head;
        head = temp;
        size++;
    }

    void push_back(int n) {
        Node* headitr = head;
        if (!headitr) {
            push_front(n);
            return;
        }
        while (headitr->next) {
            headitr = headitr->next;
        }


        Node* temp = new Node(n);
        headitr->next = temp;
        size++;
    }

    void insert_after(Node* node, int n) {
        if(!node) return;
        Node* temp = new Node(n);
        temp->next = node->next;
        node->next = temp;
        size++;
    }

    void insert(Node* node, int n) {
        if (!node) this->push_back(n);
        Node* headitr = head;
        if (headitr == node) this->push_front(n);
        while (headitr->next != node) {
            headitr = headitr->next;
            if (!headitr) return;
        }
        Node* temp = new Node(n);

        temp->next = headitr->next;
        headitr->next = temp;
        size++;
    }

    void advance(Node* &node, int n) {
        while (n--) {
            node = node->next;
            if (!node) return;
        }
    }

    void print() {
        Node* headitr = head;
        if (headitr) cout << headitr->data;
        headitr = headitr->next;
        while (headitr) {
            cout << " -> " << headitr->data;
            headitr = headitr->next;
        }
        cout << endl;
    }

    void reverse() {
        Node* curr = head;
        Node* prev = NULL, *next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

};

int main(void) {

    LinkedList l;
    l.push_front(2);
    l.push_back(3);
    l.push_front(0);
    Node* itr = l.getItr();
    l.insert_after(itr, 5);
    l.insert(itr, 6);
    itr = l.getItr();
    l.print();
    l.advance(itr, 2);
    l.insert(itr, 10);
    l.print();
    l.reverse();
    l.print();

}