//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>

using namespace std;

unsigned long long a, b;
int T;

void add(unsigned long long a, unsigned long long b){
    unsigned long long remainderA = a%10;
    unsigned long long remainderB = b%10;
    unsigned long long a1 = (a-remainderA)/10;
    unsigned long long b1 = (b-remainderB)/10;
    unsigned long long lastdigit = (remainderA+remainderB)%10;
    unsigned long long mem = (remainderA+remainderB-lastdigit)/10;
    mem = a1+b1+mem;
    if (mem>0) {
        cout<<mem;
    }
    cout<<lastdigit<<"\n";
}

int main(){
    cin>>T;
    for (int i=0; i<T; ++i) {
        cin>>a>>b;
        add(a, b);
    }
    return 0;
}
