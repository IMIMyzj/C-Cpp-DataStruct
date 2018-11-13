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
		//读入每组序列的N和L
		cin >> L;

		//根据第一行序列建树T
		T = MakeTree(N);

		//根据树T分别判断是否是同一颗树
		for (i = 0; i < L; i++) {
			Tree TTemp = MakeTree(N);

			if (Judge(T, TTemp)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}

		//进入下一次读数的时候先清空树
		FreeTree(T);
		cin >> N;
	}

	return 0;
}

//根据第一棵树构建树
Tree MakeTree(int N) {
	Tree T;
	int i, V;

	//创建新的树
	cin >> V;
	T = NewNode(V);

	for (i = 1; i < N; i++) {
		cin >> V;
		T = Insert(T, V);
	}

	return T;
}

//创建树的一个节点
Tree NewNode(int V) {
	Tree T = new TreeNode;
	T->v = V;
	T->Right = T->Left = NULL;
	T->flag = 0;

	return T;
}

//在节点后面插入一个节点
Tree Insert(Tree T, int V) {
	if (!T) T = NewNode(V);
	else {
		if (V > T->v)	T->Right = Insert(T->Right, V);
		else T->Left = Insert(T->Left, V);
	}

	return T;
}

//判断每一个序列是否一致
int Judge(Tree T, Tree Ttemp) {
	if ((T == NULL) && (Ttemp == NULL)) return 1;
	else if (((T == NULL) && (Ttemp != NULL)) || ((T != NULL) && (Ttemp == NULL))) return -1;
	else if ((T->v) != (Ttemp->v)) return 0;
	else return(Judge(T->Left, Ttemp->Left) && Judge(T->Right, Ttemp->Right));
}


//递归释放Tree每个节点指针的内存空间
void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	delete[] T;
}