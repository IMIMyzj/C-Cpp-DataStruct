#include <iostream>
using namespace std;

#define MaxSize 10001
typedef int ELementType;
typedef int SetName;
typedef ELementType SetType[MaxSize];//�����Ŵ洢���ֵ������ֵ�洢���ڵ���,������洢��Ϊ����ʱ���ʾ��ģ��С

SetName Find(SetType S, ELementType X) {
	//����·��ѹ�����ø��ڵ㵽Ѱ�ҽڵ�·���ϵĽڵ㶼ֱ��ָ������ڵ�
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}

void Union(SetType S, SetName Root1, SetName Root2) {
	//����ģ���кϲ�
	if (S[Root2] < S[Root1]) {	//����Ϊ�����������жϸ߶�Ҫ��һ��
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

	//1-N����ʵ���ϴ洢��1--N��
	for (int i = 0; i < N + 1; i++)
		a[i] = -1;

	//�ߴ���߼��
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

	//�����
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