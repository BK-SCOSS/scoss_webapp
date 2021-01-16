#include <iostream>
#define MAX 100000
using namespace std;

long long a[MAX];
long long perf[MAX];
int n;
int test;
int _max =0;
int index;

int getmax(int a, int b){
    return (a>b)? a:b;
}

void input(long long *a,int n){
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}


int solve(long long *a, int n){
    for(int i =0; i<n; i++){
        index =0;
        int keep =i;
        for(int j =i+1; j<n; j++){
            if((a[i]+1)==a[j]){
                perf[index]=a[j];
                index++;
                i =j;
            }
        }
        i=keep;
        _max = getmax(_max, index+1);
    }
    return _max;
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
