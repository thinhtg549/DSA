
#include <iostream>
#include <string>
using namespace std;

typedef struct Product
{
    int id;
    string name;
    string type;
    int year;
    int warranty;
} PRO;

struct Node
{
	PRO info;
	Node *pLeft;
	Node *pRight;
};
typedef struct Node* Tree;

void printProduct(PRO x)
{
    cout <<x.id<<"\t"<<x.name<<"\t"<<x.type<<"\t"<<x.year<<"\t"<<x.warranty<<endl;

}


//
Tree CreateNode(PRO x){
    Tree p = new Node;
    if(p==NULL) exit(1);
    p->info=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}

PRO inputInfo(){
    PRO res;
    cin>>res.id;
    cin.ignore();
    getline(cin,res.name);
    getline(cin,res.type);
    cin>>res.year>>res.warranty;
    return res;
}

void AddNode(Tree &T, PRO x){
    if(T==NULL){
        T = CreateNode(x);
        return;
    }
    if(x.id==T->info.id) return;
    if(x.id>T->info.id) AddNode(T->pRight,x);
    if(x.id<T->info.id) AddNode(T->pLeft,x);
}

void inputTree(Tree &T){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        PRO temp=inputInfo();
        AddNode(T,temp);
    }
}

void LNR(Tree T){
    if(T==NULL) return;
    LNR(T->pLeft);
    printProduct(T->info);
    LNR(T->pRight);
}

int countProducts(Tree T, int x){
    if(T==NULL) return 0;
    if(T->info.year==x) return 1+countProducts(T->pLeft,x)+countProducts(T->pRight,x);
    return countProducts(T->pLeft,x)+countProducts(T->pRight,x);
}
//


int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"List of products: ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    LNR(T);

    int year;cin>>year;
    cout<<"Number of products produced in "<<year<<": "<<countProducts(T,year)<<endl;

	return 0;
}

