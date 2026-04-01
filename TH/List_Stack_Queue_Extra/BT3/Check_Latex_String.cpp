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
	char info;
	Node *next;
};

struct Stack{
	Node *Top;
};

void StackInit(Stack &S){
	S.Top=NULL;
}

Node * CreateNode(char x){
	Node *p= new Node;
	if(p==NULL) exit(1);
	p->info=x;
	p->next=NULL;
	return p;
}

void Push(Stack &S, char x){
	Node *p = CreateNode(x);
	if(S.Top!=NULL){
		p->next=S.Top;
	}
	S.Top=p;
}

void Pop(Stack &S){
	if(S.Top==NULL) return;
	Node *temp=S.Top;
	S.Top=S.Top->next;
	delete temp;
}

bool Empty(Stack S){
	return S.Top==NULL;
}

bool isValid(string s){
	Stack S;
	StackInit(S);
	for(int i=0;i<s.length();i++){
		if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
			Push(S,s[i]);
		}
		else if(s[i]==')' || s[i]==']' || s[i]=='}'){
			if(Empty(S)) return 0;
			if(s[i]==')' && S.Top->info=='('){
				Pop(S);
			}
			else if(s[i]==']' && S.Top->info=='['){
				Pop(S);
			}
			else if(s[i]=='}' && S.Top->info=='{'){
				Pop(S);
			}
			else{
				return 0;
			}
		}
	}
	return Empty(S);
}
//

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



