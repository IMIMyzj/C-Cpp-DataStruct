#include <iostream>

using namespace std;

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);

int main() {
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1, R2)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

Tree BuildTree(struct TreeNode T[]) {
	int N = 0, i;
	int check[MaxTree];
	ElementType tl, tr;
	Tree Root = Null;

	cin >> N;

	if (N) {
		for (i = 0; i < N; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			cin >> T[i].Element >> tl >> tr;
			
			//判断根节点时候，如果发现在数据的表中有没出现的数字，那就是根节点
			if (tl != '-') {
				T[i].Left = tl - '0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;

			if (tr != '-') {
				T[i].Right = tr - '0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}

		for (i = 0; i < N; i++) 
			if (!check[i]) break;

		Root = i;
	}

	return Root;
}

int Isomorphic(Tree R1, Tree R2) {
	//双空
	if ((R1 == Null) && (R2 == Null))
		return 1;
	//单空
	if (((R1 == Null) && (R2 != Null))||((R1 != Null) && (R2 == Null)))
		return 0;
	//树根值不同
	if (T1[R1].Element != T2[R2].Element)
		return 0;
	//左指数都空，判别右指数
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	//左指数不空，且左代表的数相同，就判断左和右分别一样么
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
		return(Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	//左边不一样，看看同一结点左右同不同
	else
		return(Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}