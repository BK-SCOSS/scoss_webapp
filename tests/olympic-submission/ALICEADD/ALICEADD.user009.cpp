#include<iostream> 
#include<iomanip>
using namespace std;

int main()
{
	int T,a,b;
	cin >> T;
	do {
		cin >> a >> b;
		cout << setw(20) << right << a + b << endl;
		T = T - 1;
		if (T == 0)
		{
			break;
		}

	} while (T <= 10);
	return 0;
}



	



