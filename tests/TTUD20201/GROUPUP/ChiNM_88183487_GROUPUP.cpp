//
//  main.cpp
//  THUATTOANUNGDUNG_CUOIKI
//
//  Created by Matt on 1/16/21.
//

#include <iostream>
using namespace std;

int N;
int n[10];
long results[10];

int main(){
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> n[i];
        int a[n[i]];
        for (int j = 0; j < n[i]; j++) {
            cin >> a[j];
        }
        
        long current = 0;
        int num_groups = n[i];

        while (num_groups > 1) {
            long currentMax = 0;
            int old_num_groups = num_groups;

            int count = 0;
            for (int j = 0; j < old_num_groups - 1 ; j+= 2) {
                a[count] = a[j] + a[j+1];
                if(a[count] > currentMax){
                    currentMax = a[count];
                }
                count ++;
            }
            
            if(old_num_groups % 2 == 1){
                a[count] = a[old_num_groups-1];
                if(a[count] > currentMax){
                    currentMax = a[count];
                }
                num_groups = count + 1;
            }
            else{
                num_groups = count;
            }
            current += currentMax;
        }
        
        results[i] = current;
    }
    
    for (int i = 0; i < N; i++) {
        cout << results[i] << endl;
    }
    
    return 0;
}
