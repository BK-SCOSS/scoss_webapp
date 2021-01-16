#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T ;
    cin >> T;

    while(T>0) {
        int n;
        cin >> n;
        long long data[n];
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        int result = -1;
        vector<bool> indexes(n,false);


        for (int i = 0; i < n-1; i++) {
            if (indexes[i]) {
                continue;
            }
            indexes[i] = true;
            int start = data[i];
            int value = 1;
            for (int j =i+1 ; j < n; j++) {
                if (data[j] - start == 1) {
                    indexes[j] = true;
                    value ++;
                    start = data[j];
                }
            }
            if (value > result) {
                result = value;
            }
        }

        cout << result << endl;

        T--;
    }
    return 0;
}
