
#include <iostream>
using namespace std;
//

struct NODE{
	int info;
	NODE *pNext;
};

struct LIST{
	NODE *pHead;
	NODE *pTail;
};


void CreateEmptyList(LIST &L){
	L.pHead = NULL;
	L.pTail = NULL;
} 

NODE * CreateNode(int x){
    NODE *p= new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}

void InsertHead(LIST &L,NODE *p){
	if (L.pHead == NULL){
		L.pHead = p;
		L.pTail = L.pHead;
		}
	else{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}
//




void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}



int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertHead(L, CreateNode(x));
    }
    PrintList(L);
    return 0;
}
