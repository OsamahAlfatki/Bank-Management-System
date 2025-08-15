#pragma once
#include <iostream>
#include <string>
using namespace std;
class InterfaceComuncation
{
public:
	virtual void SenEmail(string Title, string SubTitle) = 0;
	virtual void SenFax(string Title, string Message) = 0;
	virtual void SenSMS(string Title, string Message) = 0;
};

