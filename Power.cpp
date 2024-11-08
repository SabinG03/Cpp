#include <iostream>
using namespace std;

/*

        Pow Funtion
    * if y = 0 gives 1 because any number to power 0 = 1
    * (Recursive) Loop 
       * If y is even returns t * t   ==>  ( x ^ (y/2)^2)
       * eles it multiplies x * t * t   == > x * ( x ^ (y/2)^2)
    
        Main Function
    * Assigns user values to int x and int y
    * Prints the results

*/

int pow(int x, int y){
    if (y==0)
    return 1;
    int t = pow(x,y/2);
      if(y%2==0)
        return t * t;
    else
        return x * t * t;
}
int main(){
    int x;
    cin >> x;
    int y;
    cin >> y;
    cout << pow(x,y);
}