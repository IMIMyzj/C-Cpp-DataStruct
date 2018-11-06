#include <iostream>

using namespace std;
struct Node {
	int root;		//��¼�ڵ��Ƿ��Ǹ��ڵ�
	int left;
	int right;
};
int main() {
	int n;
	struct Node nodes[10];
	cin >> n;

	//��ʼ�����ڵ�
	for (int i = 0; i < n; ++i) {		
		nodes[i].root = 1;				//û���ӵĽڵ㶼�Ǹ��ڵ�
		nodes[i].left = -1;				//û���ӵĽڵ����Ҷ��Ӷ�Ϊ��
		nodes[i].right = -1;
	}

	//������
	for (int i = 0; i < n; ++i) {		
		char ch1, ch2;
		cin >> ch1 >> ch2;
		if (isdigit(ch1)) {				//�������Ӵ��ڣ���������������ýڵ�
			nodes[i].left = ch1 - '0';	//ָ��ָ�������
			nodes[ch1 - '0'].root = 0;	//�����ȡ�����ڵ���
		}
		if (isdigit(ch2)) {
			nodes[i].right = ch2 - '0';
			nodes[ch2 - '0'].root = 0;
		}
	}

	//�ҵ�����
	int root;
	for (int i = 0; i < n; ++i)			
		if (nodes[i].root == 1) {
			root = i;
			break;
		}

	//���������!!!!�������Ҷ�ڵ㣻����������̣��Ӹ��ڵ㿪ʼ���ν����Ҷ�����ӣ�ֱ������Ϊ��
	int leaves = 0;			//��¼���Ҷ�ڵ�������������ʱ��һ���ڵ����ǰû�пո�
	int queue[10];			//�ڵ���У�ֻ����ڵ��±�
	int head = 0, rear = 0;
	queue[rear++] = root;	//���ڵ����
	while (rear - head) {
		int node = queue[head++];		//���׽ڵ����
		if (nodes[node].left == -1 && nodes[node].right == -1) {	//���Ҷ�ڵ�
			if (leaves)
				cout << " ";
			cout << node;
			++leaves;
		}
		if (nodes[node].left != -1) {		//������ڣ���������
			queue[rear++] = nodes[node].left;
		}
		if (nodes[node].right != -1) {		//������ڣ��Ҷ������
			queue[rear++] = nodes[node].right;
		}
	}

	return 0;
}