#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c, x, x1, x2, delta;
	
printf("Nhap a : ");
 scanf("%f",&a);
printf("Nhap b: ");
 scanf("%f",&b);
  printf("Nhap c: ");
scanf("%f",&c);

if(a == 0) {
	
        if(b == 0) {
            if (c == 0) {
              printf("Phuong trinh vo so nghiem");
            } else {
                printf("Phuong trinh vo nghiem");
            }
        }
         else {
            printf("Phuong trinh co nghiem duy nhat: x=%f", x=-c/b);
        }
    }
	else{
		
 delta=b*b-4*a*c;
if(delta<0){
	printf("Phuoong trinh vo nghiem!");
    }
    else if(delta==0){
        x1 = x2 = -b/(2*a);
        printf("Phuong trinh co nghiem kep x1=x2=%5.2f", x1);
    }
    else{
        delta = sqrt(delta);
        x1 = (-b + delta) / (2*a);
        x2 = (-b - delta) / (2*a);
    printf("Phuong trinh co 2 nghiem phan biet x1=%5.2f x2=%5.2f", x1, x2 );
    }
}
return 0;
}
