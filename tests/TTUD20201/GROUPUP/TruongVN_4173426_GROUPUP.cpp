#include <iostream>
#include <algorithm>
using namespace std;


int teamPeople[1000];
int result[1000];


int func(int teamNumber, int time){
    int run=0;
    //cout<<"go here: "<<teamNumber;

    if(teamNumber==1){
        return time;
    }else{
/*
        for(int i=0; i<teamNumber; i++){
        cout<<teamPeople[i]<<endl;
        }
*/
        int maxTime=0;
//do the work
        for(int i=0; i<teamNumber; i+=2){

            int temp;

            if((i+1)==teamNumber){
                temp= teamPeople[i];
                teamPeople[run]=temp;
                run++;
            }
            else{
                temp= teamPeople[i]+teamPeople[i+1];
                teamPeople[run]=temp;
                run++;
            }
            if(temp>maxTime){
                maxTime=temp;
            }
        }
        time+=maxTime;
        func(run,time);
    }
}

int main(){

    int testcase;
    cin>> testcase;

    for(int i=0; i<testcase; i++){
        int teamNumber;
        cin>> teamNumber;
        for(int i=0; i<teamNumber; i++){
            cin>> teamPeople[i];
        }

        result[i]=func(teamNumber,0);
    }


    for(int i=0; i<testcase; i++){
        if(i<testcase-1)
            cout<<result[i]<<endl;
        else
            cout<<result[i];
    }

    return 0;
}


//tinh truong hop so chan truooc
