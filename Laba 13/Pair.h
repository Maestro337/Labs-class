#pragma once
#include <iostream>
using namespace std;
class Pair
{
public:
	int a;
	double b;
	friend istream& operator>>(istream& in, Pair& p);			// ââîä
	friend ostream& operator<<(ostream& out, const Pair& p);	// âûâîä

	Pair(int a, double b);										// êîíñòðóêòîð ñ ïàðàìåòðàìè
	Pair();														// êîíñòðóêòîð áåç ïàðàìåòðîâ 
	Pair(const Pair& p);										// êîíñòðóêòîð êîïèðîâàíèÿ
	~Pair();													// äåñòðóêòîð
	Pair& operator=(const Pair& p);								// ïðèñâàèâàíèå
	Pair operator-(const Pair& p);								// âû÷èòàíèå äâóõ îáúåêòîâ
	Pair& operator+(int a);										// ïðèáàâëåíèå int ÷èñëà
	Pair& operator+(double b);									// ïðèáàâëåíèå double ÷èñëà
	Pair& operator++();											// ïðåôèêñíûé èíêðåìåíò
	Pair operator++(int);										// ïîñòôèêñíûé èíêðåìåíò
	Pair operator+(const Pair& p);
	bool operator!=(const Pair& p) { return !((this->a == p.a) && (this->b == p.b)); }
	bool operator==(const Pair& p) { return ((this->a == p.a) && (this->b == p.b)); }
	bool operator>(const Pair& p) { return (this->a > p.a) || (this->b > p.b); }
	bool operator>=(const Pair& p) { return (this->a >= p.a) || (this->b >= p.b); }
	bool operator<=(const Pair& p) { return (this->a <= p.a) || (this->b <= p.b); }
	bool operator<(const Pair& p) { return (this->a < p.a) || (this->b < p.b); }
	// óìíîæåíèå äâóõ ïàð ÷èñåë
	Pair operator * (Pair& pair)
	{
		Pair new_pair;
		new_pair.a = this->a * pair.a;
		new_pair.b = this->b * pair.b;
		return new_pair;
	}
};
