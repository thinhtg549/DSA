
#include <iostream>
using namespace std;

//
struct Node{
    int info;
    Node *left, *right;
};

typedef Node* Tree;

Tree CreateNode(int x){
    Tree p = new Node;
    if(p==NULL) exit(1);
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void AddNode(Tree &T,int x){
    if(T==NULL){
        T=CreateNode(x);
        return;
    }
    if(T->info==x) return;
    if(T->info>x) AddNode(T->right,x);
    if(T->info<x) AddNode(T->left,x);
}

int check(Tree T){
    if(T==NULL) return 0;
    return 1+max(check(T->left),check(T->right));
}

bool isAVL(Tree T){
    if(T==NULL) return 1;
    int L=check(T->left), R=check(T->right);
    if((L-R>1) || (R-L>1)) return 0;
    if(!isAVL(T->left) || !isAVL(T->right)) return 0;
    return 1;
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
//

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
