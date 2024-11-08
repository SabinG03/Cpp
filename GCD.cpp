/*

    * Gcd must have the x and y inputs
    * If x equals 0 it returns y
    * If y equals 0 it returns y
    * If x and y are equals it returns y
    * Checks if x is greater than y, Takes the x value and 
      subtracts y from it, then returns the new x value and y back
    * If y is greater, it returns the x value and y minus x back

    * Main function takes user input for x and y and prints gcd
      funtion result

*/

#include <iostream>
using namespace std;

int gcd(int x, int y){
    
    if(x==0)
        return y;
    if(y==0)
        return x;
    if(x==y)
        return y;
    if(x > y)
        return gcd(x-y, y);
    else
        return gcd(x , y-x); 
}
int main(){
    int x;
    int y;
    cin >> x;
    cin >> y;
    cout << gcd(x,y);
}