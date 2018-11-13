/*------------------------------------题目-----------------------------------*/
//An AVL tree is a self-balancing binary search tree. 
//In an AVL tree, the heights of the two child subtrees of any node differ by at most one;
//if at any time they differ by more than one, rebalancing is done to restore this property.
//Figures 1-4 illustrate the rotation rules.
/*--------------------------------------------------------------------------*/
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int val;
	struct node *left, *right;
};

//RR旋
node *rotateRight(node *root) {
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

//LL旋
node *rotateLeft(node *root) {
	node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

//LR旋，先右旋后左旋
node *rotateLeftRight(node *root) {
	root->left = rotateRight(root->left);
	return rotateLeft(root);
}

//RL旋，先左旋后右旋
node *rotateRightLeft(node *root) {
	root->right = rotateLeft(root->right);
	return rotateRight(root);
}

//非常NB, 用递归一层+1来计算层数
int getHeight(node *root) {
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

//插入节点
node *insert(node *root, int val) {
	//创建新节点
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	}
	//创建左节点，此外还要判断插入后该节点高度有没有出事，凭借递归从最底下开始调整
	else if (val < root->val) {
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2)
			root = val < root->left->val ? rotateLeft(root) : rotateLeftRight(root);
	}
	//创建右节点，此外还要判断插入后该节点高度有没有出事，凭借递归从最底下开始调整
	else {
		root->right = insert(root->right, val);
		if (getHeight(root->left) - getHeight(root->right) == -2)
			root = val > root->right->val ? rotateRight(root) : rotateRightLeft(root);
	}
	return root;
}

int main() {
	int n, val;
	cin >> n;
	node *root = NULL;

	for (int i = 0; i < n; i++) {
		cin >> val;
		root = insert(root, val);
	}
	cout << root->val;
	return 0;
}