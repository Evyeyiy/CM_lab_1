#pragma once
#include <iostream>
using namespace std;

/*
  a - переменная, в которую необходимо поместить значение
	msg - сообщение, которое будет выведено перед вводом
	использует r-value, чтобы обобщить функцию
*/

//Защищённый ввод с условием, что вводимое значение должно быть больше 0
template<typename T>
void secure_input_greater_than_zero(T &a, string&& msg="")
{
    cout << msg;
    while (!(cin >> a) || (cin.peek() != '\n') || (a <= 0))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1B[31mError\x1B[0m, try again: " << msg << endl;
    }
}
//Защищённый ввод без дополнительных условий
template<typename T>
void secure_input(T &a, string&& msg="")
{
    cout << msg;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1B[31mError\x1B[0m, try again: " << msg << endl;
    }
}

