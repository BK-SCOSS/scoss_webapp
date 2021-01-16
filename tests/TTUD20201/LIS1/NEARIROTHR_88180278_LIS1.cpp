#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;


void Test01()
{
    int arr[]={1};
    list<int> lis1(arr,arr+sizeof(arr)/sizeof(arr[0])),lis2(10,2);
    list<int> lis3(lis1);
    for(list<int>::iterator i=lis1.begin();i!=lis1.end();i++)
    {
        cout << (*i)<<" ";
    }
    cout <<endl;
    
    lis1.push_back(20);
    lis1.insert((lis1.begin()++)++,30);
    lis1.insert(lis1.begin(),10,2);
    //insert 
    lis1.pop_back();
    lis1.erase(lis1.begin(),lis1.begin()++);
    lis1.remove(5);
    //size empty resize
    
    lis2.assign(10,10);
    lis3=lis2;
    lis2.swap(lis3);
    cout << lis1.front() << " "<<lis1.back()<<endl;
    lis1.reverse();
    lis1.sort();
    for(list<int>::iterator i=lis1.begin();i!=lis1.end();i++)
    {
        cout << (*i)<<" ";
    }
}

int main()
{
    Test01();

    return 0;
}
