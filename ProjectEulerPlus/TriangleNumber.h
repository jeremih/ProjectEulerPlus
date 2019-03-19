#pragma once
#ifndef TRIANGLE_NUMBER
#define TRIANGLE_NUMBER
#endif // !TRIANGLE_NUMBER

class TriangleNumber {
private:
	long currVal;
	long nextToAdd;

public:
	TriangleNumber();
	long increment();
	long getCurrVal();
	long getIncrement();
};