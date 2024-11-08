#include <iostream>
using namespace std;

/*
        Check Function
    * Rev gets value of 0
    * X = n to make sure dont modify original value
    * The while loop makes the reversed number 
    * Once rev is made with the while loop it checks if
      rev = n, if it does its a palindrome

        Main Function
    * Call the int n and gives it the user input value for it
    * If n is negative, Return false (Palindrome cant be negative)
    * Sees what it got from the check function for value n and prints 
      true if it was a palindrome, if not print false

*/

bool check(int n)
{
    int rev = 0;
    int x = n;
    while (x != 0) {
        rev = (rev * 10) + (x % 10);
        x = x / 10;
    }
    return (rev == n);
}

int main()
{
    int n;
    cin >> n;
    if (n < 0) {
        cout << "false" << endl;
        return 0;
    }
    if (check(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
