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
	//建堆
	for (int i = 0; i < n; i++) {
		cin >> x;
		Insert(x);
	}
	//遍历堆，对于完全树用数组存储，访问父节点和左右节点很有优势
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