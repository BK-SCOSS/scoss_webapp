#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100], bit[100];
int a, b;

int comp(const int *a, const int *b) {
    return *a - *b;
}

int binarySearch(int temp, int begin, int end) {
    if(begin < end) {
        int mid = (begin + end)/2;

        if(arr[mid] == temp) {
            return mid;
        }
        else if(arr[mid] < temp) {
            return binarySearch(temp, mid + 1, end);
        }
        else {
            return binarySearch(temp, begin, mid - 1);
        }
    }
    else {
        if(arr[begin] == temp) {
            return begin;
        }
        else {
            return -1;
        }
    }
}

int main() {
    int T, i, j, temp, count;
    scanf("%d", &T);
    
    while(T--) {
        count = 0;
        scanf("%d", &a);
        for(i = 0; i < a; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, a, sizeof(int), comp);

        scanf("%d", &b);
        for(i = 0; i < b; i++) {
            scanf("%d", &temp);

            temp = binarySearch(temp, 0, a-1);

            if(bit[temp] == 0 && temp >= 0) {
                bit[temp] = 1;
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}