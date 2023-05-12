#pragma once
#include <string>
#include <iostream>
using namespace std;
class Error//áàçîâûé êëàññ
{
public:
	virtual void what() {};
};

class IndexError :public Error //îøèáêà â èíäåêñå ñïèñêà
{
protected:
	string msg;
public:
	IndexError() { msg = "Index Error\n"; }
	virtual void what() { cout << msg; }
};
class SizeError :public Error //îøèáêà â ðàçìåðå âåêòîðà
{
protected:
	string msg;
public:
	SizeError() { msg = "size error\n"; }
	virtual void what() { cout << msg; }
};

class EmptySizeError :public SizeError //óäàëåíèå èç ïóñòîãî âåêòîðà
{
protected:
	string msg_;
public:
	EmptySizeError() { SizeError(); msg_ = "Ëèñò ïóñò\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError1 :public IndexError //èíäåêñ ìåíüøå íóëÿ
{
protected:
	string msg_;
public:
	IndexError1() { IndexError(); msg_ = "index <0\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError2 :public IndexError //èíäåêñ áîëüøå òåêóùåãî ðàçìåðà âåêòîðà
{
protected:
	string msg_;
public:
	IndexError2() { IndexError(); msg_ = "index>size\n"; }
	virtual void what() { cout << msg << msg_; }
};
