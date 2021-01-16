#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100000] = {0};
int n;

int main() {
    int T, i, max;

    scanf("%d", &T);
    
    while(T--) {
        scanf("%d", &n);
        max = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if(arr[i] > max) {
                max = arr[i];
            }
        }

        int *mem = (int*)calloc(max + 1, sizeof(int));

        max = 0;
        for(i = 0; i < n; i++) {
            if(mem[arr[i] - 1] == 0) {
                mem[arr[i]] = 1;
            }
            else {
                mem[arr[i]] = mem[arr[i]-1] + 1;
            }
            
            if(mem[arr[i]] > max) {
                max = mem[arr[i]];
            }
        }       

        free(mem);
        
        printf("%d\n", max);
    }

    return 0;
}