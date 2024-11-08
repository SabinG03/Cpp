#include <iostream>

/*

    * Reads num user input
    * While loop to get last digit of num
    * The digit is put into rev and moved left
    * Once loop while loop is done print value of rev
*/

int main(){
    int num, rev =0 , x;

    scanf("%d", &num);
    while(num != 0){
        x = num%10;
        rev = (rev * 10) + x;
        num = num/10;
    }
    printf("%d",rev);
    return 0;
}