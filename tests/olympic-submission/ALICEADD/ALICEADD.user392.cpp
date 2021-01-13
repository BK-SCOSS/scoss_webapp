#include <bits/stdc++.h>
using namespace std;
char a[20],b[20],c[20],x[20],y[20],z[20];

void add () {
    fflush(stdin);
	scanf("%s",a);
	scanf("%s",b);
	for (int i=0;i<20-strlen(a);i++) x[i]='0';
	for(int i=20-strlen(a);i<20;i++) x[i]=a[i-20+strlen(a)];
	for (int i=0;i<20-strlen(b);i++) y[i]='0';
	for(int i=20-strlen(b);i<20;i++) y[i]=b[i-20+strlen(b)];
	for (int i=19;i>=0;i--)
		{
			if (x[i]+y[i]<106)  c[i]=x[i]+y[i]-48;
			else
			{
				c[i]=x[i]+y[i]-58;
				x[i-1]=x[i-1]+1;
			}
		}
	int i=0;
	while (i<20)
	{
		if (c[i]=='0') i=i+1;
		else break;
	}
	if (i==20) printf ("0");
	else for (int j=i;j<20;j++) printf ("%c",c[j]);
}
int main ()
{
    int n;
    cin >> n;
	for (int i=0;i<n;i++) add();
}

