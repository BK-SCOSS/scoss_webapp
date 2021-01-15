#include<iostream>
#include<string.h>
using namespace std;
void swapPointer(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

char* addBigNumber(char* number1, char* number2)
{
	if (strlen(number1) < strlen(number1))
	{
		swapPointer(&number1, &number2);
	}

	size_t number1Len = strlen(number1), number2Len = strlen(number2);
	char* result = new char[number1Len + 2];
	memset(result, '0', number1Len);
	bool remember = false;

	for (int i = 0; i < number2Len; i++)
	{
		int temp = number2[number2Len - i - 1] - '0' + number1[number1Len - i - 1] - '0';

		if (remember)
			temp++;

		remember = temp > 9;

		temp = temp % 10;

		result[number1Len - i] = temp + '0';
	}

	for (int i = 0; i < number1Len - number2Len; i++)
	{
		int temp = number1[number1Len - number2Len - i - 1] - '0';

		if (remember)
			temp++;

		remember = temp > 9;
	
		temp = temp % 10;

		result[number1Len - number2Len - i] = temp + '0';
	}

	result[number1Len + 1] = '\0';

	if (remember)
	{
		result[0] = '1';
	}
	else
	{
		for (int i = 0; i <= number1Len; i++)
			result[i] = result[i + 1];
	}

	cout<<result<<endl;
}

int main(){
	int t;
	char a[20],b[20];
	do {
		cin>>t;
	}while(t<0||t>10);
	while (t--){
		fflush(stdin);cin>>a>>b;
		*addBigNumber(a,b);
	
	}
	
	return 0;
}
