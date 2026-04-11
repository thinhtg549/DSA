#include<iostream>

using namespace std;

void inputArray(char *a, int &n){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

int counting_missing_characters(char *a, int n){
    bool res[26];
    fill(res,res+26,0);
    for(int i=0;i<n;i++){
        if(a[i]>='A' && a[i]<='Z'){
            res[a[i]-'A']=1;
        }
        else if(a[i]>='a' && a[i]<='z'){
            res[a[i]-'a']=1;
        }
    }
    int missing=26;
    for(int i=0;i<26;i++){
        missing-=res[i];
    }
    return missing;
}

int main(){
    char a[1000];
    int n;
    inputArray(a,n);
    cout<<counting_missing_characters(a,n);
    return 0;
}