#pragma once
#pragma once
#include <iostream>
#include <algorithm>			// äëÿ min/max
#include "Error.h"
using namespace std;

//-------------------------//
//	num â ñâÿçè Point,
//  åñëè çàäàí <Pair>
//-------------------------//
struct Pair
{
	Pair() {}
	Pair(int a, double b)
	{
		numINT = a;
		numDOUBLE = b;
	}

	int numINT = 0;
	double numDOUBLE = 0;

	// äëÿ ïðèñâîåíèÿ íîâîãî Pair èëè îäíîãî ÷èñëà äëÿ ïàðû.
	Pair& operator =(const Pair& pair)
	{
		this->numINT = pair.numINT;
		this->numDOUBLE = pair.numDOUBLE;
		return *this;
	};
	Pair& operator =(const int& k)
	{
		this->numINT = k;
		this->numDOUBLE = k;
		return *this;
	}
	// âûâîä
	friend ostream& operator<<(ostream& out, const Pair& pair)
	{
		out << pair.numINT << " : " << pair.numDOUBLE << " |";
		return out;
	}
	friend istream& operator>>(istream& in, Pair& pair)
	{
		in >> pair.numINT >> pair.numDOUBLE;
		return in;
	}
	// óìíîæåíèå äâóõ ïàð ÷èñåë
	Pair operator * (Pair& pair)
	{
		Pair new_pair;
		new_pair.numINT = this->numINT * pair.numINT;
		new_pair.numDOUBLE = this->numDOUBLE * pair.numDOUBLE;
		return new_pair;
	}
};
//-------------------------//
//	ñâÿçü ñïèñêà
//-------------------------//
template<typename T>
struct Point
{
	T num;							// int, float, double, Pair
	Point* next = nullptr;			// óêàçàòåëü íà ñëåäóþùèé ýëåìåíò ñïèñêà
};
//-------------------------//
//	èòåðàòîð ñïèñêà
//-------------------------//
template <typename T>
class Iterator
{
private:
	Point<T>* elem = nullptr;		// óêàçàòåëü íà ñâÿçü
public:
	Iterator() { elem = nullptr; }
	Iterator(Point<T>* point) { elem = point; }
	Iterator(const Iterator& it) { elem = it.elem; };
	bool operator == (const Iterator& it) { return elem == it.elem; }
	bool operator != (const Iterator& it) { return elem != it.elem; }
	Iterator& operator ++ ();											// ++i - ñìåùåíèå âïðàâî íà 1
	Iterator operator ++ (int);											// i++ - ñìåùåíèå âïðàâî íà 1
	Iterator& operator + (int n);										// i+n - ñìåùåíèå âïðàâî íà n
	T operator * () const;												// ðàçûìåíîâàíèå èòåðàòîðà (âûâîä)
};

template <typename T>
T Iterator<T>::operator * () const
{
	if (elem)
		return elem->num;
	else
		throw IndexError2();
}

template <typename T>
Iterator<T>& Iterator<T>::operator ++ ()
{
	if (elem == nullptr) throw IndexError2();
	elem = elem->next;
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator ++ (int)
{
	if (elem == nullptr) throw IndexError2();
	Iterator<T> temp(elem);
	++(*this);
	return temp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator + (int n)
{
	for (int i = 0; i < n; i++)
	{
		if (elem == nullptr) throw IndexError2();
		elem = elem->next;
	}
	return *this;
}





//-------------------------//
//	ñâÿçàííûé ñïèñîê
//-------------------------//
template <typename T>
class LinkedList
{
private:
	size_t size = 0;									// ðàçìåð ñïèñêà
	Point<T>* head = nullptr;							// óêàçàòåëü íà ïåðâûé ýëåìåíò
	Point<T>* top = nullptr;							// óêàçàòåëü íà ëàñò ýëåìåíò
	//-------------------------------âûâîä----------------------------------------//

	void output(Point<T>* obj) const;
	void show() const;
	//---------------------------------------------------------------------------//
public:
	friend ostream& operator<<(ostream& out, const LinkedList<T>& list)
	{
		list.show();
		return out;
	}
	friend istream& operator>>(istream& in, LinkedList<T>& list)
	{
		T k;
		in >> k;
		list.push(k);
		return in;
	}
	LinkedList();										// êîíñòðóêòîð
	LinkedList(size_t s, T k);							// êîíñòóêòîð: s - ðàçìåð, k - çíà÷åíèå ïî óìîë÷àíèþ
	~LinkedList();										// äåñòðóêòîð
	LinkedList(const LinkedList<T>& list);				// êîíñòðóêòîð êîïèðîâàíèÿ
	T& operator [](int index) const;					// äîñòóï ïî èíäåêñó
	LinkedList& operator =(const LinkedList<T>& list);	// îïåðàòîð ïðèñâàèâàíèÿ
	LinkedList operator * (LinkedList<T>& list);		// óìíîæåíèå ñïèñêà íà ñïèñîê
	int operator ()() { return size; };					// âîçâðàùåíèå äëèíû ñïèñêà
	void push(T k);										// äîáàâëåíèå â êîíåö ñïèñêà
	T pop();											// óäàëåíèå ïåðâîãî ýëåìåíòà
	Iterator<T> first() { return Iterator<T>(head); }	// âîçâðàùàåò óêàçàòåëü íà ïåðâûé ýëåìåíò
	Iterator<T> last() { return Iterator<T>(top->next); }// âîâçðàùàåò óêàçàåòëü íà ïîñëåäíèé ýëåìåíò

};


// êîíñòðóêòîð
template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	top = nullptr;
	size = 0;
}
// êîíñòðóêòîð ñ ïàðàìåòðàìè
template <typename T>
LinkedList<T>::LinkedList(size_t s, T k)
{
	size = s;
	if (size != 0) {
		//---------ñîçäàåì ãîëîâó è ïåðåäàåì åé çíà÷åíèå k---------//
		Point<T>* obj = new Point<T>;
		obj->num = k;
		head = obj;
		//--------------------------------------------------------//

		//-------ñîçäàåì ñëåäóþùèå size - 1 ýëåìåíòû--------------//
		Point<T>* temp = head;
		for (int i = size - 1; i != 0; i--)
		{
			obj = new Point<T>;
			temp->next = obj;
			obj->num = k;
			temp = obj;
		}
		// õâîñòèê + èòåðàòîðû
		top = obj;

	}
}
// äîáàâëåíèå â êîíåö
template <typename T>
void LinkedList<T>::push(T k)
{
	//------------------------------------------//
	//	Åñëè ðàçìåð 0, òî çàäàåì ãîëîâó = õâîñòó
	//------------------------------------------//
	if (size == 0)
	{
		head = new Point<T>;
		head->num = k;
		top = head;

	}
	//------------------------------------------//
	//	Èíà÷å ÷åðåç õâîñò äîáàâëÿåì íîâûé ýëåìåíò
	//------------------------------------------//
	else {
		Point<T>* obj = new Point<T>;
		top->next = obj;
		obj->num = k;
		top = obj;
	}
	// óâåëè÷èâàåì ðàçìåð, èòåðàòîð íà êîíåö
	size++;
}
// óäàëåíèå íà÷àëüíîãî ýëåìåíòà
template <typename T>
T LinkedList<T>::pop()
{
	if (size == 0) throw EmptySizeError();
	// ñîçäàåì ïðîìåæóòî÷íóþ ñâÿçü, óäàëÿåì ãîëîâó, ïåðåìåùàåì ãîëîâó
	T k = head->num;
	Point<T>* temp = head;
	head = head->next;
	size--;
	delete temp;
	return k;
}
// äåñòðóêòîð
template <typename T>
LinkedList<T>::~LinkedList()
{
	cout << endl << "Âûçâàí äåñòðóêòîð!" << endl << endl;
	while (head != nullptr)
	{
		pop();
	}
}
//----------------------------âûâîä----------------------------------//
template <typename T>
void LinkedList<T>::output(Point<T>* obj) const
{
	cout << obj->num << " ";
	if (obj == top) return;
	output(obj->next);
}
template <typename T>
void LinkedList<T>::show() const
{
	if (size == 0) cout << "Ñïèñîê ïóñò" << endl;
	else output(head);
}
//-------------------------------------------------------------------//
// èíäåêñ
template <typename T>
T& LinkedList<T>::operator[](int index) const
{
	if (index == 0 && size == 0) throw IndexError();
	if (index < 0) throw IndexError1();
	if (index >= size) throw IndexError2();
	Point<T>* temp = head;
	int count = 0;
	while (temp != nullptr)
	{
		if (count == index)
			return temp->num;
		temp = temp->next;
		++count;
	}
}
// êîíñòðóêòîð êîïèðîâàíèÿ
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
}
// ïðèñâàèâàíèå
template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& list)
{
	// ñîçäàåì size_temp, ò.ê. pop óìåíüøàåò size, íóæíî çàñòàíèòü
	int size_temp = size;
	// óäàëÿåì âñå ýëåìåíòû
	for (int i = 0; i < size_temp; i++)
	{
		this->pop();
	}
	// êîïèðóåì ÷åðåç push()
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
	return *this;
}
// óìíîæåíèå
template <typename T>
LinkedList<T> LinkedList<T>::operator * (LinkedList<T>& list)
{
	// ñîçäàåì íîâûé ñïèñîê ïî ìàêñ ðçàìåðó, îáíóëÿåì ÷åðåç âòîðîé ïàðàìåòð
	T nulik;
	nulik = 0;
	LinkedList<T> new_list;
	for (int i = 0; i < min((int)size, list()); i++)
	{
		new_list.push((*this)[i] * list[i]);
	}
	for (int i = 0; i < max((int)size, list()) - min((int)size, list()); i++)
	{
		new_list.push(nulik);
	}
	return new_list;
}