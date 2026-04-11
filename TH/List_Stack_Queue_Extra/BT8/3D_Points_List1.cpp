#include <iostream>
#include <cmath>

using namespace std;

//
struct Point{
    double x,y,z;
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

void AddTail(List &A, Point x){
    Node *p = CreateNode(x);
    if(A.head==NULL){
        A.head=p;
    }
    else{
        A.tail->next=p;
    }
    A.tail=p;
}

double Distance(Point info){
    return sqrt(info.x*info.x + info.y*info.y + info.z*info.z);
}

void output(Point info){
    cout<<info.x<<" "<<info.y<<" "<<info.z<<endl;
}

void Counting(List A, double L, double R){
    bool empty=1;
    for(Node *it=A.head; it!=NULL; it=it->next){
        double d=Distance(it->info);
        if(L<=d && d<=R){
            output(it->info);
            empty=0;
        } 
    }
    if(empty) cout<<"KHONG\n";
}

void inputList(List &A, int n){
    for(int i=0;i<n;i++){
        Point temp;
        cin>>temp.x>>temp.y>>temp.z;
        AddTail(A,temp);
    }
}

int main(){
    List L; int n;
    initList(L);
    cin>>n;
    inputList(L,n);
    double b,e;
    cin>>b>>e;
    Counting(L,b,e);
    return 0;
}