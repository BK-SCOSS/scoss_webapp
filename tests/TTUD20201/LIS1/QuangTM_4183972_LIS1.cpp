#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        int N;
        cin>>N;
        int *input = new int[N];
        vector<int> lis; // lis[i] = the last value in the longest increasing subsequence (lis) of length i
        for(int i = 0; i < N; i++) {
            cin>>input[i];
        }

        // Main algorithm
        lis.push_back(input[0]);
        for(int i = 1; i < N; i++) {
            int upperBoundIndex = (upper_bound(lis.begin(), lis.end(), input[i]) - lis.begin());
            if(upperBoundIndex == lis.size()) {
                // Additional check to deal with the "strictly increasing" condition
                if(input[i] == (lis[lis.size()-1] + 1)) {
                    lis.push_back(input[i]);
                }
            } else {
                if(upperBoundIndex == 0) {
                    lis[upperBoundIndex] = input[i];
                }
                // Additional check to deal with the "strictly increasing" condition
                if(input[i] > lis[upperBoundIndex-1]) {
                    lis[upperBoundIndex] = input[i];
                }
            }
        }
        cout<<lis.size();
    }
    return 0;
}
