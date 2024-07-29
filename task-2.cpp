#include <iostream>
using namespace std;
int main()
{
    double num1, num2;
    char operation;
    double result;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation between them(+, -, *, /): ";
    cin >> operation;

    switch(operation) 
    {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0) 
            {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else 
            {
                cout <<"Division by zero is not possible" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
    }

    return 0;
}
