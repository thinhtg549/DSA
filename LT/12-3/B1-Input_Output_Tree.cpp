
#include <iostream>
using namespace std;


	
struct TNode{
	int key;
	TNode *left;
	TNode *right;
};

typedef TNode *Tree;

Tree FindNode(Tree T, int x){
	if(T!=NULL){
		if(T->key==x)
			return T;
		if(T->key>x){
			return FindNode(T->left,x);
		return FindNode(T->right,x);  
		}
	}
	return NULL;
}

Tree CreateNode(int x){
	Tree p = new TNode;
	if(p==NULL) exit(1);
	p->key=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

int AddNode(Tree &T, int x){
	if(T){
		if(T->key==x) return 0;
		if(T->key>x){
			return AddNode(T->left,x);
		}
		return AddNode(T->right,x);
	}
	T = CreateNode(x);
	return 1;
}

void NLR(Tree T){
	if(T!=NULL){
		cout<<T->key<<" ";
		NLR(T->left);
		NLR(T->right);
	}
}

void LNR(Tree T){
	if(T!=NULL){
		LNR(T->left);
		cout<<T->key<<" ";	
		LNR(T->right);
	}
}

void LRN(Tree T){
	if(T!=NULL){	
		LRN(T->left);
		LRN(T->right);
		cout<<T->key<<" ";
	}
}

void CreateTree(Tree &T){
	T = NULL;
}

void inputTree(Tree &T){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		AddNode(T,temp);
	}
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}

