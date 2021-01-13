#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long 

ll testcase, N;

int Arr[7];

ll hust, soict, count_total;
bool Done_value[15];

void TRY(int k){
    //cout << hust << " " << soict << "Done" << k << endl;
    for(int value = 0; value <= 9; value++){

        if (Done_value[value])
        continue;
        
        ll backup_hust = hust;
        ll backup_soict = soict;
        if (k == 1){
            if (value == 0)
            continue;
            hust += value * 1000;
        }
        if (k == 2){
            hust += value * 100;
        }
        if (k == 3){
            if (value == 0)
            continue;
            hust += value * 10;
            soict += value * 10000;
        }
        if (k == 4){
            hust += value * 1;
            soict += value * 1;
        }
        if (k == 5){
            soict += value * 1000;
        }
        if (k == 6){
            soict += value * 100;

        }
        if (k == 7){
            soict += value * 10;
        }

        Done_value[value] = true;

        if (k == 7){
            if (hust + soict == N){
                //cout << hust << " " << soict << endl;
                count_total++;
            }
        }
        else{
            //cout << hust << endl;
            TRY(k+1);
        }
        Done_value[value] = false;
        hust = backup_hust;
        soict = backup_soict;

    }
}



int main(){

    cin >> testcase;
    while(testcase--){
        cin >> N;
        count_total = 0;
        memset(Done_value, false, 15*sizeof(Done_value[0]));
        hust = 0;
        soict = 0;
        TRY(1);
        cout << count_total << endl;
    }


}