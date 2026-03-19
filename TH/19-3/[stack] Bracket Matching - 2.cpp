/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -
struct Node{
	char value=0;
	Node *pointer=NULL;
	
};

void insert(Node *a, char x){
	a->value=x;
}

struct Stack{
	Node *pHead;
};

void Init(Stack &S){
	S.pHead=NULL;
}

bool empty(Stack &S){
	return S.pHead==NULL;
}

void Push(Stack &S, char x){
	Node *a=new Node();
	insert(a,x);
	if(S.pHead==NULL){
		S.pHead=a;
	}
	else{
		a->pointer=S.pHead;
		S.pHead=a;
	}
}

char Top(Stack S){
	if(S.pHead==NULL) return -1;
	return S.pHead->value;
}

void Pop(Stack &S){
	if(S.pHead!=NULL){
		Node *temp=S.pHead;
		S.pHead=S.pHead->pointer;
		delete (temp);
	}
}

bool isValid(string str){
	Stack s;
	Init(s);
	for(int i=0;i<str.length();i++){
		if(str[i]=='(' || str[i]=='[' || str[i]=='{') Push(s,str[i]);
		else{
			if(empty(s)) return 0;
			if(Top(s)=='(' && (str[i]==']' || str[i]=='}')) return 0;
			if(Top(s)=='[' && (str[i]==')' || str[i]=='}')) return 0;
			if(Top(s)=='{' && (str[i]==']' || str[i]==')')) return 0;
			Pop(s);
		}
	}
	if(empty(s)==0) return 0;
	return 1;
}
//
int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}




