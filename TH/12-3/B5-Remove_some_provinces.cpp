
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

bool Delete(List &X, string s){
	bool o=0;
	node *prev = NULL;
	node *temp = NULL;
	node *it=X.head;
	while(it!=NULL){
		if(it->info->name.find(s)!=string::npos){
			o=1;
			if(it!=X.head)
				prev->next=it->next;
			else
				X.head=X.head->next;
			if(it==X.tail){
				X.tail=prev;
			}		
			temp=it;
			it=it->next;
			delete temp;
			continue;
		}
		prev=it;
		it=it->next;
	}
	return o;
}

void outputProvince(Info *a){
	cout<<a->id<<'\t'<<a->name<<'\t'<<a->pop<<'\t'<<a->area<<endl;
}

void outputListProvinces(List X){
	if(X.head==NULL)
		cout<<"List is empty"<<endl;
	else
	for(node *it=X.head;it!=NULL;it=it->next){
		outputProvince(it->info);
	}
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);
	
	string s;
	cout<<"Enter the last word of name to search:"<<endl;
	cin>>s;
	
	if(Delete(L,s)){
		cout<<"Updated List:"<<endl;
		cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    	outputListProvinces(L);
	}
	else{
		cout<<"Not found"<<endl;
	}

    return 0;
}


