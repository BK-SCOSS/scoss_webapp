
#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
int countss = 0;
int result[10];
int temp = 0;
int tmp = 0;
long long kq[10];
int dem=0;
long long res[100];

long long resolve(long long *arr, int n){

    long long result[n/2+1];
    if(n==1){
        long long ress=0;
        for(int i=dem; i<100; i++){
            ress += res[i];
        }
        return ress;
    }
    if(n%2==0){
        int temp = 0;
        for(int i= 0; i<n-1; i=i+2){
            result[temp++] = arr[i]+ arr[i+1];
        }
        n = n/2;
        int maxx = -100000;
        for(int i=0; i<n; i++){
            if(result[i]>maxx) maxx = result[i];
        }
        res[tmp++] = maxx;
        return resolve(result, n);
    }
    else{
        int temp = 0;
        for(int i= 0; i<n-2; i=i+2){
            result[temp++] = arr[i]+ arr[i+1];
        }
        result[temp] = arr[n-1];
        n = n/2+1;
        int maxx = -100000;
        for(int i=0; i<n; i++){
            if(result[i]>maxx) maxx = result[i];
        }
        res[tmp++] = maxx;
        return resolve(result, n);
    }
}

void input()
{
    cin>>t;
    for(int m=0; m<t; m++)
    {
        int maxx = -100000;
        int counts = 1;
        cin>>n;
        long long a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        long long resultss = resolve(a, n);
        dem++;
        kq[countss++] = resultss;
    }
    for(int i=0; i<10; i++){
        if(kq[i]!=0){
            cout<<kq[i]<<endl;
        }
    }

}


int main()
{
    input();
    return 0;
}
