#include "Person.h"
#include "Student.h"

void f1(Person& p)
{
	p.set_age(0);
}

Student f2()
{
	Student s("Åãîð", 21, "èíôîðìàòèêà", 5);
	return s;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	cout << "Ñîçäàåì äâà îáúåêòà êëàññà Person, îäèí áåç ïàðàìåòðîâ, äðóãîé ñ: " << endl;
	Person p1;
	Person p2("Äàíèë", 18);
	cout << p1 << endl << p2 << endl;
	cout << "Êîíñòóêòîð êîïèðîâàíèÿ: p1 = p2" << endl;
	p1 = p2;
	cout << p1 << endl;
	cout << "Ñîçäàíèå îáúåêòà êëàññà Student, îäèí ñ ïàðàìåòðàìè, äðóãîé áåç: " << endl;
	Student s1;
	cout << s1 << endl;
	Student s2("Ìèõàèë", 17, "ìàòåìàòèêà", 5);
	cout << s2 << endl;
	cout << "Èçìåíåíèå ïîëåé îáúåêòà êëàññà Student" << endl;
	cin >> s1;
	cout << s1 << endl;
	cout << "Ñîçäàíèå îáúåêòà êëàññà Student ÷åðåç ô-èþ f1" << endl;
	Student s3 = f2();
	cout << s3 << endl;
	cout << "Èçìåíåíèå àòðèáóòà îáúåêòà êëàññà Person ÷åðåç f2" << endl;
	f1(p1);
	cout << p1.get_age() << endl;
	cout << "Âèðòóàëüíàÿ ôóíêöèÿ print() äëÿ Person* p3 = &s3: " << endl;
	Person* p3 = &s3;
	p3->print();
	return 0;
}