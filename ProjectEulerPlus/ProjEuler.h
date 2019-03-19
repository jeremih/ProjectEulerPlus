#pragma once
#include <vector>
#include <memory>
#include "PythagTriplet.h"
#include "TriangleNumber.h"
#include "BigNumbor.h"

int divisibleValue(int);
long long sumSquareSubtract(int);
std::vector<long>* makePrimeList(long n);
long getPrime(int, std::vector<long>*);
long digiProd(int, int, std::string);
long long getPythagProduct(int, std::vector<PythagTriplet*> &);
std::vector<PythagTriplet*> getTripleVector(int);
std::vector<long>* modifyPrimeList(std::vector<long>*, long);
long long getPrimeSum(long, std::vector<long>*);
std::shared_ptr<std::vector<long>> sieveOfEratosthenes(long);
long getMaxProduct(std::vector<std::vector<int>>);
int factorCount(long);
long getTriangNumWithNDivisors(int);
std::string addABunchONums();
std::string addABunchONums2();