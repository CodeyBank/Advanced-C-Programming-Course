#include <stdio.h>
#include <stdlib.h>

int sumup(int n);
extern char * reverse(char * str);

int gcd(int n1, int n2){
   while(n1 != n2) {
      if (n1 > n2)
        return gcd(n1-n2, n2);
      else
        return gcd(n1, n2-n1);
   }

   return n1;
}

int main()
{
    int num;
    printf("Enter the final number: ");
    scanf("%d",&num);

    int sum = sumup(num);
    printf("the sum of [1 : %d] is %d", num, sum);

    int num1 = 0,num2 = 0,res = 0;

    printf("\n\n Recursion : Find GCD of two numbers :\n");
    printf("------------------------------------------\n");

    printf(" Input 1st number: ");
    scanf("%d",&num1);

    printf(" Input 2nd number: ");
    scanf("%d",&num2);

    res = gcd(num1, num2);
    printf("\n The GCD of %d and %d is: %d\n\n",num1,num2,res);

    char str[100];
    char *rev = NULL;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("The original string is: %s\n", str);

    rev = reverse(str);

    printf("The reversed string is: %s\n", rev);

    return 0;
}

int sumup(int n){
    if (n==1) return 1;
    return n + sumup(n-1);
}
