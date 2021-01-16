#include <iostream>
#define MAX 100000
using namespace std;

int a[MAX];
int n;
int index;
int test;
int time_max=0;
int _time=0;

int getmax(int a, int b){
    return (a>b)? a:b;
}

void input(int *a,int n){
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

int solve(int *a, int n){
    while(n>1){
        index=0;
        for(int i=0; i<n; i++){

            a[index]=a[i]+a[i+1];
            index++;
            i++;
            n--;
        }
        for(int i=0; i<index; i++){
            time_max = getmax(time_max, a[i]);
        }
        _time += time_max;
    }
    return _time;
}

int main()
{
    cin >> test;
    while(test >0){
        cin >> n;
        input(a, n);
        cout << solve(a,n);
        test--;
    }
    return 0;
}
