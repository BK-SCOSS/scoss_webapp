#include <vector>
#include <iostream>
#include<fstream>
#include <string>
#include<limits>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;


int main()
{
    int ar_count;
    cin >> ar_count;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<int> result(ar_count);
    

    for (int i = 0 ; i < ar_count ; i++)
    {    
        string ar_temp_temp;
        getline(cin, ar_temp_temp);
        int N = stoi(ar_temp_temp);
        int T = N * (N+1) * (N+2) ;
        int T2 = T*T;
        vector<int> U_T;
        for (int j = 1; j <= T ; j++)
        {
            if(T%j == 0)
            U_T.push_back(j);
        }
        int count = 0;
        for (int j = 1; j <= T ; j++)
        {
            for(int it: U_T)
            {
                if(j == it)
                continue;
            }
            if (T2 % j == 0)
            {
                count ++;
            }
        }
        result[i] = count;

}
    for (int jt: result)
    {
        cout << "\n" << jt;
    }
    return 0;
}