#include <iostream>
#include <vector>
#include <algorithm>

//C++11 中引入 std::ref 用于取某个变量的引用，这个引入是为了解决一些传参问题。

using namespace std;

struct square
{
	typedef void resule_type;                  //返回结果类型定义；
	void operator ()(int& x) {
		x = x * x;
	}
};

int main( int argc, char** argv){

	typedef double(*pfunc)(double);
	pfunc pf = sqrt;

	std::cout << pf(5.0) << endl;
	std::cout << std::ref(pf)(5.0) << endl;             //包装函数指针

	square sq;
	int x = 5;
	ref(sq)(x);//包装函数
	cout << x << endl;


	vector<int> v = { 1,2,3,4,5,6 };
	for_each(v.begin(), v.end(), sq);
	
	cout << "==============" << endl;
	for_each(v.begin(), v.end(), [](int &a) {
		cout << a << endl;
	});
	cout << endl;

	for_each (v.begin(), v.end(), std::ref(sq));//传递给算法引用

	cout << "==============" << endl;
	for_each(v.begin(), v.end(), [](int &a) {
		cout << a << endl;
	});
	cout << endl;
};