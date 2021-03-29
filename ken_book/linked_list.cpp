#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node* next;
    string name;
    Node(string name_ = "") : next(NULL), name(name_) {}
};

Node* nil;

void init() {
    nil = new Node();
    nil->next;
}

// print linked list
void printList() {
    Node* cur = nil->next;
    for (; cur != nil; cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

void insert(Node* node, Node *p = nil) {
    node->next = p->next;
    p->next = node;
}

int main(void) {
    init();
}



