#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int brr[],int l,int h){
	int x=arr[h];
	int i=l-1;
	for(int j=l; j<=h-1; j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]);
				swap(&brr[i],&brr[j]);
		}
	}
	swap(&arr[i+1],&arr[h]);
		swap(&brr[i+1],&brr[h]);
	return(i+1);
}
void quicksort(int arr[],int brr[],int l,int h){
	if(l<h){
		int p=partition(arr,brr,l,h);
		quicksort(arr,brr,l,p-1);
		quicksort(arr,brr,p+1,h);
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int day[1000000];
	int price[1000000];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		day[i]=a+b;
		cin>>price[i];
		}
		long sum=0;
		quicksort(day,price,0,n-1);
		for(int i=0;i<n-1;i++)
		{
			if((day[i+1]-day[i])<k){
				if(price[i+1]>price[i]) sum=sum+price[i+1];
				else sum=sum+price[i];
			}
		
		}

cout<<sum;
	
	
	return 0;
	}
