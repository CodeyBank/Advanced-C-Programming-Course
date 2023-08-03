#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long decimal_to_binary(int dec);
int binary_to_decimal(long long number);
int main()
{

    /*
        Program to check the input from a user to see if the nth bit is set or not
    */

    // Ask for the number and save
/*
    printf("Enter a number:\n");
    int num;
    scanf("%d", &num);

    //Ask for the nth bit
    printf("Enter the nth bit to check and set (0-31):\n");
    int nth_element;
    scanf("%d", &nth_element);

    // Check bit
    int MASK = num >> nth_element;
    printf("The value at the %d th position is %d",nth_element, (1 & MASK));
*/

    long long n, result2;
    int n2;
    int result;

    printf("Enter a binary number: ");
    scanf("%I64d", &n);

    result = binary_to_decimal(n);
    printf("%I64d in binaary is %d in decimal \r\n", n,result);


    printf("Enter a decimal number: ");
    scanf("%d", &n2);


    result2 = decimal_to_binary(n2);
    printf("Decimal number %d = Binary number is %I64d \n\r",n2,result2);

    return 0;
}


int binary_to_decimal(long long n)
{

    int decimalNumber = 0, i=0, remainder=0;

    while(n!=0){
        remainder = n%10;
        n /=10;
        decimalNumber += remainder*pow(2,i);
        i++;
    }
    return decimalNumber;

}

long long decimal_to_binary(int dec)
{

    long long result=0;
    int remainder=0, i=1;
    while (dec!=0)
    {
        remainder = dec%2;
        dec = dec/2;
        result += remainder * i;
        i *=10;

    }

    return result;
}































