#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
   	cin >> T;
   	while(T--){
   		int N, cnt = 0;
   		cin >> N;
   		for (int a = 1; a <= 9; a++) {
   			for(int b = 1; b <= 9; b++) {
   				for(int c = 1; c <= 9; c++) {
   					for (int d = 1; d <= 9; d++) {
   						for(int e = 1; e <= 9; e++) {
   							for(int f = 1; f <= 9; f++) {
   								for(int g = 1; g <= 9; g++) {
   									if ( (1000*(a+e) + 10010*c + 100*(b+f) + 10*g) == N) cnt ++;
							   }
						   }
					   }
				   }
			   }
		   }
	   }	
		cout << cnt;  
	}
    return 0;
}

