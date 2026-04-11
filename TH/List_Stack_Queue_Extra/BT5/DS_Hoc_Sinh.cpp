#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void initList(List &L){
    L.head=NULL;
    L.tail=NULL;
}

double AVG(Hocsinh hs){
    return (hs.Toan + hs.Ly + hs.Hoa + hs.Van + hs.Anh + hs.Sinh)/6;
}

void AddTail(List &A, Node *&p){
    if(A.head==NULL){
        A.head=p;
    }
    else{
        A.tail->next=p;
    }
    A.tail=p;
}

void InputList(List &A){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        Node *p = new Node;
        InputElement(p->data);
        if(AVG(p->data)>=9){
            AddTail(A,p);
        }
    }
}

//
int main(){
    List L;
    initList(L);
    InputList(L);
    Output(L);
    return 0;
}
//


