
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}

//
Tree CreateNode(int x){
    Tree p = new Node;
    if(p==NULL) exit(1);
    p->info=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}

void insertNode(Tree & T, int x){
      if(T==NULL){
        T = CreateNode(x);
        return;
    }
    if(x==T->info) return;
    if(x>T->info) insertNode(T->pRight,x);
    if(x<T->info) insertNode(T->pLeft,x);
}

void NLR(Tree T){
    if(T==NULL) return;
    cout<<T->info<<" ";
    NLR(T->pLeft);   
    NLR(T->pRight);
}

void inputTree(Tree &T){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        insertNode(T,temp);
    }
}

int nodesWithLevel(Tree T, int k, int c){
    if(T==NULL) return 0;
    int res=0;
    if(!c){
        cout<<"\nList of nodes with level "<<k<<" (R->L): ";
    } 
    if(c==k){ 
        cout<<T->info<<" ";
        res=1;
    }
    res+=nodesWithLevel(T->pRight,k,c+1);
    res+=nodesWithLevel(T->pLeft,k,c+1);
    if(!c){
        cout<<"\nNumber of nodes with level "<<k<<": ";
    }
    return res;
}