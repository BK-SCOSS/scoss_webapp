#include <iostream>
#include <cstring>
int remind(int num1,int num2)
{
    if(num1 + num2 < 9) return 0;
    else return (num1 + num2) / 10;
}
std::string addString(std::string s1, std::string s2)
{
    int length,num1,num2,add,rem = 0;
    std::string s3;
    if(s1.size() < s2.size()) std::swap(s1,s2);
    length = s1.size() < s2.size() ? s1.size() : s2.size();
    for(int i = 0; i < length; i++)
    {
        num1 = s1[s1.size() - 1 - i] - 48;
        num2 = s2[s2.size() - 1 - i] - 48;
        add = num1 + num2 + rem;
        rem = remind(num1, num2 + rem);
        if(add > 9) add %= 10;
        s3.push_back(add + '0');
    }
    if(s1.size() != s2.size())
    {
        for(int i = length ; i < s1.size(); i++)
        {
            num1 = s1[s1.size() - 1 - i] - 48;
            add = rem + num1;
            if(add > 9) add %= 10;
            rem = remind(rem, num1);
            s3.push_back(add + '0');
        }
    }
    if(rem != 0) s3.push_back('1');
    return s3;
}
int main()
{
    int testCase;
    std::string s1,s2,s3;
    std::cin >> testCase;
    while(testCase--)
    {
        std::cin >> s1 >> s2;
        s3 = addString(s1,s2);
        for(int i = s3.size() - 1; i >=0; i--) std::cout << s3[i];
        std::cout << std::endl;
    }
}
