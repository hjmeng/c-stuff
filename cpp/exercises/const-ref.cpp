#include <iostream>
using namespace std;

//void foo(const int &x) {
//trying to change a const results in a compilation error
//passing with a constant reference saves memory, but cannot be changed
void foo(int &x) {
	x=6;
}

int main() {
	int x =5;
	foo(x);
	cout << x << endl;
	return 0;
}
