
#include <iostream>
using namespace std;


//
struct Node{
	int value;
	Node *next,*prev;
};

struct List{
	Node *head,*tail;
};

Node * CreateNode(int x){
	Node *p = new Node;
	if(p==NULL) exit(1);
	p->value=x;
	p->next=NULL;
	p->prev=NULL;
	return p;
}

void AddTail(List &A, int x){
	Node *p=CreateNode(x);
	if(A.head==NULL)
		A.head=p;
	if(A.tail!=NULL)
		A.tail->next=p;
	p->prev=A.tail;
	A.tail=p;
}

void AddHead(List &A, int x){
	Node *p=CreateNode(x);
	if(A.tail==NULL)
		A.tail=p;
	if(A.head!=NULL)
		A.head->prev=p;
	p->next=A.head;
	A.head=p;
}

void DeleteTail(List &A){
	if(A.tail!=NULL)
	if(A.tail==A.head){
		A.head=NULL;
		delete A.tail;
		A.tail=NULL;
	}
	else{
		Node *temp=A.tail;
		A.tail=A.tail->prev;
		A.tail->next=NULL;
		delete temp;
	}
}

void DeleteHead(List &A){
	if(A.head!=NULL)
	if(A.head->next==NULL){
		A.tail=NULL;
		delete A.head;
		A.head=NULL;
	}
	else{
		Node *temp=A.head;
		A.head=A.head->next;
		A.head->prev=NULL;
		delete temp;
	}
}

void InitList(List &A){
	A.head=NULL;
	A.tail=NULL;
}

void func(List &A, char x, char y, int z){
	if(x=='+'){
		if(y=='H'){
			AddHead(A,z);
		}
		else{
			AddTail(A,z);
		}
	}
	else{
		if(y=='H'){
			DeleteHead(A);
		}
		else{
			DeleteTail(A);
		}
	}
}


int main(){
	int n;
	List L;
	InitList(L);
	cin>>n;
	for(int i=0;i<n;i++){
		char x,y;
		int z;
		cin>>x>>y>>z;
		func(L,x,y,z);
	}
	for(Node *it=L.head;it!=NULL;it=it->next){
		cout<<it->value<<" ";
	}
	return 0;
}
