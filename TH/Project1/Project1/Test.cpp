
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//
struct Node {
    string info;
    Node* next;
};

struct Stack {
    Node* Top;
};

void InitStack(Stack& S) {
    S.Top = NULL;
}

Node* CreateNode(string x) {
    Node* p = new Node;
    if (p == NULL) exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void Push(Stack& S, string x) {
    Node* p = CreateNode(x);
    p->next = S.Top;
    S.Top = p;
}

void Pop(Stack& S) {
    if (S.Top == NULL) return;
    Node* p = S.Top;
    S.Top = p->next;
    delete p;
}

bool Empty(Stack& S) {
    return S.Top == NULL;
}

int main() {
    Stack S;
    InitStack(S);
    string temp;
    getline(cin, temp);
    while (temp != "-1") {
        Push(S, temp);
        getline(cin, temp);
    }
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        Pop(S);
    }
    cout << S.Top->info << endl;
    return 0;
}