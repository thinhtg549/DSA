
#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//
DNode * CreateNode(int x){
	DNode *p = new DNode;
	if(p==NULL) exit(1);
	p->info=x;
	p->pNext=NULL;
	p->pPrev=NULL;
	return p;
}

void init(DList &A){
	A.pHead=NULL;
	A.pTail=NULL;
}

void addTail(DList &A, int x){
	DNode *p=CreateNode(x);
	if(A.pHead==NULL)
		A.pHead=p;
	if(A.pTail!=NULL)
		A.pTail->pNext=p;
	p->pPrev=A.pTail;
	A.pTail=p;
}

void addHead(DList &A, int x){
	DNode *p=CreateNode(x);
	if(A.pTail==NULL)
		A.pTail=p;
	if(A.pHead!=NULL)
		A.pHead->pPrev=p;
	p->pNext=A.pHead;
	A.pHead=p;
}

void createList(DList &A){
	while(1){
		int temp;
		cin>>temp;
		if(temp==-1) break;
		addTail(A,temp);
	}
}

void addAfter(DList &A,int a,int b){
	for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
		if(it->info==a){
			DNode *p=CreateNode(b);
			p->pNext=it->pNext;
			p->pPrev=it;
			if(it->pNext!=NULL){
				it->pNext->pPrev=p;
			}
			else A.pTail=p;
			it->pNext=p;
			return;
		}
	}
	cout<<"\nCan't find the value "<<a;
}

void addBefore(DList &A,int a,int b){
	for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
		if(it->info==a){
			DNode *p=CreateNode(b);
			p->pNext=it;
			p->pPrev=it->pPrev;
			if(it->pPrev!=NULL){
				it->pPrev->pNext=p;
			}
			else A.pHead=p;
			it->pPrev=p;
			return;
		}
	}
	cout<<"\nCan't find the value "<<a;
}

void printList(DList A){
	if(A.pHead==NULL) cout<<"List is empty\n";
	else{
		for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
			cout<<it->info<<" ";
		}
		cout<<endl;	
	}
}
//

int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}

