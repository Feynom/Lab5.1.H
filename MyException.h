#pragma once
#include <iostream>

using namespace std;

class MyException
{
	string message;
public:
	MyException(string msg) : message(msg) {}
	string what();
};

