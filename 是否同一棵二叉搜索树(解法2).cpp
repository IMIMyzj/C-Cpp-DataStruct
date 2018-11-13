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
int Judge(Tree T, Tree Ttemp);
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
			Tree TTemp = MakeTree(N);

			if (Judge(T, TTemp)) cout << "Yes" << endl;
			else cout << "No" << endl;
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
int Judge(Tree T, Tree Ttemp) {
	if ((T == NULL) && (Ttemp == NULL)) return 1;
	else if (((T == NULL) && (Ttemp != NULL)) || ((T != NULL) && (Ttemp == NULL))) return -1;
	else if ((T->v) != (Ttemp->v)) return 0;
	else return(Judge(T->Left, Ttemp->Left) && Judge(T->Right, Ttemp->Right));
}


//�ݹ��ͷ�Treeÿ���ڵ�ָ����ڴ�ռ�
void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	delete[] T;
}