#include <stdio.h>
#define SUM(a,b) \
(a)+(b)

#define CUBE(a) \
(a)*(a)*(a)

#define SQUARE(a) \
(a)*(a)

int main(int argc, char **argv)
{
	printf("Line number is %d\n", __LINE__);
	printf("The file name is: %s \n",__FILE__);
	printf("The function name is %s\n", __func__);
	printf("Date of last compilation is %s\n", __DATE__);
	printf("Time of last compilation is %s\n", __TIME__);

	int a=5, b=8;
	printf("The sum of %d and %d is %d \n", a, b, SUM(a, b));

	printf("Enter any number to find the square and cube: ");
	int num;
	scanf("%d",&num);

	printf("SQUARE(%d) = %d\n",num, SQUARE(num));
	printf("CUBE(%d) = %d\n ",num, CUBE(num) );
	return 0;
}
