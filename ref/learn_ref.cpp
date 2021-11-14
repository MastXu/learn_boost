#include <iostream>
#include <vector>
#include <algorithm>

//C++11 ������ std::ref ����ȡĳ�����������ã����������Ϊ�˽��һЩ�������⡣

using namespace std;

struct square
{
	typedef void resule_type;                  //���ؽ�����Ͷ��壻
	void operator ()(int& x) {
		x = x * x;
	}
};

int main( int argc, char** argv){

	typedef double(*pfunc)(double);
	pfunc pf = sqrt;

	std::cout << pf(5.0) << endl;
	std::cout << std::ref(pf)(5.0) << endl;             //��װ����ָ��

	square sq;
	int x = 5;
	ref(sq)(x);//��װ����
	cout << x << endl;


	vector<int> v = { 1,2,3,4,5,6 };
	for_each(v.begin(), v.end(), sq);
	
	cout << "==============" << endl;
	for_each(v.begin(), v.end(), [](int &a) {
		cout << a << endl;
	});
	cout << endl;

	for_each (v.begin(), v.end(), std::ref(sq));//���ݸ��㷨����

	cout << "==============" << endl;
	for_each(v.begin(), v.end(), [](int &a) {
		cout << a << endl;
	});
	cout << endl;
};