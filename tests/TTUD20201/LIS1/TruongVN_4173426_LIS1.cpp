
#include <iostream>

using namespace std;

int maxLen=0;
int result[1000];

int main(){

    int testcase;
    cin>> testcase;

    for(int a=0; a<testcase; a++){

        int number;
        cin>>number;
        int element[1000];
        for(int i=0; i<number; i++){
            cin>> element[i];
        }

        //xet day con
        for(int i=0; i<number; i++){
            int currentValue=element[i];

            int currentMax=1;
            for(int j=i; j<number; j++){
                if(element[j]==(currentValue+1)){
                    currentValue=element[j];
                    currentMax++;
                }

            }
            if(currentMax>maxLen){
                maxLen=currentMax;

            }
        }
        result[a]=maxLen;
    }

    for(int i=0; i<testcase; i++){
        if(i<testcase-1)
            cout<<result[i]<<endl;
        else
            cout<<result[i];
    }



    return 0;
}
