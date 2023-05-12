#pragma once
#include "Vector.h"
using namespace std;

class Dialog :
	public Vector
{
public:
	Dialog(void);//êîíòðóêòîð public:
	virtual ~Dialog(void);//äåñòðóêòîð
	virtual void GetEvent(TEvent& event);//ïîëó÷èòü ñîáûòèå 
	virtual int Execute();//ãëàâíûé öèêë îáðàáîòêè ñîáûòèé 
	virtual void HandleEvent(TEvent& event); //îáðàáîò÷èê
	virtual void ClearEvent(TEvent& event);//î÷èñòèòü ñîáûòèå 
	int Valid();//ïðîâåðêà àòðèáóòà EndState
	void EndExec();//îáðàáîòêà ñîáûòèÿ «êîíåö ðàáîòû» 
protected:
	int EndState;
};