
#include <iostream>
#include <math.h>

using namespace std;

//

void inputArray(int *a, int &n){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

void printArray(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void removeDups(int *a, int n){
    int maxx=0;
    for(int i=0;i<n;i++) maxx=max(maxx,a[i]);
    bool *res=new bool[maxx+1] {0};
    for(int i=0;i<n;i++){
        res[a[i]]=1;
    }
    for(int i=0;i<=maxx;i++){
        if(res[i]) cout<<i<<" ";
    }
}
//

int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
