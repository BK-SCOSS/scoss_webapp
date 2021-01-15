#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string calculate(string stra, string strb)
{
  // ensure that stra always longer than strb
  if (stra.length() < strb.length())
    swap(stra, strb);

  // reverse each string number
  reverse(stra.begin(), stra.end());
  reverse(strb.begin(), strb.end());

  // get length of each number
  int lengtha = stra.length();
  int lengthb = strb.length();

  int carry = 0;
  int sum = 0;
  string strsum = {};

  // do mathematic addition
  for (int i = 0; i < lengtha; i++) {
    sum = ((stra[i] - '0' + strb[i] - '0') + carry);
    strsum.push_back(sum % 10 + '0');

    carry = sum / 10;
  }

  for (int i = lengtha; i < lengthb; i++) {
    sum = ((strb[i] - '0') + carry);
    strsum.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  if (carry) {
    strsum.push_back(carry + '0');
  }

  // reverse the result
  reverse(strsum.begin(), strsum.end());
  return strsum;
}

int main() {
	int count;
        string inputa, inputb;
	cin >> count; 
  for(int i = 0; i<count; i++){
	cin >> inputa >> inputb;
	string result = calculate(inputa, inputb);
  	cout << result << endl;
  }
}
