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
double AverageByLevel(TREE T, int lv){
    if(T==NULL) return 0;
    int sum=0,count=0;
    vector <int> level;
    vector <TREE> stack;
    TREE it=NULL; int k=-1;
    stack.push_back(T);
    level.push_back(0);
    while(!stack.empty()){
        it=stack[stack.size()-1];
        k=level[level.size()-1];
        stack.pop_back();
        level.pop_back();
        if(k==lv){
            sum+=it->key;
            count++;
        }
        if(k<lv){
            if(it->left!=NULL){
                stack.push_back(it->left);
                level.push_back(k+1);
            }
            if(it->right!=NULL){
                stack.push_back(it->right);
                level.push_back(k+1);
            }
        }
    }
    if(!count) return 0;
    return sum*1.0/count;
}


