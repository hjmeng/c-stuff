#include <iostream>

using namespace std;

int main() {
	int x;
	cout << "Please enter a number: ";
	cin >> x;
	if(x>=56 && x<=78)
		cout << "YOU WIN!" << endl;
	else
		cout << "YOU LOSE!" << endl;
	return 0;
}
