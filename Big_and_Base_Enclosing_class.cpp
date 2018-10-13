#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int k;
	Base():k(0){}
	Base(int n) :k(n) { }
};
class Big
{
public:
	int v;
	Base b;

	// 在此处补充你的代码
	Big(int n):v(n+1),b(n){}
	Big(const Big &n){
		v = n.v + 2;
		cout << "调用了复制构造函数" << endl; }
};
int main()
{
	int n;
	while (cin >> n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
}