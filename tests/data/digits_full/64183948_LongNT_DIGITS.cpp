#include <bits/stdc++.h>

using namespace std;

int main()
{
   int T, N;
   cin >> T;
   for (int j=0; j<T; j++)
   {
       cin >> N;
       int k=0;
       if ((N<10000) || (N>100000) || (N%2==1))
       {
           cout << '0' << endl;
           continue;
       }
       for (int S=1; S<10; S++)
            for (int H=1; H<10; H++)
                for (int O=0; O<10; O++)
                    for (int U=0; U<10; U++)
                        for (int I=0; I<10; I++)
                            for (int C=0; C<10; C++)
                                for (int T=0; T<10; T++)
                                    if (((10000*S + 1000*(H+O) + 100*(U+I) + 10*(S+C) + 2*T) == N) && (H!=U) && (H!=S) && (H!=T) && (H!=O) && (H!=I)
                                        && (H!=C) && (U!=S) && (U!=T) && (U!=O) && (U!=I) && (U!=I) && (U!=C) && (S!=T) && (S!=O) && (S!=I) && (S!=C)
                                        && (T!=O) && (T!=I) && (T!=C) && (O!=I) && (O!=C) && (I!=C) ) k++;
       cout << k << endl;

   }
}
