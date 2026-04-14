
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

void AddTail(DList &A, int x){
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

void createList(DList &A){
    int temp;
    cin>>temp;
    while(temp!=-1){
        AddTail(A,temp);
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
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
