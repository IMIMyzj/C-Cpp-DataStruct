/*********************************************
*测试数据
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

第一行表示：链表数据起始地址 总共几个结点 几个结点翻转一次
剩下行表示：链表数据起始地址 该结点数据 下一个结点地址

*输出数据
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

按照结点上的数据进行结点翻转，数据起始点不变，但是其下一个结点地址需要改变
*********************************************/
#include <iostream>
using namespace std;
int main() {
	int first, k, n, sum = 0;
	cin >> first >> n >> k;
	int temp, data[100000], next[100000], list[100000], result[100000];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		cin >> data[temp] >> next[temp];
	}
	while (first != -1) {
		list[sum++] = first;
		first = next[first];
	}//排好首地址

	/*关键的两步*/
	for (int i = 0; i < sum; i++) result[i] = list[i];//先全部放进去，不用换位置的也就不用动了
	for (int i = 0; i < (sum - sum % k); i++)//总数减去余数为需要换位置的前几个数
		result[i] = list[(i / k * k + k - 1) - (i % k)];//每个周期内的数值位置转换，即先找到该数对应的周期末尾数，然后用%求出应当减去的数

	for (int i = 0; i < sum - 1; i++)
		printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
	printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
	return 0;
}