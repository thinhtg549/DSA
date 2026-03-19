
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//
struct Info{
	int id;
    string name;
    int pop;
    float area;
};

struct node {
    Info *info;
    node * next;
};

struct List {
    node * head, * tail;
};

istream &operator>>(istream &in, Info &p){
	in>>p.id;
	in.ignore();
	getline(in,p.name);
	in>>p.pop>>p.area;
	return in;
}

node * Createnode() {
    node *p = new node;
    if (p == NULL) exit(1);
    p->next = NULL;
    p->info= new Info;
    cin>>*p->info;
    return p;
}

void Init(List &l) {
    l.head = l.tail = NULL;
}


void inputListProvinces(List &X){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		node *p=Createnode();
		if(X.head==NULL){
			X.head=p;
		}
		else{
			X.tail->next=p;
		}
		X.tail=p;
	}
}

void outputProvince(Info *a){
	cout<<a->id<<'\t'<<a->name<<'\t'<<a->pop<<'\t'<<a->area<<endl;
}

void outputListProvinces(List X){
	for(node *it=X.head;it!=NULL;it=it->next){
		outputProvince(it->info);
	}
}

void outputProvincesMore1MillionPop(List X){
	for(node *it=X.head;it!=NULL;it=it->next){
		if(it->info->pop>1000)
			outputProvince(it->info);
	}
}

node *findProMaxArea(List &X){
	node *p=X.head;
	for(node *it=X.head;it!=NULL;it=it->next){
		if(it->info->area>p->info->area)
			p=it;
	}
	return p;
}
//


int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}




