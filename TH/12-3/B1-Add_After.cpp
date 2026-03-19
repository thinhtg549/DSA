	#include<bits/stdc++.h>
	using namespace std;

struct Node{
	int value;
	Node *next;
};

struct List{
	Node *head, *tail;
};

Node *CreateNode(int value){
	Node *p = new Node;
	if(p==NULL) exit(1);
	p->next=NULL;
	p->value=value;
	return p;
}

void CreateList(List &X){
	X.head=NULL;
	X.tail=NULL;
}

void AddHead(List &X, int value){
	Node *p = CreateNode(value);
	if(X.head==NULL){
		X.tail=p;
	}
	else{
		p->next=X.head;
	}
	X.head=p;
}

void AddTail(List &X, int value){
	Node *p = CreateNode(value);
	if(X.tail==NULL){
		X.head=p;
	}
	else{
		X.tail->next=p;
	}
	X.tail=p;
}

void Insert(List &X, int pos, int value){
	for(Node *it=X.head;it!=NULL;it=it->next){
		if(it->value==pos){
			Node *p = CreateNode(value);
			if(it==X.tail) X.tail = p;
			p->next=it->next;
			it->next=p;
			return;
		}
	}
	AddHead(X,value);
}

void Print(List X){
	if(X.head!=NULL)
	for(Node *it=X.head;it!=NULL;it=it->next){
		cout<<it->value<<" ";
	}
}
	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	List A;
	CreateList(A);
	while(1){
		int type, pos, value;
		cin>>type;
		if(type==3) break;
		switch(type){
			case 0:
				cin>>value;
				AddHead(A, value);
			break;
			case 1:
				cin>>value;
				AddTail(A, value);
			break;
			case 2:
				cin>>pos>>value;
				Insert(A, pos, value);
			break;
		}
	}
	Print(A);
}
