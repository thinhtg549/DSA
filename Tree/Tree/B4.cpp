
#include <iostream>
using namespace std;

//
struct Node {
	int info;
	Node* left, * right;
};

typedef Node* Tree;

Tree CreateNode(int x) {
	Tree p = new Node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

bool Insert(Tree& T, int x) {
	if (T == NULL) {
		T = CreateNode(x);
		return 1;
	}
	if (x == T->info) return 0;
	if (x > T->info) return Insert(T->right, x);
	return Insert(T->left, x);
}

void inputTree(Tree& T) {
	int n;
	cin >> n;
	int temp;
	while (n--) {
		cin >> temp;
		if (!Insert(T, temp)) {
			cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
			return;
		}
	}
}

Tree Search(Tree& T, int x) {
	if (T == NULL) return NULL;
	if (T->info == x) return T;
	if (T->info < x) return Search(T->right, x);
	return Search(T->left, x);
}

int countNodes(Tree T) {
	if (T == NULL) return 0;
	return 1 + countNodes(T->left) + countNodes(T->right);
}

int countLeafs(Tree T) {
	if (T == NULL) return 0;
	if (T->left == NULL || T->right == NULL) return 1 + countLeafs(T->left) + countLeafs(T->right);
	return countLeafs(T->left) + countLeafs(T->right);
}

int countInternalNodes(Tree T) {
	return max(0,countNodes(T) - countLeafs(T) - 1);
}

int countOneChild(Tree T) {
	if (T == NULL) return 0;
	if ((T->left == NULL) + (T->right == NULL) == 1) return 1+ countOneChild(T->left) + countOneChild(T->right);
	return countOneChild(T->left) + countOneChild(T->right);
}

int countTwoChildren(Tree T) {
	if (T == NULL) return 0;
	if ((T->left == NULL) + (T->right == NULL) == 0) return 1 + countTwoChildren(T->left) + countTwoChildren(T->right);
	return countTwoChildren(T->left) + countTwoChildren(T->right);
}

int countLess(Tree T, int x){
	if (T == NULL) return 0;
	if (T->info < x) return 1 + countLess(T->left, x) + countLess(T->right, x);
	return countLess(T->left, x) + countLess(T->right, x);
}

int countBetweenValues(Tree T, int x, int y) {
	if (T == NULL) return 0;
	if (T->info > x && T->info < y) return 1+countBetweenValues(T->left, x, y) + countBetweenValues(T->right, x, y);
	return countBetweenValues(T->left,x,y) + countBetweenValues(T->right,x,y);
}

//

int main()
{
	Tree T = NULL;
	inputTree(T);

	cout << "Number of nodes: " << countNodes(T) << endl;
	cout << "Number of leaf nodes: " << countLeafs(T) << endl;
	cout << "Number of internal nodes: " << countInternalNodes(T) << endl;
	cout << "Number of nodes with one child: " << countOneChild(T) << endl;
	cout << "Number of nodes with two children: " << countTwoChildren(T) << endl;

	int x;cout << "Enter x: ";cin >> x;
	cout << "\nNumber of nodes less than " << x << ": " << countLess(T, x) << endl;
	int y; cout << "Enter x,y: ";cin >> x >> y;
	cout << "\nNumber of nodes greater than " << x << " and less than " << y << ": " << countBetweenValues(T, x, y) << endl;

	return 0;
}
