#include<iostream>

using namespace std;

int My_T, My_N;
int flag[10];
int my_result = 0;
int num[7];

void My_Try(int depth) {
  if (depth == 7) {
    int H = num[0];
    int U = num[1];
    int S = num[2];
    int T = num[3];
    int O = num[4];
    int I = num[5];
    int C = num[6];
    int sum = H * 1000 + U * 100 + S * 10 + T + S * 10000 + O * 1000 + I * 100 + C * 10 + T;
    if (sum == My_N) {
      my_result++;
    }
    return;
  }
  
  int start;
  if (depth == 0 || depth == 2) {
    start = 1;
  } else {
    start = 0;
  }

  for (int i = start; i <= 9; i++) {
    if (!flag[i]) {
      flag[i] = 1;
        num[depth] = i;
        My_Try(depth + 1);
      flag[i] = 0;
    }
  }
}

int main() {
  cin >> My_T;
  for (int i = 0; i < My_T; i++) {
    cin >> My_N;
    my_result = 0;
    for (int i = 0; i < 10; i++)
    {
      flag[i] = 0;
    }
    My_Try(0);
    cout << my_result;
    if (i != My_T - 1) {
      cout << endl;
    }
  }
}
