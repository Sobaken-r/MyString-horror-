#include <Windows.h>
#include <iostream>
#include "String.h"
#include <cstring>
using namespace std;

int main()
{
    setlocale(0, "");
    
    String test1;
    test1.setString("Hello,");
    String test2;
    test2.setString("world!s");

    String test3 = test1 + test2;
    test3.Print();
    test1.getLenght();

    String test4 = test1 - test2;
    test4.Print();

    String test5 = test1 / 2;
    test5.Print();

    String test6;
    test6 = test1;
    test6.Print();
    
    String str1("apple");
    String str2("banana");

    cout << (str1 > str2) << endl;
    cout << (str2 > str1) << endl;

    String str3 = !str2;
    str3.Print();

    cout << str3[2];

    cout << test1;

}
