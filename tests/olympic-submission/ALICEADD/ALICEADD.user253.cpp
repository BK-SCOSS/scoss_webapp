//#include <iostream>
//using namespace std;
//using ll=long long ;
//int main(){
//	int t; cin>>t;
//	while(t--){
//		ll a,b;
//		cin>>a>>b;
//		cout<<a+b<<endl;
//	}
//}
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        bool remember=false;
        string a, b, s1, s2;
        cin >> a >> b;
        if(a.size() == b.size())
            s1 = (a > b ? a : b), s2 = (a > b ? b : a);
        else if(a.size() > b.size())
            s1 = a, s2 = b, [](string& s, string ss){while(s.size() != ss.size())s='0'+s;}(s2, s1);
        else
            s1 = b, s2 = a, [](string& s, string ss){while(s.size() != ss.size())s='0'+s;}(s2, s1);
        // s1 la so lon s2 la so be
        string res;
        bool abun = false;
        for(int i = s1.size()-1; i >=0; i--) {
            if(abun == true)
                s2[i]++;
            if(s2[i] + s1[i] - '0' > '9')
                abun=true, res = char(s1[i]+s2[i]-'9'-1) + res;
            else 
                abun=false, res = char(s1[i]+s2[i]-'0') + res;
        }
        if(abun)
            res = '1' + res;
        // while(res[0] == '0')
        //     res.erase(0, 1);
        cout << res << "\n";
    }
    return 0;
}
