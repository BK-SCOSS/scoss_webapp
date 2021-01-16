#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main()
{
    int T;
    int result = 0;
    cin >> T;
    for (int i = 0 ; i < T; i++) {
        map<long long, int> indexes ;
        int n;
        cin >>n;
        for (int j = 0 ;j < n; j++) {
            long long a;
            cin >>a;
            indexes[a] = 1;
        }

        int m;
        cin >>m;
        for (int j =0 ; j < m;j++) {
            long long b;
            cin >>b;
            if (indexes.find(b) != indexes.end()) {
                result++;
                indexes.erase(b);
            }
        }
        cout << result << endl;

    }
    return 0;
}
