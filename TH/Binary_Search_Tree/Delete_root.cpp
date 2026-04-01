
#include <iostream>
using namespace std;

//
struct Node{
    int info;
    Node *left, *right;
};

typedef Node* Tree;

Tree CreateNode(int x){
    Tree p=new Node;
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
    if(x>T->info) AddNode(T->right,x);
    if(x<T->info) AddNode(T->left,x);
}

void NLR(Tree T){
    if(T==NULL) return;
    cout<<T->info<<" ";
    NLR(T->left);
    NLR(T->right);
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

void ReplaceNode(Tree &p,Tree &q){
    // if(q->left->left==NULL){
    //     Tree temp=q->left->right;
    //     ReplaceNode(p,q->left);
    //     q->left=temp;
    //     return;
    // }
    if(q->left!=NULL){   
        ReplaceNode(p,q->left);
        return;
    }
    *p=*q;
    p=q;
}

void deleteRoot(Tree &T, int m){
    for(int i=0;i<m;i++){
        if(T==NULL) return;
        Tree p=T;
        if(T->left==NULL){
            T=T->right;
        }
        else if(T->right==NULL){
            T=T->left;
        }
        else{
            ReplaceNode(p,T->right);
        }
        NLR(T);
        delete p;
    }
}
//

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int m; cout<<"\nEnter m: ";cin>>m;
	deleteRoot(T,m);
	cout<<"\nNLR: "; NLR(T);

	return 0;
}
