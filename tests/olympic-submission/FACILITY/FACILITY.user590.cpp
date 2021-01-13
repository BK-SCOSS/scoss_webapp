#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <map>
#include <cmath>

using namespace std;

enum info
{
    DATE,
    RENT_TIME,
    PAYMENT,
    MAX_INFO
};
using FREE_DATE = long long;
using MAX_PROFIT = long long;

int main()
{
	long long Clients(0), Maintainance_Time(0);
	std::cin>>Clients>>Maintainance_Time;

    std::list<std::array<long long, MAX_INFO>> info;
    info.resize(Clients);

    for (auto iii= info.begin(); iii!=info.end() ; ++iii)
    {
        std::cin>>iii->at(DATE)>>iii->at(RENT_TIME)>>iii->at(PAYMENT);
    }

    //std::sort(info.begin(), info.end());

    info.sort();

    //for (auto &i: info)
    //{
    //    std::cout<<"info date: " <<i.at(DATE)<<"\ttime: "<<i.at(RENT_TIME)<<"\tpayment: "<<i.at(PAYMENT)<<"\n";
    //}
    

    long long MAX_REVENUE(0), 
                Current_Date(0);

    std::list<std::pair<FREE_DATE, MAX_PROFIT>> log;

    while (info.size())
    {
        
        Current_Date = info.begin()->at(DATE);

        ///for (auto &i: log)
        //{
        //    std::cout<<"log date: " <<i.first<<"\tpayment: "<<i.second<<"\n";
        //}

            while (log.size() && 
                    log.begin()->first <= Current_Date)
            {
                if (log.begin()->second > MAX_REVENUE)
                {
                    MAX_REVENUE = log.begin()->second;
                }

                log.erase(log.begin());
            }



        while (info.size() && 
                info.begin()->at(DATE) <= Current_Date)
        {

            auto iii=log.begin();

            auto Due_Date = Current_Date + 
                        info.begin()->at(RENT_TIME) + 
                        Maintainance_Time;

            for (; iii != log.end() && 
                    iii->first <= Due_Date
                ; ++iii)
                {}

            log.insert(iii,
                            {   Due_Date
                            , 
                            MAX_REVENUE + info.begin()->at(PAYMENT)});

            info.erase(info.begin());
        }
    }


    while (log.size())
    {
        if (log.begin()->second > MAX_REVENUE)
        {
            MAX_REVENUE = log.begin()->second;
        }

        log.erase(log.begin());
    }

    std::cout<<MAX_REVENUE<<"\n";
	return 0;
}	
