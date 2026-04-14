
#include <bits/stdc++.h>
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

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void TronDSLK(LIST &, LIST &, LIST &);
//
void TronDSLK(LIST &L1, LIST &L2, LIST &L3){
    CreateEmptyList(L3);
    NODE *it1=L1.pHead, *it2=L2.pHead;
    while(it1!=NULL && it2!=NULL){
        if(it1->info<it2->info){
            InsertTail(L3,CreateNode(it1->info));
            it1=it1->pNext;
        }
        else{
            InsertTail(L3,CreateNode(it2->info));
            it2=it2->pNext;
        }
    }
    while(it1!=NULL){
        InsertTail(L3,CreateNode(it1->info));
        it1=it1->pNext;
    }
    while(it2!=NULL){
        InsertTail(L3,CreateNode(it2->info));
        it2=it2->pNext;
    }
}
//

int main()
{
    int t; cin >> t;
    LIST L1;
    LIST L2;
    LIST L3;
    for (int pid = 0; pid < t; pid++){
        CreateEmptyList(L1);
        int n, m; cin >> n >> m;
        int x;
        for (int i = 0; i < n; i++){
            cin >> x;
            InsertTail(L1, CreateNode(x));
        }
        CreateEmptyList(L2);
        for (int i = 0; i < m; i++){
            cin >> x;
            InsertTail(L2, CreateNode(x));
        }
        TronDSLK(L1, L2, L3);
        PrintList(L3);
        cout << "\n";
    }
    return 0;
}