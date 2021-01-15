#include<stdio.h>
#include<math.h>
#define PI 3.1415926535898
int main()
{// giai pt bac 3	
	float a, b, c, d, delta, k, x1, x2, x3, x0, x, X;
	printf("ax^3 + bx^2 + cx + d = 0\n");
	printf("nhap a, b, c, d:\n");
	scanf("%f\n%f\n%f\n%f", &a, &b, &c, &d);
 	delta = (float)pow(b,2) - 3*a*c;
	k = (float)(9*a*b*c - 2*pow(b,3) - 27*pow(a,2)*d)/ (2*sqrt(abs(pow(delta,3))));
	
	if(delta>0){
		if(abs(k)<=1) {
		x1 = (2*sqrt(delta)*cos((acos(k)/3)) - b)/ (3*a);
		x2 = (2*sqrt(delta)*cos((acos(k)/3 - (2*PI/3))) - b)/(3*a);
		x3 = (2*sqrt(delta)*cos((acos(k)/3 + (2*PI/3))) - b)/(3*a);
		printf("pt co 3 ngiem:\n%.2f\n%.2f\n%.2f", x1, x2, x3);}
		else{
		float x0 = ((sqrt(delta)*abs(k))/(3*a*k))*(pow(abs(k) + sqrt(pow(k,2) - 1),1/3) + pow(abs(k) - sqrt(pow(k,2) - 1),1/3)) - (b/(3*a));
		printf("pt co nghiem duy nhat: %.2f", x0);
		}
		}
	
	
	if(delta=0){
		X = (-b + pow(pow(b,3) - 27*pow(a,2)*d,1/3))/(3*a);
		printf("pt co nghiem boi: %.2f", X);
	}
	if(delta<0){
		x = (sqrt(abs(delta))/(3*a))*(pow(k + sqrt(pow(k,2) + 1),1/3) + pow(k - sqrt(pow(k,2) + 1),1/3)) - (b/(3*a));
		printf("pt co nghiem duy nhat: %.2f", x);
	}
 }
