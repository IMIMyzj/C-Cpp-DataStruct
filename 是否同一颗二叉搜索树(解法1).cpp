#include <iostream>

using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode {
	int v;
	Tree Left, Right;
	int flag;
};


Tree MakeTree(int N);
Tree NewNode(int V);
Tree Insert(Tree T, int V);
bool Check(Tree T, int V);
int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);

int main() {
	int N, L, i;
	Tree T;

	cin >> N;
	while (N) {
		//����ÿ�����е�N��L
		cin >> L;

		//���ݵ�һ�����н���T
		T = MakeTree(N);

		//������T�ֱ��ж��Ƿ���ͬһ����
		for (i = 0; i < L; i++) {
			if (Judge(T, N)) cout << "Yes" << endl;
			else cout << "No" << endl;
			ResetT(T);
		}

		//������һ�ζ�����ʱ���������
		FreeTree(T);
		cin >> N;
	}

	return 0;
}

//���ݵ�һ����������
Tree MakeTree(int N) {
	Tree T;
	int i, V;

	//�����µ���
	cin >> V;
	T = NewNode(V);

	for (i = 1; i < N; i++) {
		cin >> V;
		T = Insert(T, V);
	}

	return T;
}

//��������һ���ڵ�
Tree NewNode(int V) {
	Tree T = new TreeNode;
	T->v = V;
	T->Right = T->Left = NULL;
	T->flag = 0;

	return T;
}

//�ڽڵ�������һ���ڵ�
Tree Insert(Tree T, int V) {
	if (!T) T = NewNode(V);
	else {
		if (V > T->v)	T->Right = Insert(T->Right, V);
		else T->Left = Insert(T->Left, V);
	}

	return T;
}

//�ж�ÿһ�������Ƿ�һ��
int Judge(Tree T, int N) {
	int i, V, flag = 0;
	cin >> V;

	if (V != T->v) flag = 1;
	else T->flag = 1;

	for (i = 1; i < N; i++) {
		cin >> V;
		if ((!flag) && (!Check(T, V))) flag = 1;
	}

	if (flag) return 0;
	else return 1;
}

//��ÿ�������У�������ж���˳���ǲ��Ǻ�ԭʼ��Treeһ��
bool Check(Tree T, int V) {
	if (T->flag) {
		if (V < T->v) return Check(T->Left, V);
		else if (V > T->v) return Check(T->Right, V);
		else return 0;
	}
	else {
		if (V == T->v) {
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}

//�ݹ����Tree�ϵ�flag
void ResetT(Tree T) {
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}

//�ݹ��ͷ�Treeÿ���ڵ�ָ����ڴ�ռ�
void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	delete[] T;
}