#include <iostream>
using namespace std;

int coef[] = {10010, 1000, 1000, 100, 100, 10, 2};
char alpha[] = {'S', 'H', 'O', 'I', 'U', 'C', 'T'};
int passed[10];
int counter = 0;

void TRY(int i, int remain){
    if(i == 7){
        if(remain == 0) counter++;
        return;
    }
    
    for(int k=0;k<=9;k++){
        if(passed[k] == 1) continue;
        if((i == 1 || i == 0) && k == 0) continue;
        int new_remain = remain - coef[i]*k;
        if(new_remain < 0) continue;
        passed[k] = 1;
        TRY(i+1, new_remain);
        passed[k] = 0;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        TRY(0, num);
        cout << counter << "\n";
        counter = 0;
    }



    return 0;
}