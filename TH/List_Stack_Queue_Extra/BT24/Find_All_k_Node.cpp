
#include <iostream>
#include <vector>
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

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void TimKiem(LIST, int);
//
void TimKiem(LIST L, int x){
    int k=0;
    bool finded=0;
    for(NODE *it=L.pHead;it!=NULL;it=it->pNext){
        if(it->info==x){
            finded=1;
            cout<<k<<" ";
        }
        k++;
    }
    if(!finded) cout<<-1;
    cout<<endl;
}
//




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
    TimKiem(L, k);
    return 0;
}
