
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
void init(DList &A){
    A.pHead=NULL;
    A.pTail=NULL;
}

DNode * CreateNode(int x){
    DNode *p = new DNode;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    p->pPrev=NULL;
    return p;
}

void addTail(DList &A, int x){
    DNode *p = CreateNode(x);
    if(A.pHead==NULL){
        A.pHead=p;
    }
    else{
        A.pTail->pNext=p;
        p->pPrev=A.pTail;
    }
    A.pTail=p;
}

void addHead(DList &A, int x){
    DNode *p = CreateNode(x);
    if(A.pTail==NULL){
        A.pTail=p;
    }
    else{
        p->pNext=A.pHead;
        A.pHead->pPrev=p;
    }
    A.pHead=p;
}

void createList(DList &A){
    int temp;
    cin>>temp;
    while(temp!=-1){
        addTail(A,temp);
        cin>>temp;
    }
}

void printList(DList A){
    if(A.pHead==NULL){
        cout<<"List is empty\n";
    }
    else{
        for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
            cout<<it->info<<" ";
        }
        cout<<endl;
    }
}

void addAfter(DList &A,int x, int y){
    for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
        if(it->info==x){
            DNode *p= CreateNode(y);
            p->pNext=it->pNext;
            if(p->pNext!=NULL) p->pNext->pPrev=p;
            if(it==A.pTail) A.pTail=p;
            p->pPrev=it;
            it->pNext=p;
            return;
        }
    }
    cout << "\nCan't find the value "<<x; 
}

void addAllAfter(DList &A,int x, int y){
    bool notfind=1;
    for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
        if(it->info==x){
            notfind=0;
            DNode *p= CreateNode(y);
            p->pNext=it->pNext;
            if(p->pNext!=NULL) p->pNext->pPrev=p;
            if(it==A.pTail) A.pTail=p;
            p->pPrev=it;
            it->pNext=p;
        }
    }
    if(notfind) cout << "\nCan't find the value "<<x; 
}

void addBefore(DList &A,int x, int y){
    for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
        if(it->info==x){
            DNode *p= CreateNode(y);
            p->pPrev=it->pPrev;
            if(p->pPrev!=NULL) p->pPrev->pNext=p;
            if(it==A.pHead) A.pHead=p;
            p->pNext=it;
            it->pPrev=p;
            return;
        }
    }
    cout << "\nCan't find the value "<<x; 
}

void addAllBefore(DList &A,int x, int y){
    bool notfind=1;
    for(DNode *it=A.pHead;it!=NULL;it=it->pNext){
        if(it->info==x){
            notfind=0;
            DNode *p= CreateNode(y);
            p->pPrev=it->pPrev;
            if(p->pPrev!=NULL) p->pPrev->pNext=p;
            if(it==A.pHead) A.pHead=p;
            p->pNext=it;
            it->pPrev=p;
        }
    }
    if(notfind) cout << "\nCan't find the value "<<x; 
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
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAllAfter(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAllBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
