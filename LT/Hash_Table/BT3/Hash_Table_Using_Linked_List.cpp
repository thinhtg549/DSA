
#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//
struct Node{
    int info;
    Node *next;
};

struct List{
    Node *head=NULL,*tail=NULL;
};

struct Hash{
    int m;
    List *list;
};

Node * CreateNode(int x){
    Node *p=new Node;
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}

void Insert(List &A,int x){
    Node *p=CreateNode(x);
    if(A.head==NULL){
        A.head=p;
        A.tail=p;
        return;
    }
    if(p->info<A.head->info){
        p->next=A.head;
        A.head=p;
        return;
    }
    Node *it=A.head;
    while(it->next!=NULL && p->info>it->next->info){
        it=it->next;
    }
    if(it->next==NULL)
        A.tail=p;
    p->next=it->next;
    it->next=p;
}

void initHash(Hash &H){
    H.list=new List[H.m];
}

void insertHash(Hash &H, int x){
    Insert(H.list[x%H.m],x);
}

void PrintList(List A){
    for(Node *it=A.head;it!=NULL;it=it->next){
        cout<<it->info<<" ";
    }
}

void traverseAllHash(Hash H){
    for(int i=0;i<H.m;i++){
        cout<<"Bucket "<<i<<": "; 
        PrintList(H.list[i]);
        cout<<endl;
    }
}

//

int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

