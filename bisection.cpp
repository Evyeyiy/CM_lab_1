#include <iostream>
#include <cmath>
#include <iomanip>
#include "secure_input.h"
using namespace std;

//Метод бисекции
float A, B, C, D;
float epsilon = 0.001;

float myEquation(float value)
{
    float answer;
    answer = A * pow(value, 3) + B * pow(value, 2) + C * value + D;
    return answer;
}

int main()
{
    float left, right, half, fl, fr, fh;
    cout << "Please, enter A: \n";
    secure_input(A);
    cout << "Please, enter B: \n";
    secure_input(B);
    cout << "Please, enter C: \n";
    secure_input(C);
    cout << "Please, enter D: \n";
    secure_input(D);
    cout << "Please, enter left border: \n";
    secure_input(left);
    cout << "Please, enter right border: \n";
    secure_input(right);
    cout << "Let's solve this problem! \n";
    cout << "Epsilon = " << epsilon << "\n\n";

    while((abs(left - right) - epsilon) > 0.0)
    {
        half = (left + right)/2;
        fl = myEquation(left);
        fr = myEquation(right);
        fh = myEquation(half);

        if ((fl * fh > 0) && (fr * fh > 0))
        {
            cout << "Error! There is not answers!\n";
            return(1);
        }

        
        cout << "[ " << setw(9) << left << " ; " << setw(9) << right << " ]"; 
        cout << "     fa = " << setw(9) << fl << "     fb = " << setw(9) << fr;
        if (fl * fh > 0)
        {
            left = half;
        }
        if (fr * fh > 0)
        {
            right = half;
        }
        cout << "     |a - b| = " << setw(9) << abs(left - right) << '\n';
    }
    cout << "Answer: \n";
    cout << left << " < X < " << right << '\n';
    return(0);
}