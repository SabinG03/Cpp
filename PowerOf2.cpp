#include <iostream>
using namespace std;


/*
        Check Function
    * if x = 0 return false , 0 isnt a power of 2    
    * Keeps looping if x is even ( mod 2 ) and dividing by 2 
    * Once x is equal to 1 it means that it was a power of 2
      and returns true

        Main Function
    * Puts user input to int x
    * Sees check function if x is true or false

*/

bool check(int x) {

    if (x == 0)
        return false;
        while (x % 2 == 0) {
        x /= 2;
    }
        return x == 1;
}

int main() {
    int x;
    cin >> x;
    if (check(x)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
