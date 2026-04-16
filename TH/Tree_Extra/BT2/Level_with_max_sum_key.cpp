#include <iostream>
#include <vector>
#include <map>



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

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


int MaxLevel(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    Input(nlr);
    Input(lnr);


    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cout << MaxLevel(r) << endl;

    return 0;
}

//
int MaxLevel(TREE T){
    vector <int> sum,level;
    vector <TREE> stack;
    TREE it=NULL; int k=-1;
    stack.push_back(T);
    level.push_back(0);
    while(!stack.empty()){
        it=stack[stack.size()-1];
        k=level[level.size()-1];
        stack.pop_back();
        level.pop_back();
        while(sum.size()<=k) sum.push_back(0);
        sum[k]+=it->key;
        if(it->left!=NULL){
            stack.push_back(it->left);
            level.push_back(k+1);
        }
        if(it->right!=NULL){
            stack.push_back(it->right);
            level.push_back(k+1);
        }
    }
    if(!sum.size()) return -1;
    int res=0;
    for(int i=1;i<sum.size();i++){
        if(sum[res]<sum[i]) res=i;
    }
    return res;
}
