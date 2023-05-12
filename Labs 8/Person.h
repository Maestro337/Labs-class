#pragma once
#include "Object.h"


class Person :
	public Object
{
protected:
	string name;
	int age;
	friend istream& operator>>(istream& in, Person& p);			// ââîä
	friend ostream& operator<<(ostream& out, const Person& p);	// âûâîä
public:
	void set_name(string name);									// ñåòòåð èìåíè
	void set_age(int age);										// ñåòòåð âîçðàñòà
	string get_name();											// ãåòòåð èìåíè
	int get_age();												// ãåòòåð âîçðàñòà
	Person();													// êîíñòðóêòîð áåç ïàðàìåòðîâ
	Person(string name, int age);								// êîíñòðóêòîð ñ ïàðàìåòðàìè
	Person(const Person& p);									// êîíñòðóêòîð êîïèðîâàíèÿ
	~Person();													// äåñòðóêòîð
	void Show();
	void HandleEvent(const TEvent& e);
	int AvgAge() { return age; }

};