#pragma once
#include <iostream>
using namespace std;
struct fraction
{
	double first;
	int second;
	void Init(double, int);
	void Read();
	void Show();
	double Element(int j);
};