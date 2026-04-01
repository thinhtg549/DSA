
#include <iostream>
using namespace std;

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
    if(T->info>x) AddNode(T->left,x);
    if(T->info<x) AddNode(T->right,x);
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

void NLR(Tree T){
    if(T==NULL) return;
    cout<<T->info<<" ";
    NLR(T->left);
    NLR(T->right);
}

void clear(Tree &T){
    if(T==NULL) return;
    clear(T->left);
    clear(T->right);
    delete T;
}

void AddNLR(Tree &T,Tree x){
    if(x==NULL) return;
    AddNode(T,x->info);
    AddNLR(T,x->left);
    AddNLR(T,x->right);
}

void RotateTree(Tree &T){
    if(T==NULL){
        cout<< "Khong the xoay vi cay rong\n";
        return;
    }
    if(T->right==NULL){
        cout<< "Khong the xoay trai vi khong co nut con ben phai\n";
        return;
    }
    Tree temp=NULL;
    AddNode(temp,T->right->info);
    AddNode(temp,T->info);
    AddNLR(temp,T->left);
    AddNLR(temp,T->right->right);
    AddNLR(temp,T->right->left);
    clear(T);
    T=temp;
}


int main()
{
	Tree T = NULL;
	inputTree(T); cout<<"NLR: ";
    NLR(T); cout<<endl;
    RotateTree(T); cout<<"NLR: ";
    NLR(T); cout<<endl;
	return 0;
}
