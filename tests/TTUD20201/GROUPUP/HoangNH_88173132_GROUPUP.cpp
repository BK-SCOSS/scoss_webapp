#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int T, N;
int *ret;
vector<int> a;

// int calc() {
//   int sum_time = 0;
//   while (a.size() > 1) {
//     vector<int> temp = vector<int>();
//     int max_time = 0;
//     for (int i = 0; i < a.size(); i += 2) {
//       int k = a[i] + a[i+1];
//       max_time = max(max_time, k);
//       temp.push_back(k);
//     }
//     if (a.size() % 2 == 1) {
//       temp.push_back(a[a.size() - 1]);
//     }
//     a = temp;
//     sum_time += max_time;
//     cout << "a size = " << a.size() << endl;
//     cout << "max_time = " << max_time << endl;
//     cout << "sum time = " << sum_time << endl;
//   }
//   return sum_time;
// }

int calc() {
  int sum_time = 0;
  while (a.size() > 1) {
    vector<int> temp = vector<int>();
    int max_time = 0;
    if (a.size() % 2 == 0) {
      for (int i = 0; i < a.size(); i += 2) {
        int k = a[i] + a[i+1];
        temp.push_back(k);
        max_time = max(max_time, k);
      }
    } else {
      for (int i = 0; i < a.size() - 1; i += 2) {
        int k = a[i] + a[i+1];
        temp.push_back(k);
        max_time = max(max_time, k);
      }
      temp.push_back(a[a.size() - 1]);
    }
    a = temp;
    sum_time += max_time;
    // cout << "a size = " << a.size() << endl;
    // cout << "max_time = " << max_time << endl;
    // cout << "sum time = " << sum_time << endl;
  }
  return sum_time;
}

int main() {
  cin >> T;
  ret = new int[T];
  for (int i = 0; i < T; i++) {
    cin >> N;
    a = vector<int>(N);
    for (int j = 0; j < N; j++) {
      cin >> a[j];
    }
    ret[i] = calc();
  }

  for (int i = 0; i < T; i++) {
    cout << ret[i] << endl;
  }
}