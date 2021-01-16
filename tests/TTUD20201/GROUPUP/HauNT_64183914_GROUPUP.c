#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n; 
int arr[100000] = {0};

int main() {
    int T, i, max, calc;

    scanf("%d", &T);

    while(T--) {
        calc = 0;

        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        while(n > 1) {
            max = 0;
            
            for(i = 0; i < n - 1; i += 2) {
                arr[i/2] = arr[i] + arr[i + 1];

                if(arr[i/2] > max) {
                    max = arr[i/2];
                }
            }

            calc += max;

            if(n%2 != 0) {
                arr[(n-1)/2] = arr[n-1];
                n = n/2 + 1;
            }
            else {
                n = n/2;
            }
        }

        printf("%d\n", calc);
    }

    return 0;
}