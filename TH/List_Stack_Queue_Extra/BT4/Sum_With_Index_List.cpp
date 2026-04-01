#include <iostream>

using namespace std;
	
//
struct Node{
    int info;
    Node * next;
};

struct List{
    Node *head, *tail;
};

Node * CreateNode(int x){
    Node *p=new Node;
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}

void Init(List &A){
    A.head=NULL;
    A.tail=NULL;
}

void AddTail(List &A, int x){
    Node *p= CreateNode(x);
    if(A.head==NULL){
        A.head=p;
    }
    else{
        A.tail->next=p;
    }
    A.tail=p;
}

int Index(List A, int x){
    Node *it=A.head;
    while(x && it!=NULL){
        x--;
        it=it->next;
    }
    if(it==NULL) return 0;
    return it->info;
}

int main(){
    List L;
    Init(L);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        AddTail(L,temp);
    }
    cin>>n;
    int Sum=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        Sum+=Index(L,temp);
    }
    cout<<Sum<<endl;
    return 0;
}