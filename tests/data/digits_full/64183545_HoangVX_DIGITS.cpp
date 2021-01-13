#include <iostream>
using namespace std;
int status[10];
int N;
int arr[7];
int count_s = 0;
int calculate(){
    return arr[0]*1000+arr[1]*100+arr[2]*10+arr[3]+arr[2]*10000+arr[4]*1000+arr[5]*100+arr[6]*10+arr[3];
}
void Try(int k){
        for(int i=0;i<10;i++){
            if(status[i]==0){
                status[i] = 1;
                arr[k] = i;
                if(k==6){
                    if(calculate()==N&&arr[0]!=0&&arr[2]!=0){
                        count_s+=1;
                    }
                }else{
                    Try(k+1);
                }
                status[i] = 0;
            }
        }
}
int main(){
    int T;
    cin>> T;
    for(int i=0;i<10;i++){
        status[i] = 0;
    }
    while(T>0){
        cin>> N;
        count_s = 0;
        Try(0);
        cout<< count_s<< endl;
        T--;
    }
}
