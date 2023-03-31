#include <stdio.h>
#include <stdlib.h>
int gcd(int x1, int x2);
int fact(int x);
void TOH(char, char, char, int);
int fibonacci(int);
int main()
{
	int x, x1, x2;
	int choice;
	int factorial;
	int gcdof;
	int fibo;
	int num,j;


	while (1)
	{
		printf("\n1.Greatest Common Divisior\n2.Factorial\n3.Fibonacci Sequence\n4.Tower of hanoi\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("Enter two numbers:");
			scanf("%d%d", &x1, &x2);
			gcdof = gcd(x1, x2);
			printf("The gcd is:%d", gcdof);
			break;
		case 2:
			printf("enter number:");
			scanf("%d", &x);
			factorial = fact(x);
			printf("The factorial is %d", factorial);
			break;
		case 3:
			printf("Enter number:");
			scanf("%d",&num);
			for(j=0;j<num;j++){
			fibo=fibonacci(j);
			printf(" %d  ",fibo);
			}
			break;
		case 4:
            printf("Enter the number of plates :");
            scanf("%d",&num);
			TOH('S', 'T','A',num);
            break;
		case 5:
			exit(0);
		default:
			printf("\n");
		}
	}
	return 0;
}
int fact(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return fact(n - 1) * n;
	}
}

int gcd(int x1, int x2)
{
	if (x2 != 0)
	{
		return gcd(x2, x1 % x2);
	}
	else
	{
		return x1;
	}
}
void TOH(char s, char t, char a,int n)
{
	if (n == 1)
	{
		printf("\nMove %d disc from peg %c to peg %c", n, s, t);
	}
	else
	{
		TOH(s, a, t, n - 1);
		printf("\nMove %d disc from peg %c to peg %c ", n, s, t);
		TOH(a, t, s, n - 1);
	}
}
int fibonacci(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
	 	return 1;
	}
	else if (n>=2)
	{
	 	return fibonacci(n-1)+fibonacci(n-2);
	}
}