//#include<iostream>
//#include<string>

#include<bits/stdc++.h>

using namespace std;
int CharToInt(char s){

}

class number{
    private:
        int a[20];
        int length;
    public:

     //   int a[20];
       // int length;
       number(){};
       number(int i){
           length=i;
       }
        number(string s){
            length=s.size();
            for (int i=0;i<s.size();i++){
                //a[i]=atoi(s.at(i);
                a[i]=(int)s[i]-48;  // hoac s[i]-'0'
            }
            

        }
        
         void Output(){
            for(int i=0;i<length;i++)
                cout<<a[i];
        }

        void OutputREvese(){
            for(int i=length-1;i>=0;i--)
                cout<<a[i];
        }

        /* void SetLength(int i){
            this.length=i;
        } */

       /*  void number1(int i){
            this->length=i;
        } */
        int Length(){
            return length;
        } 
        void SetLength(int i){
            length=i;
        }
        int IntAt(int i){
            return a[i];
        }
        void Insert(int vt,int gt){
            a[vt]=gt;
        }
};

void SameLength(string &a,string &b){
     int l1 = a.size(), l2 = b.length();
    if (l1 >= l2){
        b.insert(0, l1-l2, '0');    
    }else{
        a.insert(0, l2-l1, '0');    
    }
}

number Add(number a, number b){
    number c;
    /* int min =(a.Length()>b.Length()?b.Length():a.Length());
     if (a.Length>b.Length){
         for(int i=a.length;i>(a.length-b.length);i--){
            if 
        }
        int i= b.Length; 
        while (min>=0)
        {
            if (a.IntAt(i)

            i=i-1;
        }
    } */
    int temp = 0;
    for (int i=a.Length()-1; i>=0; i--)   // duyet va cong
    {
        temp = a.IntAt(i) + b.IntAt(i) + temp;    // tinh tong tung doi mot
        c.Insert(a.Length()-i-1,(temp%10));         // gan phan don vi vao
        temp = temp/10;     // lay lai phan hang chuc
    }
    c.SetLength(a.Length());
 //   cout<<temp<<endl;
    if (temp>0)  // neu hang chuc > 0 thi them vao KQ
    {
        c.Insert(a.Length(),(temp));
        c.SetLength(a.Length()+1);
    } 

    return c;



}





int main(){
    
    /* a.Input("1020");
    b.Input("1000"); */
  /*   a.Output();
    b.Output();
    int x=a.Length();
    cout <<x; */
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
         string x;
    string y;
    cin>> x>> y;
    SameLength(x,y);
    //number a= new number(x);
    number a(x);
    number b(y);
//    a.Output();
 //   cout<<endl;
  //  b.Output();
   // cout<<endl;
    number c;
    c= Add(a,b);
    c.OutputREvese();

    }
    
   




    return 0;
}