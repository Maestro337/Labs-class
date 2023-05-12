#include "Dialog.h"

//êîíñòðóêòîð 
Dialog::Dialog(void) :Vector()
{
	EndState = 0;
}
//äåñòðóêòîð 
Dialog::~Dialog(void)
{
}
//ïîëó÷åíèå ñîáûòèÿ
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-mszq"; //ñòðîêà ñîäåðæèò êîäû îïåðàöèé 
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s; code = s[0];//ïåðâûé ñèìâîë êîìàíäû 
	if (OpInt.find(code) >= 0)//ÿâëÿåòñÿ ëè ñèìâîë êîäîì îïåðàöèè
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmGet; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 'q': event.command = cmQuit; break;
		}

		//âûäåëÿåì ïàðàìåòðû êîìàíäû, åñëè îíè åñòü 
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());//ïðåîáðàçóåì ïàðìåòð â ÷èñëî 
			event.a = A;//çàïèñûâàåì â ñîîáùåíèå
		}
	}
	else event.what = evNothing;//ïóñòîå ñîáûòèå
}

int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //ïîëó÷èòü ñîáûòèå 
		HandleEvent(event); //îáðàáîòàòü ñîáûòèå

	} while (!Valid()); return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0) return 0; else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;//ïóñòîå ñîáûòèå
}

void Dialog::EndExec()
{
	EndState = 1;
}
//îáðàáîò÷èê ñîáûòèé
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://ñîçäàíèå ãðóïïû 
			size = event.a; //ðàçìåð ãðóïïû
			beg = new Object * [size];//âûäåëÿåì ïàìÿòü ïîä ìàññèâ óêàçàòåëåé
			cur = 0; //òåêóùàÿ ïîçèöèÿ
			ClearEvent(event);//î÷èùàåì ñîáûòèå
			break;
		case cmAdd://äîáàâëåíèå
			Add();
			ClearEvent(event);
			break;
		case cmDel:Del(); //óäàëåíèå 
			ClearEvent(event); break;
		case cmShow:Show(); //ïðîñìîòð 
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec(); //âûõîä 
			ClearEvent(event);
			break;
		case cmGet:
			AvgAge();
			ClearEvent(event);
			break;
		default:
			ClearEvent(event);
			HandleEvent(event);
		};
	};
}