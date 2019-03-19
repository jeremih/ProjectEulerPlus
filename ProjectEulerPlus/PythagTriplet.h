#pragma once
#include <string>

class PythagTriplet{
private:
	int a;
	int b;
	int c;
	
	int sum;
	int prod;

public:
	PythagTriplet(int a, int b, int c);

	int getSum();
	int getProd();
	void printMe();
};