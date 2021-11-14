#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <string>

using namespace std;

void f(int& n1, int& n2, const int& n3)
{
	std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
	++n1; // increments the copy of n1 stored in the function object
	++n2; // increments the main()'s n2
	//++n3; // increments the main()'s n2
}

void threadFunc(std::string &str, int a)
{
	str = "change by threadFunc";
	a = 13;
}


int main() {
	int n1 = 1, n2 = 2, n3 = 3;
/************************************************************************/
/* 即使函数形参是引用，不加ref，仍然是拷贝赋值；                                                                     */
/************************************************************************/
	std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
	n1 = 10;
	n2 = 11;
	n3 = 12;
	std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
	bound_f();
	std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';

/************************************************************************/
/* 即使函数形参不是引用，加ref，仍然是拷贝赋值；                                                                     */
/************************************************************************/

	cout << "====================================================================" << endl;
	std::string str("main");
	int a = 9;
	std::thread th(threadFunc, std::ref(str), std::ref(a));

	th.join();

	std::cout << "str = " << str << std::endl;
	std::cout << "a = " << a << std::endl;

	return 0;
}