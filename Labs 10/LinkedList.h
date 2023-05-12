#pragma once
#include <iostream>
#include <algorithm>			// äëÿ min/max
#include <fstream>

using namespace std;


class Pair
{
public:
	Pair() {}
	Pair(int a, double b);

	int numINT = 0;
	double numDOUBLE = 0;

	Pair& operator =(const Pair& pair);
	Pair& operator =(const int& k);
	// âûâîä
private:
	friend fstream& operator>>(fstream& fin, Pair& p)
	{
		fin >> p.numINT;
		fin >> p.numDOUBLE;
		return fin;
	}
	friend fstream& operator<<(fstream& fout, const Pair& p)
	{
		fout << p.numINT << "\n" << p.numDOUBLE << "\n";
		return fout;
	}

	friend ostream& operator<<(ostream& out, const Pair& pair)
	{
		out << pair.numINT << " : " << pair.numDOUBLE;
		return out;
	}
	friend istream& operator>>(istream& in, Pair& pair)
	{
		in >> pair.numINT >> pair.numDOUBLE;
		return in;
	}
public:
	Pair operator * (Pair& pair);								// óìíîæåíèå äâóõ ïàð ÷èñåë
	Pair operator-(const Pair& p);								// âû÷èòàíèå äâóõ îáúåêòîâ
	Pair& operator+(int a);										// ïðèáàâëåíèå int ÷èñëà
	Pair& operator+(double b);									// ïðèáàâëåíèå double ÷èñëà
	Pair& operator++();											// ïðåôèêñíûé èíêðåìåíò
	Pair operator++(int);										// ïîñòôèêñíûé èíêðåìåíò
	bool operator<=(const Pair& p);
};

bool Pair::operator<=(const Pair& p)
{
	return this->numINT <= p.numINT && this->numDOUBLE <= p.numDOUBLE;
}
Pair Pair::operator*(Pair& pair)
{
	Pair new_pair;
	new_pair.numINT = this->numINT * pair.numINT;
	new_pair.numDOUBLE = this->numDOUBLE * pair.numDOUBLE;
	return new_pair;
}

Pair& Pair::operator =(const Pair& pair)
{
	this->numINT = pair.numINT;
	this->numDOUBLE = pair.numDOUBLE;
	return *this;
};

Pair& Pair::operator =(const int& k)
{
	this->numINT = k;
	this->numDOUBLE = k;
	return *this;
}

Pair::Pair(int a, double b)
{
	numINT = a;
	numDOUBLE = b;
}

Pair Pair::operator-(const Pair& p)
{
	Pair res(numINT - p.numINT, numDOUBLE - p.numDOUBLE);
	return res;

}
Pair& Pair::operator+(int a)
{
	this->numINT += a;
	return *this;
}
Pair& Pair::operator+(double b)
{
	this->numDOUBLE += b;
	return *this;
}

Pair& Pair::operator++()
{
	++numINT; ++numDOUBLE;
	return *this;
}

Pair Pair::operator ++(int)
{
	Pair temp = *this;
	this->numINT++; this->numDOUBLE++;
	return temp;
}




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
	void operator ++ () { elem = elem->next; };			// ++i - ñìåùåíèå âïðàâî íà 1
	void operator ++ (int) { elem = elem->next; };		// i++ - ñìåùåíèå âïðàâî íà 1
	//---------// i+n - ñìåùåíèå âïðàâî íà n
	Iterator& operator + (int n)
	{
		for (int i = 0; i < n && elem->next != nullptr; i++)
			elem = elem->next;
		return *this;
	}
	T operator * () const { return elem->num; };      // ðàçûìåíîâàíèå èòåðàòîðà (âûâîä)
};

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
	LinkedList();											// êîíñòðóêòîð
	LinkedList(size_t s, T k);								// êîíñòóêòîð: s - ðàçìåð, k - çíà÷åíèå ïî óìîë÷àíèþ
	~LinkedList();											// äåñòðóêòîð
	LinkedList(const LinkedList<T>& list);					// êîíñòðóêòîð êîïèðîâàíèÿ
	T& operator [](int index) const;						// äîñòóï ïî èíäåêñó
	LinkedList& operator =(const LinkedList<T>& list);		// îïåðàòîð ïðèñâàèâàíèÿ
	LinkedList operator * (LinkedList<T>& list);			// óìíîæåíèå ñïèñêà íà ñïèñîê
	int operator ()() { return size; };						// âîçâðàùåíèå äëèíû ñïèñêà
	void push(T k);											// äîáàâëåíèå â êîíåö ñïèñêà
	T pop();												// óäàëåíèå ïåðâîãî ýëåìåíòà
	Iterator<T> first() { return Iterator<T>(head); }		// âîçâðàùàåò óêàçàòåëü íà ïåðâûé ýëåìåíò
	Iterator<T> last() { return Iterator<T>(nullptr); }     // âîâçðàùàåò óêàçàåòëü íà ïîñëåäíèé ýëåìåíò
	size_t give_size() { return size; }						// äëèíà ñïèñêà
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
	while (head != nullptr)
	{
		pop();
	}
}
//----------------------------âûâîä----------------------------------//
template <typename T>
void LinkedList<T>::output(Point<T>* obj) const
{
	cout << obj->num << "\n";
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
	if (index < size && index >= 0)
	{
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
	cout << endl << endl;
	perror("Îøèáêà èíäåêñèðîâàíèÿ");
	cout << endl;
	exit(1);
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



template <typename T>
class FileIO
{
	LinkedList <T> list;								// áóôåðíûé ñïèñîê, î÷èùàåòñÿ ïðè êàæäîì âûâîäå ñïèñêà get_list();
	string filename;									// îñíîâíîé, êóäà áóäåò ñîõðàíÿòüñÿ
	string bufname = "temp.txt";						// áóôåðíûé ôàéë
public:
	FileIO(string filename);						    // êîíñòðóêòîð ñ ïàðàìåòðàìè
	int load(LinkedList<T>& list);						// çàãðóçêà â ñïèñêà ôàéë	  (âîçâðàùàåò ÷èñëî óñïåøíûõ çàãðóçîê)
	int unload();										// âûãðóçêà èç ôàéëà â ñïèñîê (âîçâðàùàåò ÷èñëî óñïåøíûõ çàãðóçîê)
	LinkedList<T> give_list();							// âåðíóòü ñïèñîê
	void del_less_than(T obj);							// óäàëåíèå çàïèñåé ìåíüøå çàäàííîãî
	void decrease_records(T L);						    // óìåíüøåíèå âñåõ çàïèñåé íà L
	void add_records(int number, int k);				// äîáàâëåíèå k çàïèñåé ïåðåä çàäàííûì íîìåð n
};


template <typename T>
FileIO<T>::FileIO(string filename) : filename(filename) {}

template <typename T>
int FileIO<T>::load(LinkedList<T>& list)
{
	fstream stream(filename, ios::out);
	if (!stream) return -1;
	auto it = list.first();
	auto count = 0;
	for (; it != list.last(); it++)
	{
		stream << *it << "\n";
		count++;
	}
	stream.close();
	return count;
}

template <typename T>
int FileIO<T>::unload()
{
	fstream stream(filename, ios::in);
	if (!stream) return -1;
	auto count = 0;
	T k;
	stream >> k;
	while (!stream.eof())
	{
		count++;
		list.push(k);
		stream >> k;
	}
	stream.close();
	return count;
}



template <typename T>
LinkedList<T> FileIO<T>::give_list()
{
	LinkedList<T> temp = list;
	auto sizel = list.give_size();
	for (int i = 0; i < sizel; i++)
	{
		list.pop();
	}
	return temp;
}


template <typename T>
void FileIO<T>::del_less_than(T obj)
{
	fstream in(filename, ios::in);
	fstream out(bufname, ios::out);
	T k;
	in >> k;
	while (!in.eof())
	{
		if (obj <= k)
		{
			out << k << "\n";
		}
		in >> k;
	}
	in.close();
	out.close();
	remove(filename.c_str());
	rename(bufname.c_str(), filename.c_str());
}

template <typename T>
void FileIO<T>::add_records(int number, int k)
{
	fstream in(filename, ios::in);
	fstream out(bufname, ios::out);

	T obj;
	in >> obj;
	int count = 1;
	while (!in.eof())
	{
		out << obj << "\n";
		in >> obj;
		if (count == number)
		{
			cout << "Ââåäèòå " << k << " ýëåìåíòîâ: " << endl;
			T res;
			for (int i = 1; i <= k; i++)
			{
				cin >> res;
				out << res << "\n";
			}
		}
		count++;
	}
	in.close();
	out.close();
	remove(filename.c_str());
	rename(bufname.c_str(), filename.c_str());
}


template <typename T>
void FileIO<T>::decrease_records(T L)
{
	fstream in(filename, ios::in);
	fstream out(bufname, ios::out);
	T k;
	in >> k;

	while (!in.eof())
	{
		out << k - L << "\n";
		in >> k;
	}
	in.close();
	out.close();
	remove(filename.c_str());
	rename(bufname.c_str(), filename.c_str());
}
