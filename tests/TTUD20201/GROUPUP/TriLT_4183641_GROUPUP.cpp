#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<math.h>
using namespace std;

// typedef struct Node
// {
//     int soNhom;
//     int soNguoi;

// }Node;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int solan = 0; solan < T; solan++)
    {
        int n;
        cin >> n;
        int m = 0;
        while (pow(2,m) < n)
        {
            m++;
        }
        m = pow(2,m);
        int A[m+1];
        for(int i = 1; i <=n;i++){
            cin >> A[i];
        }
        for(int i = n+1; i <= m; i++){
            A[i] = 0;
        }
        int thoigian = 0;
        while (m!=1)
        {
            int max = -1;
            for(int index = 1; index <=m;index+=2){
                A[(index + 1)/2] = A[index] + A[index+1];
                if(A[(index + 1)/2] > max){
                    max = A[(index + 1)/2];
                }
            }

            thoigian += max;


            m/=2;
        }
        cout << thoigian << "\n";
    }
}