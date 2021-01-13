#include <stdio.h>
#include <string.h>

void swap(char **a, char **b);
char* add(char *num1, char *num2);
int main(){
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		char a[20], b[20];
		scanf("%s %s", a, b);
		char *tong = add(a, b);
		printf("%s\n", tong);
	}
	return 0;
}
void swap(char **a, char **b){
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

char* add(char *num1, char *num2){
	
	if (strlen(num1) < strlen(num2))
		swap(&num1, &num2);

	size_t num1_len = strlen(num1), num2_len = strlen(num2);
	char* sum = new char[num1_len+2];
	memset(sum, '0', num1_len+1);
	int nho = 0;

	for (int i = 0; i < num2_len; i++){
		int tmp = num2[num2_len-i-1] - '0'+ num1[num1_len-i-1] - '0';
		if (nho)
			tmp++;
		
		nho = tmp > 9;
		tmp %= 10;
		sum[num1_len-i] = tmp + '0';
	}

	for (int i = 0; i < num1_len - num2_len; i++){
		int tmp = num1[num1_len-num2_len-i-1] - '0';
		if (nho)
			tmp++;

		nho = tmp > 9;
		tmp %= 10;
		sum[num1_len-num2_len-i] = tmp + '0';
	}

	sum[num1_len+1] = '\0';

	if (nho)
		sum[0] = '1';
	else{
		for (int i = 0; i <= num1_len; i++)
			sum[i] = sum[i+1];
	}
	return sum;
}
