#include <iostream>
#include <queue>

using namespace std;


int main()
{
    int T;
    cin >> T;
    for (int i =0 ; i < T; i++) {
        int n;
        cin >>n;
        queue<long long> q;
        for (int j = 0 ; j < n;j ++) {
            int x;
            cin >> x;
            q.push(x);
        }

        int result = 0;
        while(q.size() >1) {
            int q_size = q.size();
            int loop = q_size /2;
            int remain = q_size % 2;
            int max_value = -1;
            for (int j = 0; j < loop; j++) {
                int current1 = q.front();
                q.pop();
                int current2 = q.front();
                q.pop();
                if (current1 + current2 > max_value) {
                    max_value = current1 + current2;
                }
                q.push(current1+current2);
            }
            if (remain == 1) {
                int current = q.front();
                q.pop();
                q.push(current);
            }
            result += max_value;
        }

        cout << result << endl;
    }

    return 0;
}
