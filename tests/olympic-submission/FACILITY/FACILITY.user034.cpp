#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int maximum(int a[], int n) 
{  
    int max;
	max=a[0]; 
    for (int i = 1; i < n; i++) 
        if (a[i] > max){
            max = a[i]; 
    	}
    return max; 
} 
int minimum(int a[], int n) 
{  
    int min;
	min=a[0]; 
    for (int i = 1; i < n; i++) 
        if (a[i] < min){
            min = a[i]; 
    	}
    return min; 
} 
void sort(int a[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++){
    	for (j = 0; j < n-i-1; j++){
        	if (a[j] > a[j+1]){
        		int temp;
				temp = a[j];  
   				a[j] = a[j+1];  
  				a[j+1] = temp; 
        	}
    	}
	}
}  
int main(){
	int n,K;
	int *s,*d,*r,*tot,*day;
	int max,min;
	cin>>n>>K;
	s= new int[n];
	d= new int[n];
	r= new int[n];
	tot= new int[n];
	day= new int[n];
	for (int i=0;i<n;i++){
		tot[i]=0; day[i]=0;
	}
	for (int i=0;i<n;i++){
		cin>>s[i]>>d[i]>>r[i];
	}
	sort(s,n);sort(d,n);sort(r,n);
	for (int j=0; j<n; j++){
	while(day[j]<s[n-1]){
		for (int i=0;i<n;i++){
			if (s[i]>day[j]){
				tot[j]+=r[i];
				day[j]=day[j]+d[i]+K;
			}
		}
	}
	}
	cout<<maximum(tot,n);
}







