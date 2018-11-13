/*------------------------------------��Ŀ-----------------------------------*/
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

//RR��
node *rotateRight(node *root) {
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

//LL��
node *rotateLeft(node *root) {
	node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

//LR����������������
node *rotateLeftRight(node *root) {
	root->left = rotateRight(root->left);
	return rotateLeft(root);
}

//RL����������������
node *rotateRightLeft(node *root) {
	root->right = rotateLeft(root->right);
	return rotateRight(root);
}

//�ǳ�NB, �õݹ�һ��+1���������
int getHeight(node *root) {
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

//����ڵ�
node *insert(node *root, int val) {
	//�����½ڵ�
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	}
	//������ڵ㣬���⻹Ҫ�жϲ����ýڵ�߶���û�г��£�ƾ��ݹ������¿�ʼ����
	else if (val < root->val) {
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2)
			root = val < root->left->val ? rotateLeft(root) : rotateLeftRight(root);
	}
	//�����ҽڵ㣬���⻹Ҫ�жϲ����ýڵ�߶���û�г��£�ƾ��ݹ������¿�ʼ����
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