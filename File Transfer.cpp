#include <iostream>
using namespace std;

#define MaxSize 10001
typedef int ELementType;
typedef int SetName;
typedef ELementType SetType[MaxSize];//数组标号存储结点值，数组值存储父节点标号,当数组存储的为负数时候表示规模大小

SetName Find(SetType S, ELementType X) {
	//进行路径压缩，让根节点到寻找节点路径上的节点都直接指向其根节点
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}

void Union(SetType S, SetName Root1, SetName Root2) {
	//按规模进行合并
	if (S[Root2] < S[Root1]) {	//树高为负数，所以判断高度要反一下
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}	
}

int main() {
	int N;
	int ComputerA, ComputerB;
	char operation;
	SetType a;

	cin >> N;

	//1-N数字实际上存储在1--N处
	for (int i = 0; i < N + 1; i++)
		a[i] = -1;

	//边存入边检查
	cin >> operation;
	while (operation != 'S') {
		if (operation == 'I') {
			cin >> ComputerA >> ComputerB;
			Union(a, Find(a, ComputerA), Find(a, ComputerB));
		}
		else if (operation == 'C') {
			cin >> ComputerA >> ComputerB;
			if (Find(a, ComputerA) == Find(a, ComputerB))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		cin >> operation;
	}

	//最后检查
	int components = 0;
	for (int i = 1; i < N + 1; i++)
		if (a[i] < 0)
			components++;

	if (components == 1)
		cout << "The network is connected." << endl;
	else
		cout << "There are " << components << " components." << endl;
	
	system("pause");
	return 0;
}