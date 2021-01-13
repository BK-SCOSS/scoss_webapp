#include <iostream>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    int* arr  = new int[Q];

    for (int i = 0; i < Q; i ++) {
        int N;
        cin >> N;
        int T = N * ( N + 1 ) * ( N + 2);
        int count = 0;
        for (int k = 1; k < T; k ++ ) {
            if ((T * T) % k == 0) {
                if (T % k != 0) count ++;
            }
        }
        arr[0] = count;
    }

    for (int i = 0; i < Q; i ++) {
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;

}