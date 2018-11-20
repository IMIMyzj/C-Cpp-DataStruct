#include <iostream>
using namespace std;

#define MAXN 1001
#define MINH -10001

int H[MAXN], Size;

void Create() {
	Size = 0;
	H[0] = MINH;
}

void Insert(int X) {
	int i;
	for (i = ++Size; H[i / 2] > X; i /= 2)
		H[i] = H[i / 2];
	H[i] = X;
}

int main() {
	int n, m, x, j;

	cin >> n >> m;
	Create();
	//����
	for (int i = 0; i < n; i++) {
		cin >> x;
		Insert(x);
	}
	//�����ѣ�������ȫ��������洢�����ʸ��ڵ�����ҽڵ��������
	for (int i = 0; i < m; i++) {
		cin >> j;
		cout << H[j];
		while (j > 1) {
			j /= 2;
			cout << ' ' << H[j];
		}
		cout << endl;
	}

	return 0;
}