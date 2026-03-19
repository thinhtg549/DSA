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

Node *Find(List &X, int value){
	for(Node *it=X.head;it!=NULL;it=it->next)
		if(it->value==value) return it;
	return NULL;
}

void Insert(List &X, int pos, int value){
	Node *it=Find(X,pos);
	if(it!=NULL){
		Node *p = CreateNode(value);
		if(it==X.tail) X.tail = p;
		p->next=it->next;
		it->next=p;
		return;
	}
	else AddHead(X,value);
}

void Delete(List &X, int value){
	Node *prev = NULL;
	for(Node *it=X.head;it!=NULL;it=it->next){
		if(it->value==value){
			if(it!=X.head)
				prev->next=it->next;
			else
				X.head=X.head->next;
			if(it==X.tail){
				X.tail=prev;
			}			
			delete it;
			return;
		}
		prev=it;
	}
}

void DeleteHead(List &X){
	if(X.head!=NULL){
		if(X.head==X.tail){
			X.tail=NULL;
		}
		Node *temp=X.head;
		X.head=X.head->next;
		temp->next=NULL;
		delete temp;
	}
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
		if(type==6) break;
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
			case 3:
				cin>>value;
				Delete(A, value);
			break;
			case 5:
				DeleteHead(A);
			break;
		}
	}
	Print(A);
}
