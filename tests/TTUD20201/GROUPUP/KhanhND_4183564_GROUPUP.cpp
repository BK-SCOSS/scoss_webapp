#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int t;
int timing = 0;
int temp;
int temp2;
vector<int> A;
int maximum;

void cal(vector<int> in,vector<int>& out){
    out.clear();
    maximum = 0;
    int size = in.size();
    if (size % 2 == 0){
        for (int i = 0; i < size; i+=2 ){
            temp = in[i] + in[i+1];
            out.push_back(temp);
            if (temp > maximum){
                maximum = temp;
            }
        }
        timing += maximum;

    }
    else {
        for (int i = 0; i < size-1; i+=2){
            temp = in[i] + in [i+1];
            out.push_back(temp);
            if( temp > maximum){
                maximum = temp;
            }
        }
        temp = in[size-1];
        A.push_back(temp);
        if (temp>maximum){
            maximum = temp;
        }
        timing += maximum;
    }
}


void input(){
    cin  >> t;
    for (int i = 0; i < t; i++){
        cin  >> n;
        timing = 0;
        for (int j = 0; j < n; j ++){
            cin >> temp2;
            A.push_back(temp2);
        }
        while (A.size()!=1){
            cal(A,A);
        }
        cout << timing << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    input();
}
