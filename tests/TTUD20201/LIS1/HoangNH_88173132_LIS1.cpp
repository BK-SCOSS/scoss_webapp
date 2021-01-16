#include<iostream>
#include<algorithm>
using namespace std;

int T, N;
int *ret;
int *a;

// int calc() {
//   int ret = 1;
//   int length = 1;
//   for (int i = 0; i < N; i++) {
//     int temp = a[i];
//     for (int j = i + 1; j < N; j++) {
//       if (a[j] = temp + 1) {
//         temp = a[j];
//         length++;
//       }
//     }
//     ret = max(ret, length);
//     length = 1;
//   }
//   return ret;
// }

int calc() {
  int ret = 1;
  int length = 1;
  for (int i = 0; i < N; i++) {
    int temp = a[i];
    for (int j = i + 1; j < N; j++) {
      if (temp + 1 == a[j]) {
        temp = a[j];
        length++;
      }
    }
    ret = max(ret, length);
    length = 1;
  }
  return ret;
}

int main () {
  cin >> T;
  ret = new int[T];
  for (int i = 0; i < T; i++) {
    cin >> N;
    a = new int[N];
    for (int j = 0; j < N; j++) {
      cin >> a[j];
    }
    ret[i] = calc();
  }

  for (int i = 0; i < T; i++) {
    cout << ret[i] << endl;
  }
}