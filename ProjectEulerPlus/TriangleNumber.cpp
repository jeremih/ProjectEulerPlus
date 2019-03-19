#include "TriangleNumber.h"

TriangleNumber::TriangleNumber() {
	currVal = 1;
	nextToAdd = 2;
}

long TriangleNumber::increment() {
	currVal += nextToAdd++;
	return currVal;
}

long TriangleNumber::getCurrVal() {
	return currVal;
}

long TriangleNumber::getIncrement() {
	return nextToAdd;
}