#include "String.h"
#include <Windows.h>
#include <iostream>
#include <cstring>
using namespace std;

String::String() : string{ nullptr } {}

String::String(const char* ustring)
{
	string = new char[strlen(ustring) + 1];
	strcpy_s(this->string, strlen(ustring) + 1, ustring);
}

void String::getLenght()
{
	int count;
	for (int i = 0; i < strlen(string); i++) { count = i; }
	cout << count << endl;
};

void String::setString(const char* ustring)
{
	delete[]string;
	string = new char[strlen(ustring) + 1];
	strcpy_s(string, strlen(ustring) + 1, ustring);
}

const char String::getString() const
{
	return* string;
}


String String::operator=(const String& str)
{
	string = new char[strlen(str.string) + 1];
	strcpy_s(string, strlen(str.string) + 1, str.string);
	return String(string);
}

bool String::operator==(const String& str) const
{
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] != str.string[i]) { return false; }
	}
	return true;
}

bool String::operator!=(const String& str) const
{
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == str.string[i]) { return false; }
	}
	return true;
}

bool String::operator>(const String& str) const
{ 
	return strcmp(string, str.string) > 0;
}

bool String::operator<(const String& str) const
{
	return strcmp(string, str.string) < 0;
}

bool String::operator>=(const String& str) const
{
	return strcmp(string, str.string) >= 0;
}

bool String::operator<=(const String& str) const
{
	return strcmp(string, str.string) <= 0;
}

String String::operator!()
{
	char* temp_string = new char[strlen(string) + 1];
	for(int i = 0; i < strlen(string); i++)
	{
		if(isupper(string[i]))
		{
			temp_string[i] = tolower(string[i]);
		}
		else if(islower(string[i]))
		{
			temp_string[i] = toupper(string[i]);
		}
		else
		{
			temp_string[i] = string[i];
		}
	}
	temp_string[strlen(string)] = '\0';
	return String(temp_string);
}

char& String::operator[](int id) const
{
	return string[id];
}

int String::operator()(const char* str) const
{
	char* found = strstr(string, str);
	if (found)return found - string;
	return -1;
}

void String::Print() const
{
	cout << string << endl;
}

String::~String()
{
	delete[]string;
}

String operator+(const String& str_1, const String& str_2)
{
	size_t size = strlen(str_1.string) + strlen(str_2.string) + 1;
	char* strCpy = new char[size];

	strcpy_s(strCpy, size, str_1.string);
	strcat_s(strCpy, size, str_2.string);

	return String(strCpy);
}

String operator-(const String& str_1, const String& str_2)
{
	char* result = new char[strlen(str_1.string) + 1];
	int count = 0;

	for (int i = 0; i < strlen(str_1.string); i++) {
		if (strchr(str_2.string, str_1.string[i]) == nullptr) {
			result[count++] = str_1.string[i];
		}
	}
	result[count] = '\0';

	return String(result);
}

String operator/(const String& str_1, int count)
{
	char* result = new char[(strlen(str_1.string) * count) + 1];
	for(int i = 0; i < count; i++)
	{
		strcpy_s(result + i * strlen(str_1.string), strlen(result) + 1, str_1.string);
	}
	return String(result);
}

ostream& operator<<(ostream& out, const String& str)
{
	out << str.string << endl;
	return out;
}

istream& operator>>(istream& in, String& str)
{
	in >> str.string;
	return in;
}



	