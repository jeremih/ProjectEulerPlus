#include "PythagTriplet.h"
#include <iostream>
PythagTriplet::PythagTriplet(int a, int b, int c) {
	this->a = a;
	this->b = b;
	this->c = c;

	this->sum = a + b + c;
	this->prod = a * b * c;
}

int PythagTriplet::getSum() {
	return sum;
}

int PythagTriplet::getProd() {
	return prod;
}

void PythagTriplet::printMe() {
	std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
}