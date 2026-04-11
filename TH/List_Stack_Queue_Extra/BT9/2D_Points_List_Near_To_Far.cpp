
#include <iostream>
using namespace std;

//
struct Point{
    double x,y;
};

struct Node{
    Point info;
    Node *next;
};

struct List{
    Node *head,*tail;
};

void initList(List &A){
    A.head=NULL;
    A.tail=NULL;
}

Node * CreateNode(Point x){
    Node *p = new Node;
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}

bool cp(Point a,Point b){
    double da=a.x*a.x+a.y*a.y;
    double db=b.x*b.x+b.y*b.y;
    if(da<db) return 1;
    if(da>db) return 0;
    if(a.x<b.x) return 1;
    return 0;
}

void Insert(List &A, Point x){
    Node *p = CreateNode(x);
    if(A.head==NULL){
        A.head=p;
        return;
    }
    Node *temp=A.head;
    if(cp(p->info,temp->info)){
        p->next=A.head;
        A.head=p;
    }
    while(temp->next!=NULL){
        if(cp(p->info,temp->next->info)){
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
        cout<<it->info.x<<" "<<it->info.y<<endl;
    }
}

void inputList(List &A, int n){
    for(int i=0;i<n;i++){
        Point temp;
        cin>>temp.x>>temp.y;
        Insert(A,temp);
    }
}

int main(){
    List L; int n;
    initList(L);
    cin>>n;
    inputList(L,n);
    output(L);
    return 0;
}