#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int n;

long long A[MAX];
void run(int a){
    unsigned long long count=0;
    int arr[7];
   
    for(arr[0]=0; arr[0]<10; arr[0]++){
        for(arr[1]=0; arr[1]<10; arr[1]++){
            for(arr[2]=0; arr[2] <10; arr[2]++){
                for(arr[3]=0; arr[3]<10; arr[3]++){
                    for(arr[4]=0; arr[4] <10; arr[4]++){
                        for(arr[5]=0;arr[5]<10; arr[5]++){
                            for(arr[6]=0; arr[6]<10; arr[6]++){
                                if((arr[0]*1000+arr[1]*100+arr[2]*10010+arr[3]*1000+arr[4]*2+arr[5]*100+arr[6]*10)==a){
                                    bool c = true;
                                    for(int i=0; i < 7; ++i){
                                        for(int j= i+1; j < 7; ++j){
                                            if((arr[i]==arr[j])){
                                                c = false;
                                            }
                                        }
                                    }
                                    if(arr[0]==0 || arr[2]==0){
                                        c= false;
                                    }
                                    if (c == true){
                                         count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;
}
int main() {
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>A[i];
    }
    for (int i = 0; i < n; ++i){
        run(A[i]);
    }
}