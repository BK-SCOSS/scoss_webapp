#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n;
      cin >> n;
      string a, b;
      stack<int>st1, st2, st3;
      for(int i = 1;i <= n; i++)
      {
            cin >> a >> b;
            for(int j = 0; j < a.length(); j++)
                  st1.push(a[j]-'0');
            for(int j = 0; j < b.length(); j++)
                  st2.push(b[j]-'0');
            int cnt = 0;
            while(st1.size()>0&&st2.size()>0)
            {
                  if (st1.top()+st2.top() + cnt <= 9)
                  {
                        st3.push(st1.top()+st2.top()+cnt);
                        st1.pop();
                        st2.pop();
                        cnt = 0;
                  }
                  else
                  {
                        st3.push(st1.top()+st2.top()+cnt-10);
                        cnt = 1;
                        st1.pop();
                        st2.pop();
                  }
            }
            while(st1.size()>0)
            {
                  if (st1.top() + cnt <= 9)
                  {
                        st3.push(st1.top()+cnt);
                        st1.pop();
                        cnt = 0;
                  }
                  else
                  {
                        st3.push(st1.top()+cnt-10);
                        cnt = 1;
                        st1.pop();
                  }
            }
            while(st2.size()>0)
            {
                  if (st2.top() + cnt <= 9)
                  {
                        st3.push(st2.top()+cnt);
                        st2.pop();
                        cnt = 0;
                  }
                  else
                  {
                        st3.push(st2.top()+cnt-10);
                        cnt = 1;
                        st2.pop();
                  }
            }
            if (cnt == 1) st3.push(1);
            while(st3.size()>0)
            {
                  cout<<st3.top();
                  st3.pop();
            }
            cout << endl;


      }
}
