#include <iostream>
#include <queue>
#define MAX_N 100001
using namespace std;

int find_this_life(int arr[], int length){
    int new_arr[MAX_N];
    int counter = 0;
    int max = 0;
    for(int i=0;i<length-1;i+=2){
        new_arr[counter] = arr[i] + arr[i+1];
        if(new_arr[counter] > max) max = new_arr[counter];
        counter++;
    }

    return max + find_this_life(new_arr, counter);
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int r;
        queue<int> q;
        cin >> r;
        for(int j=0;j<r;j++){
            int temp;
            cin >> temp;
            q.push(temp);
        }
        int total = 0;
        int max_of_this_life = 0;
        int iteration_length[] = {r, 0};
        int iteration = 0;
        while(q.size() > 1){
            int first = q.front();
            q.pop();
            iteration_length[iteration%2]--;
            
            int second = 0;
            if(iteration_length[iteration%2] != 0){
                second = q.front();
                q.pop();
                iteration_length[iteration%2]--;
            }
            int next_value = first + second;

            if(next_value > max_of_this_life) max_of_this_life = next_value;
            q.push(next_value);
            iteration_length[1-iteration%2]++;

            if(iteration_length[iteration%2] == 0){
                iteration++;
                total += max_of_this_life;
                max_of_this_life = 0;
            }
        }

        cout << total << endl;
    }
}