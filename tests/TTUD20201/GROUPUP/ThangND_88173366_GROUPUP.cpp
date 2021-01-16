#include <iostream>

using namespace std;

const int TMAX = 11, NMAX = 1e5;
int a[TMAX][NMAX];
int T;
int res[TMAX];
int n[TMAX];

void input(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n[t];
        for(int j=0; j<n[t]; j++){
            cin >> a[t][j];
        }
    }
}

void Try(int arr[], int arrLen, int t){
    int maxTime = 0;
    int len = (arrLen%2 == 0)?(arrLen/2):(arrLen/2+1);
    int newArr[len];
    for(int k=0; k<len; k++){
        newArr[k] = 0;
    }
    int index = 0;

    int maxI = (arrLen%2 == 0)?(arrLen-1):(arrLen-2);
    for(int i=0; i<maxI; i = i+2){
        int sum = arr[i]+arr[i+1];
        maxTime = (maxTime > sum)?maxTime:sum;
        newArr[index] = sum;
        index++;
    }
    if(newArr[len-1] == 0){
        newArr[len-1] = arr[arrLen-1];
    }
    res[t] += maxTime;
    if(len == 1){
        return;
    }
    Try(newArr, len, t);
}

int main()
{
    input();
    for(int t=0; t<T; t++){
        Try(a[t], n[t], t);
    }
    for(int t=0; t<T; t++){
        cout << res[t] << endl;
    }
    return 0;
}
