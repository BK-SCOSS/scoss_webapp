#include <vector>
#include <iostream>
#include<fstream>
#include <string>
#include<limits>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;


vector<string> split_string(string);

/*
 * Complete the simpleArraySum function below.
 */

int main()
{
    int ar_count;
    cin >> ar_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (ar_count > 10)
    {
        return 0;
    }

    for (int i= 0 ; i< ar_count; i++)
    {
        string ar_temp_temp;
        getline(cin, ar_temp_temp);
        
        vector<string> ar_temp = split_string(ar_temp_temp);

        vector<int> ar(2);

        for (int ar_itr = 0; ar_itr < 2 ; ar_itr++) {
            int ar_item = stoi(ar_temp[ar_itr]);

            ar[ar_itr] = ar_item;
        }
        for (int i = 0 ; i < 2; i++)
        {
            if (ar[i] < 0 || ar[i] > 10e18 )
            return 0;
        }
        int sum = 0;
        for(int i : ar)
        {
            sum += i;
        }
        cout << sum << endl ;
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}