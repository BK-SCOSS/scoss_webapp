#include <iostream>

using namespace std;

int main(){
    int testcase;
    cin>> testcase;
    int result[1000];
    for(int i=0; i<testcase; i++){
        int line1, line2;
        cin>> line1;
        int ele1[1000];
        for(int i=0; i<line1; i++){
            cin>> ele1[i];
        }
        cin>> line2;
        int ele2[1000];
        for(int i=0; i<line2; i++){
            cin>> ele2[i];
        }
        int count1=0;
        for(int i=0; i<line1; i++){
            for(int j=0; j<line2; j++)
                if(ele1[i]==ele2[j])
                    count1++;
        }
        result[i]=count1;
    }

    for(int i=0; i<testcase; i++){
        if(i<testcase-1)
            cout<<result[i]<<endl;
        else
            cout<<result[i];
    }


    return 0;
}
