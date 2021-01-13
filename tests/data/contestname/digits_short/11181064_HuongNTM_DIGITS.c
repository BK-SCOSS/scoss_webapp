#include<stdio.h>
#include<conio.h>

int Fact(int n){
	if (n == 0) return 1;
	else return n*Fact(n-1);
} 
