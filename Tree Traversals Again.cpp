#include <stdio.h>
#include <iostream>

using namespace std;
struct Node {
	int tag;		//��ǽڵ��ǵڼ��ν�ջ
	int num;
};
//���������Ӧ��ջ˳�����������Ӧ��ջ˳��
//������������������ͬ���ǽڵ��ջ��Ҫ��������ջ��tag���ڶ�����ջ��ǣ������Ҷ��ӱ�������ٳ�ջ;
//����ʵ���ϣ�ÿ�����������popʱ�����ջ���Ǳ�ǹ��Ľڵ㣨tag=2����ѭ�����������û�б�ǹ���tag=1��������ǣ���������ѹջ��
//ջ��tag=2�Ľڵ��Ӧ����������ѵ����Ľڵ㣻ѭ�������������ĵ�һ��tag=1�Ľڵ�Ŷ�Ӧ���������ǰpop�Ľڵ�
int main() {
	int n;
	cin >> n;
	int flag = 0;
	struct Node stack[30];
	int size = 0;			//ջԪ�ش�С��ָ��ջ������һ��λ��
	for (int i = 0; i < 2 * n; ++i) {
		char s[10];
		cin >> s;
		if (s[1] == 'u') {		//push
			cin >> stack[size].num;		//��ջ
			stack[size].tag = 1;				//��ǵ�һ����ջ
			++size;
		}
		else {					//pop
			while (size > 0 && stack[size - 1].tag == 2) {	//ѭ������ջ��tag=2�Ľڵ�
				if (flag)
					printf(" ");
				flag = 1;
				printf("%d", stack[--size].num);
			}
			if (size > 0)		//�����������Ӧ��Ҫ�����Ľڵ㵯����ѹջ������Ǽ���
				stack[size - 1].tag = 2;
		}
	}
	while (size) {				//��ջ��ʣ��ڵ����ε���
		if (flag) {
			printf(" ");
		}
		flag = 1;
		printf("%d", stack[--size].num);
	}
	system("pause");
	return 0;
}