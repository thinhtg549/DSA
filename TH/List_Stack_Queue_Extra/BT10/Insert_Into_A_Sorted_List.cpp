
#include <iostream>
using namespace std;

//
struct Node{
    int info;
    Node *next;
};

struct List{
    Node *head,*tail;
};

void initList(List &A){
    A.head=NULL;
    A.tail=NULL;
}

Node * CreateNode(int x){
    Node *p = new Node;
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}

void Insert(List &A, int x){
    Node *p = CreateNode(x);
    if(A.head==NULL){
        A.head=p;
        A.tail=p;
        return;
    }
    Node *temp=A.head;
    if(p->info<temp->info){
        p->next=A.head;
        A.head=p;
        return;
    }
    while(temp->next!=NULL){
        if(p->info<temp->next->info){
            p->next=temp->next;
            temp->next=p;
            return;
        }
        temp=temp->next;
    }
    temp->next=p;
    A.tail=p;
}

void output(List A){
    for(Node *it=A.head; it!=NULL; it=it->next){
        cout<<it->info<<" ";
    }
    cout<<endl;
}

void inputList(List &A, int n){
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        Insert(A,temp);
        output(A);
    }
}

int main(){
    List L; int n;
    initList(L);
    cin>>n;
    inputList(L,n);
    return 0;
}