#include <iostream>

using namespace std;

class A {
public:
	//A() = default;
	virtual void f() = 0;
	//void f() {cout << "\n A : f()";}
	virtual void display() { cout << "\n A : display"; }
};

class B : public A {
public:
	void display() {cout << "\n B : display";}
	void f() {cout << "\n B : f()"; }
};

int main() {

	//A *base = new B();
	A *base;
	B derived;
	base = &derived;
	base->f();
	base->display();
	//base


}