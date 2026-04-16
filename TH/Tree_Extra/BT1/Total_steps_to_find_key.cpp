#include <iostream>
#include <vector>

using namespace std;
struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode * TREE;

void CreateTree(TREE &t) {
    t = NULL;
}

TNode * CreateTNode(int x) {
    TNode * p = new TNode;
    if (p == NULL) return NULL;
    p->left = p->right = NULL;
    p->key = x;
	return p;
}

void InsertNode(TREE &t, int x) {
    TNode *p = CreateTNode(x);

    if (t == NULL) {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL) {
        if (x == q->key) return;
        if (x > q->key) {
            if (q->right == NULL) {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else {
            if (q->left == NULL) {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t) {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        InsertNode(t, k);
    }
}

int ComparisonCount(TREE, int);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    int m, k;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        cout << ComparisonCount(t, k) << endl;
    }
    return 0;
}
	
//
int ComparisonCount(TREE T, int k){
    if(T==NULL) return 0;
    if(T->key==k) return 1;
    if(T->key<k) return 1+ComparisonCount(T->right,k);
    return 1+ComparisonCount(T->left,k);
}