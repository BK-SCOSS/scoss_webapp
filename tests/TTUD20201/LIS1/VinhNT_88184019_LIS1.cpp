#include <iostream>
#include <vector>
#define MAX_N 100001
using namespace std;

int main(){
    int n;
    cin >> n;
    int cases;
    for(int i=0;i<n;i++){
        cin >> cases;
        int arr[MAX_N];
        vector<pair<int, int>> newest;
        for(int j=0;j<cases;j++){
            cin >> arr[j];
        }
        int longest_seq = 1;
        for(int j=0;j<cases;j++){
            bool not_change = true;
            for(int k=0;k<newest.size();k++){
                if(arr[j] - newest[k].first == 1){
                    not_change = false;
                    newest[k].first = arr[j];
                    newest[k].second++;
                    if(longest_seq < newest[k].second) longest_seq = newest[k].second;
                    break;
                }
            }

            if(not_change) newest.push_back({arr[j],1});
        }
        
        cout << longest_seq << endl;
    }
}