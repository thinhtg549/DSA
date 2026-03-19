
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

void InsertAfter(List &A, int a, int b){
	for(Node *it=A.head;it!=NULL;it=it->next){
		if(it->value==a){
			Node *p=CreateNode(b);
			p->next=it->next;
			p->prev=it;
			if(it->next!=NULL){
				it->next->prev=p;
			}
			else A.tail=p;
			it->next=p;
			return;
		}
	}
	AddHead(A,b);
}

void DeleteX(List &A, int x){
	if(A.head!=NULL)
	for(Node *it=A.head;it!=NULL;it=it->next){
		if(it->value==x){
			if(it==A.head){
				A.head=A.head->next;
				if(A.head!=NULL) A.head->prev=NULL;
			}
			if(it==A.tail){
				A.tail=A.tail->prev;
				if(A.tail!=NULL) A.tail->next=NULL;
			}
			if(it->prev!=NULL)
				it->prev->next=it->next;
			if(it->next!=NULL)
				it->next->prev=it->prev;
			delete it;
			return;
		}
	}
}

void DeleteAllX(List &A, int x){
	Node *it=A.head;
	while(it!=NULL){
		if(it->value==x){
			if(it==A.head){
   				A.head=A.head->next;
    			if(A.head!=NULL) A.head->prev=NULL;
			}
			if(it==A.tail){
    			A.tail=A.tail->prev;
    			if(A.tail!=NULL) A.tail->next=NULL;
			}
			if(it->prev!=NULL)
				it->prev->next=it->next;
			if(it->next!=NULL)
				it->next->prev=it->prev;
			Node *temp=it;
			it=it->next;
			delete temp;
		}
		else{
			it=it->next;
		}
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	List L;
	InitList(L);
	while(1){
		int type,a,b;
		cin>>type;
		if(type==6) break;
		switch(type){
			case 0:
				cin>>a;
				AddHead(L,a);
			break;
			case 1:
				cin>>a;
				AddTail(L,a);
			break;
			case 2:
				cin>>a>>b;
				InsertAfter(L,a,b);
			break;
			case 3:
				cin>>a;
				DeleteX(L,a);
			break;
			case 4:
				cin>>a;
				DeleteAllX(L,a);
			break;
			default:
				DeleteHead(L);
		}
	}
	for(Node *it=L.head;it!=NULL;it=it->next){
		cout<<it->value<<" ";
	}
	return 0;
}
