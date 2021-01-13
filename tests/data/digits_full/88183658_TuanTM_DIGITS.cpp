#include <iostream>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	int H, U ,S, T, O, I, C;
	int Test;
	cin >> Test;
	for (int test = 0; test < Test; test ++)
	{
		bool check[10] = {false};
		int count = 0, N;
		cin >> N;
		for (int i = 1; i < 10; i++)
		{
			if (check[i]) continue;
			check[i] = 1;
			H = i;
			for (int j = 0; j < 10; j++)
			{
				if (check[j]) continue;
				check[j] = 1;
				U = j;
				for (int k = 1; k < 10; k++)
				{
					if (check[k]) continue;
					check[k] = 1;
					S = k;
					for (int l = 0; l < 10; l++)
					{
						if (check[l]) continue;
						check[l] = 1;
						T = l;
						for (int m = 0; m < 10; m++)
						{
							if (check[m]) continue;
							check[m] = 1;
							O = m;
							for (int n = 0; n < 10; n++)
							{
								if (check[n]) continue;
								check[n] = 1;
								I = n;
								for (int p = 0; p < 10; p++)
								{
									if (check[p]) continue;
									C = p;
									int tong = 1000*H + 100*U + 10010*S + 2*T + 1000*O + 100*I + 10*C;
									if (tong == N) count ++;
								}
								check[n] = 0;
							}
							check[m] = 0;
						}
						check[l] = 0;
					}
					check[k] = 0;
				}
				check[j] = 0;
			}
			check[i] = 0;
		}
		cout << count << "\n";
	}
	return 0;
}
