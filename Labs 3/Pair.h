#pragma once
#include <iostream>
using namespace std;
class Pair
{
	int a;
	double b;


public:
	friend istream& operator>>(istream& in, Pair& p);			
	friend ostream& operator<<(ostream& out, const Pair& p);	

	Pair(int a, double b);										
	Pair();														 
	Pair(const Pair& p);										
	~Pair();													
	Pair& operator=(const Pair& p);								
	Pair operator-(const Pair& p);								
	Pair& operator+(int a);										
	Pair& operator+(double b);									
	Pair& operator++();											
	Pair operator++(int);										
};
