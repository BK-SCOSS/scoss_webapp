//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>
#include<map>
#include<cmath>

using namespace std;

const int test = 1e5;
int Q;
int N;
map<int, int> factorT[test];//, factorN_1,factorN_2;

void analysFactor(int N, int indexTest){
    
    while (N%2==0) {
        factorT[indexTest][2]++;
        N/=2;
    }
    int sqrtN = sqrt(N);
    for (int i=3;i<=sqrtN;i+=2) {
        while (N%i==0) {
            factorT[indexTest][i]++;
            N/=i;
        }
    }
    if (N!=1) {
        factorT[indexTest][N]++;
    }
}

int countResult(int N, int indexTest){
    analysFactor(N, indexTest); analysFactor(N+1,indexTest) ;analysFactor(N+2,indexTest) ;
    int count1=1, count2=1; // count1: # factor of T^2 smaller than T, count2 : #factor of T
    for (auto factor: factorT[indexTest]){
        count1 *= (2*factor.second+1);
        count2 *= (factor.second+1);
    }
    
    //    factorT.clear();
    return (count1-1)/2-count2+1; // plus 1 because count2 including T
}

int main(){
    cin>>Q;
    for (int i=0; i<Q; ++i) {
        cin>>N;
        cout<<countResult(N,i)<<"\n";
    }
    return 0;
}
