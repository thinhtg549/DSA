#include <iostream>
#include <cmath>

using namespace std;

struct Point{
	double x,y,z;
	Point *next;
	int index;
};

struct List{
	Point *head;
	Point *tail;
};

Point *CreatePoint(double x, double y, double z){
	Point *p = new Point;
	if(p==NULL) exit(1);
	p->x=x;
	p->y=y;
	p->z=z;
	p->next=NULL;
	return p;
}

void AddTail(List &X, double x, double y, double z, int index){
	Point *p = CreatePoint(x,y,z);
	if(X.head==NULL){
		X.head=p;
	}
	else{
		X.tail->next=p;
	}
	p->index=index;
	X.tail=p;
}

int Find(List &X, double x, double y, double z){
	for(Point *it=X.head;it!=NULL;it=it->next){
		if(it->x==x && it->y==y && it->z==z) return it->index;
	}
	return -1;
}

void CreateList(List &X){
	X.head=NULL;
	X.tail=NULL;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	List A;
	CreateList(A);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		double x,y,z;
		cin>>x>>y>>z;
		AddTail(A,x,y,z,i);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		double x,y,z;
		cin>>x>>y>>z;
		int temp=Find(A,x,y,z);
		if(temp==-1) cout<<"KHONG\n";
		else cout<<temp<<endl;
	}
	return 0;
}

