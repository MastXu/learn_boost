#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <string>

#include "boost/bind.hpp"

using namespace boost;
using namespace std;

int f(int a, int b) {
	return a + b;
}

int g(int a, int b, int c) {
	return a + b + c;
}


int main() {
	cout << bind(f, 1, 2)() << endl;
	cout << bind(g, 1, 2, 3)() << endl;

	cout << bind(g, _1, _1, _3)(1,2,3) << endl;

}