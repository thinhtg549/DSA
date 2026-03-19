
#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct List
{
    node *head,*tail;
};
node* getNode(int x)
{
    node *p=new node;
    if (p)
    {
        p->info=x;
        p->next=NULL;
    }
    return p;
}
void Init (List &L)
{
    L.head=L.tail=NULL;
}



void addTail(List &L, int x)
{
    node* p = getNode(x);
    if (L.head==NULL)
        L.head=L.tail=p;
    else
    {
        L.tail->next=p;
        L.tail = p;
    }
}
void inputList(List &L,int n)
{

    int x;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        addTail(L,x); // them phan tu moi vao cuoi danh sach
    }
}

void outputList(List L)
{
    if (L.head==NULL)
    {
        cout<<"List is empty"; return;
    }

    node *p=L.head;
    while (p)
    {
       cout<<p->info<<" ";
        p=p->next;
    }
}

//
void addHead(List &A, int x){
	node *p = getNode(x);
	if(A.head==NULL){
		A.tail=p;
	}
	else{
		p->next=A.head;
	}
	A.head=p;
}

void insertList(List &A, int x){
	if(A.head!=NULL && x<A.head->info){
		addHead(A,x);
		return;
	} 
	for(node *it=A.head;it!=NULL;it=it->next){
		if(it->next==NULL || it->next->info>x){
			node *p=getNode(x);
			if(it==A.tail) A.tail = p;
			p->next=it->next;
			it->next=p;
			return;
		}
	}
	addHead(A,x);
}
//

int main()
{
    List L;
    Init(L);
    int n,x; cin>>n;
    inputList(L,n);
    cout<<"Created List: ";
    outputList(L);
    cout<<"\nEnter a number to add to the list: ";
    cin>>x;
    insertList(L,x);
    cout<<"\nUpdated List: ";
    outputList(L);
    return 0;
}


