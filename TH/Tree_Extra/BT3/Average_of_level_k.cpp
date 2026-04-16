#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}


double AverageByLevel(TREE, int);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++) {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}

//
int sum_of_level(TREE T, int k, int i){
    if(T==NULL) return 0;
    if(i==k) return T->key;
    if(i<k) return sum_of_level(T->left,k,i+1)+sum_of_level(T->right,k,i+1);
    return 0;
}

int count_of_level(TREE T, int k, int i){
    if(T==NULL) return 0;
    if(i==k) return 1;
    if(i<k) return count_of_level(T->left,k,i+1)+count_of_level(T->right,k,i+1);
    return 0;
}

double AverageByLevel(TREE T, int k){
    int temp=count_of_level(T,k,0);
    if(!temp) return 0;
    return sum_of_level(T,k,0)*1.0/temp;
}

