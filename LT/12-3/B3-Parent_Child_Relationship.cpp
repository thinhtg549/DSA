
#include <iostream>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isFather(Tree, int, int);
void run(int q, Tree T);

//
TNode *CreateNode(int x){
	TNode *p = new TNode;
	if(p==NULL) exit(1);
	p->key=x;
	p->pLeft=NULL;
	p->pRight=NULL;
	return p;
}

TNode *FindNode(TNode *T, int x){
    if(T == NULL) return NULL;

    if(T->key == x) return T;

    if(x < T->key)
        return FindNode(T->pLeft, x);
    else
        return FindNode(T->pRight, x);
}

int isFather(TNode *T, int u, int v){
    TNode *p = FindNode(T,u);
    if(p){
        if((p->pLeft && p->pLeft->key == v) ||
           (p->pRight && p->pRight->key == v))
            return 1;
    }

    p = FindNode(T,v);
    if(p){
        if((p->pLeft && p->pLeft->key == u) ||
           (p->pRight && p->pRight->key == u))
            return -1;
    }

    return 0;
}

void AddNode(TNode *&T, int x){
	if(T){
		if(T->key==x) return;
		if(T->key>x){
			return AddNode(T->pLeft,x);
		}
		return AddNode(T->pRight,x);
	}
	T = CreateNode(x);
}

void Insert(Tree &T, int x){
	AddNode(T.root,x);
}

void run(int q, Tree T){
	for(int i=0;i<q;i++){
		int u,v;
		cin>>u>>v;
		switch(isFather(T.root,u,v)){
			case 1:
				cout<<u<<" la cha cua "<<v<<endl;
			break;
			case -1:
				cout<<v<<" la cha cua "<<u<<endl;
			break;
			default:
				cout<<u<<" va "<<v<<" khong co quan he cha con\n";
		}
	}
}
//

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);

    return 0;
}

