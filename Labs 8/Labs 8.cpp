#include "Dialog.h"
#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "ÌÅÍÞØÅ×ÊÀ: " << endl << endl;
	cout << "-----------------------------------" << endl;
	cout << endl << "1. Ñîçäàòü âåêòîð: (m6, ãäå 6-ðàçìåð)\n2. Äîáàâèòü ýëåìåíò: +\n3. Óäàëèòü ýëåìåíò: -\n4. Âûâîä ïîëåé ýëåìåíòîâ: s\n5. Ñðåäíèé âîçðàñò: z\n6. Âûõîä: q\n\n";
	cout << "-----------------------------------" << endl;
	cout << endl;
	Dialog D;
	D.Execute();
	return 0;


}