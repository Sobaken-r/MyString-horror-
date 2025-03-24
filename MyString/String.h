#pragma once
#include <cstring>
#include <Windows.h>
#include <iostream>
using namespace std;

class String
{
	char* string;
public:
	String();
	String(const char* string);

	void getLenght();

	void setString(const char* string);

	const char getString() const;

	friend String operator+(const String& str_1, const String& str_2);
	friend String operator-(const String& str_1, const String& str_2);
	friend String operator/(const String& str_1, int count);
	String operator=(const String& str);
	bool operator==(const String& str) const;
	bool operator!=(const String& str) const;
	bool operator>(const String& str) const;
	bool operator<(const String& str) const;
	bool operator>=(const String& str) const;
	bool operator<=(const String& str) const;
	String operator!();
	char& operator[](int id) const;
	int operator()(const char* str) const;

	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);

	void Print() const;
	~String();
};

