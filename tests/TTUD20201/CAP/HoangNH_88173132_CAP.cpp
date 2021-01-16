#include<iostream>
#include<set>

using namespace std;

int T, N, M;
set<long long int> a,b;
int *ret;

int num_intersect() {
  int num = 0;
  for (int u : a) {
    for (int v : b) {
      if (u == v) {
        num++;
      }
    }
  }
  return num;
}

int main () {
  cin >> T;
  ret = new int[T];
  for (int i = 0; i < T; i++) {
    cin >> N; 
    a = set<long long int>();
    for (int j = 0; j < N; j++) {
      int t;
      cin >> t;
      a.insert(t);
    }
    cin >> M;
    b = set<long long int>();
    for (int j = 0; j < M; j++) {
      int t;
      cin >> t;
      b.insert(t);
    }
    ret[i] = num_intersect();
  }

  for (int i = 0; i < T; i++) {
    cout << ret[i] << endl;
  }
}