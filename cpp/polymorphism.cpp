/*
   Example of late-binding with virtual functions
*/
#include <iostream>
using namespace std;

class Animal {
	public:
		void /*nonvirtual*/ move() {
			cout << "This animal moves in some way" << endl;
		}
		virtual void eat() {
			// The class "Animal" may possess a declaration for eat() if desired.
			cout << "Animals eat... stuff" << endl;
		}
};

class Llama : public Animal {
	public:
		void move() {
			cout << "The llama moves in some way" << endl;
		}
		// The non virtual function move() is inherited but cannot be overridden
		void eat() {
			cout << "Llamas eat grass!" << endl;
		}
};

int main() {
	Animal *p;
	Animal foo = Animal();
	p = &foo;
	p->move();
	p->eat();

	cout << endl;

	Llama a = Llama();
	p = &a;
	p->move();
	p->eat();
}
