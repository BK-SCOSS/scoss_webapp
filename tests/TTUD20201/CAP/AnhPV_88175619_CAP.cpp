#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1000;

int T, n, m;
long long a[MAXN];
long long b[MAXN];

void nhap()
{
	cin >> T;
	if (T < 0 || T > 10) {
		exit;
	}

	for(int i = 0; i < T; i++)
    {
        cin >> n;
	if (n < 2 || T > 100) {
		exit;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

        cin >> m;
	if (m < 2 || m > 100) {
		exit;
	}
	for (int i = 0; i < m; i++)
		cin >> b[i];
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i] == b[j] && a[i] > 0 && a[j] > 0)
            {
                count += 1;
            }
            else
            {
                count += 0;
            }
        }
    }
    cout << count << endl;
    }
}


int main()
{

	nhap();

	return 0;
}

