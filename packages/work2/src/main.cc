#include <iostream>
#include <memory>
#include <algorithm>


#include <ip.h>
#include <utils.h>

using namespace otus::ip;
using namespace otus::utils;


using namespace std;

int main() {

    try{

        vector<CustomIPSP> ip_pool;
        for(string line; getline(cin, line);)
        {
            auto temp = split(line, '\t');
            if(!temp.empty())
                ip_pool.push_back(make_shared<CustomIP>(temp.at(0).c_str()));
        }

        sort(ip_pool.begin(), ip_pool.end(), [](const CustomIPSP left, const CustomIPSP right) -> bool {return *left <= *right; });
        
        for(const auto& ip : ip_pool){
            ip->print();
        }

        for(auto it = ip_pool.cbegin(); it != ip_pool.cend(); ++it){
            (*it)->print();
        }

        for(const auto& ip : ip_pool){
            if(ip->check_byte(1,1))
                ip->print();
        }

        for(const auto& ip : ip_pool){
            if(ip->check_byte(1,46) && ip->check_byte(2,70))
                ip->print();
        }

        for(const auto& ip : ip_pool){
            if(ip->check_byte(1,46) || ip->check_byte(2,46) || ip->check_byte(3,46) || ip->check_byte(4,46))
                ip->print();
        }

    }
    catch(std::exception& ex){
        cerr<<ex.what()<<endl;
    }


}
