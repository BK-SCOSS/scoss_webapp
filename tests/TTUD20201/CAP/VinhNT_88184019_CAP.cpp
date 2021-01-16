#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAX_ARR 101
using namespace std;

int n;

int main(){
    cin >> n;
    int cases_1;
    int cases_2;
    for(int i=0;i<n;i++){
        set<int> arr_1;
        set<int> arr_2;
        cin >> cases_1;
        for(int j=0;j<cases_1;j++){
            int temp;
            cin >> temp;
            arr_1.insert(temp);
        }
        cin >> cases_2;
        for(int j=0;j<cases_2;j++){
            int temp;
            cin >> temp;
            arr_2.insert(temp);
        }
        //sort(arr_1.begin(),arr_1.end());
        //sort(arr_2.begin(),arr_2.end());
        vector<int> v_intersection;
        set_intersection(arr_1.begin(),arr_1.end(), arr_2.begin(),arr_2.end(), back_inserter(v_intersection));
        cout << v_intersection.size() << endl;
    }
}