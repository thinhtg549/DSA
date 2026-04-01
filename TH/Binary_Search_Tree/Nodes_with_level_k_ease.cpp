
#include <iostream>
using namespace std;

//
struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
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

void nodesWithLevel(Tree T, int k){
    if(T==NULL) return;
    if(!k){ 
        cout<<T->info<<" ";
        return;
    }
    nodesWithLevel(T->pRight,k-1);
    nodesWithLevel(T->pLeft,k-1);
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
//

int main()
{
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}
