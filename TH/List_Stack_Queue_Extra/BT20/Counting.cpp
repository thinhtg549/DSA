
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

void InsertTail(LIST &L,NODE *p){
	if (L.pHead == NULL){
		L.pHead = p;
	}
	else{
		L.pTail->pNext=p;
	}
    L.pTail=p;
}

int DemSoLuongPhanTuTrongL(LIST L){
    int res=0;
    for(NODE *it=L.pHead;it!=NULL;it=it->pNext)
        res++;
    return res;
}
//



void InsertTail(LIST &, NODE *);
int DemSoLuongPhanTuTrongL(LIST);

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
    int k = DemSoLuongPhanTuTrongL(L);
    cout << k;
    return 0;
}
