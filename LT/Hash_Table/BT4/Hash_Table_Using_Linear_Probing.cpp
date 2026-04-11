
#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

//
struct Hash{
    int *hashtable;
    int N;
};

bool isFull(Hash H){
    return H.N==M;
}

void initHash(Hash &H){
    H.hashtable=new int[M];
    for(int i=0;i<M;i++) H.hashtable[i]=NULLKEY;
    H.N=0;
}

void insertHash(Hash &H, int x){
    if(isFull(H)){
        cout<<"\nBang bam bi day, khong them duoc";
        return;
    }
    int i=x%M, count=M;
    while(H.hashtable[i]!=NULLKEY && count){
        i++;
        if(i>=M) i%=M;
        count--;
    }
    H.hashtable[i]=x;
    H.N++;
}

void traverseAllHash(Hash H){
    for(int i=0;i<M;i++){
        cout<<H.hashtable[i]<<" ";
    }
}

//

int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}

