#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() 
{
    // Initialize random number
    srand(time(0));
    // Generates random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int guess = 0;
    cout<<"Guess the number between 1 and 100 : ";
    // Loop until the user guesses the correct number
    while (guess!=randomNumber) 
    {
        cin >> guess;
        if (guess>randomNumber)
        {
            cout << "Too high! Try again: ";
        } 
        else if (guess<randomNumber) 
        {
            cout << "Too low! Try again: ";
        } 
        else 
        {
            cout << "Congratulations! You guessed the right number." <<endl;
        }
    }

    return 0;
}

