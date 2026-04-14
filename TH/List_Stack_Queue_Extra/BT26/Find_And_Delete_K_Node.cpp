
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

//
void PrintList(LIST L){
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void InsertTail(LIST &L,NODE *p){
	if (L.pHead == NULL){
		L.pHead = p;
	}
	else{
		L.pTail->pNext=p;
	}
    L.pTail=p;
}

void DeleteNode(LIST &L, NODE *it){
    if(it==L.pHead){
        L.pHead=L.pHead->pNext;
        delete it;
        return;
    } 
    NODE*p=L.pHead;
    while(p->pNext!=it) p=p->pNext;
    p->pNext=it->pNext;
    delete it;
    if(L.pTail==it)
        L.pTail=p;
}

void TimKiemVaXoa(LIST &L, int x){
    for(NODE *it=L.pHead;it!=NULL;it=it->pNext){
        if(it->info==x){
            DeleteNode(L,it);
            PrintList(L);
            return;
        }
    }
    cout<<-1<<endl;
}
//

NODE* TimKiem(LIST, int);
void DeleteNode(LIST &, NODE*);
void TimKiemVaXoa(LIST &, int);


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
    TimKiemVaXoa(L, k);
    return 0;
}
