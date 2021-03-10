#include <iostream>
#include <cmath>
#include <iomanip>
#include "secure_input.h"
using namespace std;

//Метод хорд
float A, B, C, D, Xn;
float epsilon = 0.001;

float myEquation(float value)
{
    float answer;
    answer = A * pow(value, 3) + B * pow(value, 2) + C * value + D;
    return answer;
}

float myDerivative1(float value)
{
    float answer;
    answer = 3 * A * pow(value, 2) + 2 * B * value + C;
    return answer;
}

float myDerivative2(float value)
{
    float answer;
    answer = 3 * 2 * A * value + 2 * B;
    return answer;
}

int main()
{
    float left, right, Xn;
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

    if((myEquation(left) * myDerivative2(left)) < 0.0)
    {
        cout << "Start point is left\n";
        Xn = left;
        while(abs(myEquation(Xn)) > epsilon)
        {
            cout << setw(9) << Xn << " : " << setw(9) << abs(myEquation(Xn)) << '\n';
            Xn = Xn - ((myEquation(Xn) / (myEquation(right) - (myEquation(Xn))))*(right - Xn));
        }
    }

    if((myEquation(right) * myDerivative2(right)) < 0.0)
    {
        cout << "Start point is right\n";
        Xn = right;
        while(abs(myEquation(Xn)) > epsilon)
        {
            cout << setw(9) << Xn << " : " << setw(9) << abs(myEquation(Xn)) << '\n';
            Xn = Xn - ((myEquation(Xn) / (myEquation(Xn) - (myEquation(left))))*(Xn - left));
        }
    }

    if(((myEquation(left) * myDerivative2(left)) >= 0.0) && ((myEquation(right) * myDerivative2(right)) >= 0.0))
    {
        cout << "Error! There is not answers!\n";
        return(1);
    }

    cout << setw(9) << Xn << " : " << setw(9) << abs(myEquation(Xn)) << '\n';
    cout << "Answer: X = " << Xn << '\n';
    return(0);
}