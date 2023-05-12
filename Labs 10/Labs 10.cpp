#include "LinkedList.h"
#include "windows.h"

#define SAVE_VARIBLE_NAME(varible) VARIBLE_NAME = string(#varible) + ".txt";

// Äëÿ ðàáîòû ñ n + Pair;

Pair& operator+(int n, Pair& pair)
{
    return pair + n;
}
Pair& operator+(double n, Pair& pair)
{
    return pair + n;
}

string VARIBLE_NAME = "NULL";               // äëÿ ïîëó÷åíèÿ èìåíè ïåðåìåííîé, âûøå äèðåêòèâà (õç çà÷åì, õî÷ó)

void fun_int()
{
    LinkedList <double> list(3, 1.5);
    SAVE_VARIBLE_NAME(list2);
    FileIO <double> file(VARIBLE_NAME);
    list.push(1.7);
    list.push(2.1);
    list.push(2.5);

    cout << "\n" << VARIBLE_NAME << " çàãðóæàåòñÿ â ôàéë: " << endl;
    cout << list << endl;
    file.load(list);

    cout << "\n" << VARIBLE_NAME << " óìåíüøàåì íà 0.5: " << endl;
    file.decrease_records(0.5);
    if (file.unload() != -1)
        cout << file.give_list();

    cout << "\n" << VARIBLE_NAME << " óäàëÿåì ìåíüøåå 1.6: " << endl;
    file.del_less_than(1.6);
    if (file.unload() != -1)
        cout << file.give_list();

    int n, k;
    cout << "\n" << VARIBLE_NAME << " äîáàâëÿåì ïîñëå n= ýëåìåíòà k=" << endl;
    cin >> n >> k;
    file.add_records(n, k);
    if (file.unload() != -1)
        cout << file.give_list();
}

void fun_Pair()
{
    LinkedList <Pair> list(3, Pair(1, 1));
    SAVE_VARIBLE_NAME(list2);
    FileIO <Pair> file(VARIBLE_NAME);
    list.push(Pair(1, 1.7));
    list.push(Pair(2, 2.1));
    list.push(Pair(3, 2.5));

    cout << "\n" << VARIBLE_NAME << " çàãðóæàåòñÿ â ôàéë: " << endl;
    cout << list << endl;
    file.load(list);

    cout << "\n" << VARIBLE_NAME << " óìåíüøàåì íà Pair(2,0.3) " << endl;
    file.decrease_records(Pair(2, 0.3));
    if (file.unload() != -1)
        cout << file.give_list();

    cout << "\n" << VARIBLE_NAME << " óäàëÿåì ìåíüøåå Pair(1, 0.5) " << endl;
    file.del_less_than(Pair(0, 1.4));
    if (file.unload() != -1)
        cout << file.give_list();

    int n, k;
    cout << "\n" << VARIBLE_NAME << " äîáàâëÿåì ïîñëå n= ýëåìåíòà k=" << endl;
    cin >> n >> k;
    file.add_records(n, k);
    if (file.unload() != -1)
        cout << file.give_list();
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    /*fun_int();*/
    fun_Pair();

    return 0;
}