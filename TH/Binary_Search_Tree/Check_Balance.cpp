
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode* TREE;

TREE CreateTREE(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTREE(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTREE(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

//
int check(TREE T){
    if(T==NULL) return 0;
    return 1+max(check(T->left),check(T->right));
}

void Fun(TREE T){
    if(T==NULL){
        cout<<"Empty TREE\n";
        return;
    }
    int L=check(T->left),R=check(T->right);
    if(L>R) cout<<-1<<endl;
    else if(L<R) cout<<1<<endl;
    else cout<<0<<endl;
}
//

int main() {
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num=duyetNLR.size()-1;
    TREE root = CreateTREE(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    return 0;
}
