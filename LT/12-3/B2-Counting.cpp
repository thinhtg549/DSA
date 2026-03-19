
#include <iostream>
using namespace std;

//
struct TNode{
	int key;
	TNode *left;
	TNode *right;
};

typedef TNode *Tree;

Tree FindNode(Tree T, int x){
	if(T!=NULL){
		if(T->key==x)
			return T;
		if(T->key>x){
			return FindNode(T->left,x);
		return FindNode(T->right,x);  
		}
	}
	return NULL;
}

Tree CreateNode(int x){
	Tree p = new TNode;
	if(p==NULL) exit(1);
	p->key=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

int AddNode(Tree &T, int x){
	if(T){
		if(T->key==x) return 0;
		if(T->key>x){
			return AddNode(T->left,x);
		}
		return AddNode(T->right,x);
	}
	T = CreateNode(x);
	return 1;
}

void NLR(Tree T){
	if(T!=NULL){
		cout<<T->key<<" ";
		NLR(T->left);
		NLR(T->right);
	}
}

void LNR(Tree T){
	if(T!=NULL){
		LNR(T->left);
		cout<<T->key<<" ";	
		LNR(T->right);
	}
}

void LRN(Tree T){
	if(T!=NULL){	
		LRN(T->left);
		LRN(T->right);
		cout<<T->key<<" ";
	}
}

void CreateTree(Tree &T){
	T = NULL;
}

void inputTree(Tree &T){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		AddNode(T,temp);
	}
}

int countNodes(Tree &T){
	if(T==NULL) return 0;
	return 1+countNodes(T->left)+countNodes(T->right);
}

int depthOfTree(Tree &T){
	if(T==NULL) return -1;
	return 1+max(depthOfTree(T->left),depthOfTree(T->right));
}

int count_Even(Tree T){
	if(T==NULL) return 0;
	if(T->key%2==0) return 1+count_Even(T->left)+count_Even(T->right);
	return count_Even(T->left)+count_Even(T->right);
}

void countEven(Tree T,int &total){
	total=count_Even(T);
}

int count_Odd(Tree T){
	if(T==NULL) return 0;
	if(T->key%2) return 1+count_Odd(T->left)+count_Odd(T->right);
	return count_Odd(T->left)+count_Odd(T->right);
}

void countOdd(Tree T,int &total){
	total=count_Odd(T);
}

int countPositive(Tree T){
	if(T==NULL) return 0;
	if(T->key>0) return 1+countPositive(T->left)+countPositive(T->right);
	return countPositive(T->left)+countPositive(T->right);
}

int countNegative(Tree T){
	if(T==NULL) return 0;
	if(T->key<0) return 1+countNegative(T->left)+countNegative(T->right);
	return countNegative(T->left)+countNegative(T->right);
}

bool IsPrime(int x){
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}

int countPrime(Tree T){
	if(T==NULL) return 0;
	if(IsPrime(T->key)) return 1+countPrime(T->left)+countPrime(T->right);
	return countPrime(T->left)+countPrime(T->right);
}

void listPrime(Tree T){
	if(T!=NULL){
		if(IsPrime(T->key)) cout<<T->key<<" ";
		listPrime(T->left);
		listPrime(T->right);
	}
}
//

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}

