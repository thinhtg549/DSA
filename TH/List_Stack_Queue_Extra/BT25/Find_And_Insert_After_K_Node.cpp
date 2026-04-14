
#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

//
void InsertTail(LIST &L,NODE *p){
	if (L.pHead == NULL){
		L.pHead = p;
	}
	else{
		L.pTail->pNext=p;
	}
    L.pTail=p;
}

void InsertNode(LIST &L, NODE *it){
    NODE *p= CreateNode(1999);
    p->pNext=it->pNext;
    it->pNext=p;
    if(it==L.pTail) L.pTail=p;
}

void TimKiemVaThem(LIST &L, int x){
    for(NODE *it=L.pHead;it!=NULL;it=it->pNext){
        if(it->info==x){
            InsertNode(L,it);
            PrintList(L);
            return;
        }
    }
    InsertTail(L,CreateNode(1999));
    PrintList(L);
}
//

NODE* TimKiem(LIST, int);
void InsertNode(LIST &, NODE*);
void TimKiemVaThem(LIST &, int);

int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    int k; cin >> k;
    TimKiemVaThem(L, k);
    return 0;
}
