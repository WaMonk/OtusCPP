#include <work2.h>


#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

namespace otus {
    namespace timus {
        void task1001(){
            std::string out;
            std::vector<double> v;
            for(std::string line; getline(std::cin, line);)
                {
                    auto start = line.begin();
                    auto sstart = line.begin();
                    auto stop= line.end();
                    auto eend = line.end();

                    do {
                        
                        sstart = std::find_if(start, stop, [](auto chr) { return !std::isspace(chr); });
                        if(sstart != stop){
                            eend = std::find_if(sstart+1, stop, [](auto chr) { return std::isspace(chr); });
                            auto s = sqrt(std::stoll(std::string(sstart, eend)));
                            v.push_back(s);
                            start = eend + 1;
                        }
                        else{
                            break;
                        }    
                    }
                    while(start != line.end());

            }

            std::ios_base::sync_with_stdio(false);
            std::cout.precision(4);
            std::cout.setf(std::ios::fixed);
            
            std::string buffer = "";
            for(auto i = v.rbegin(); i != v.rend(); ++i){
                buffer += (std::to_string(*i) + '\n'); 
            }
            std::cout<<buffer;
        }


        void task1000(){
            std::string line;
            getline(std::cin, line);

            std::vector<long> v;

            auto start = line.begin();
            auto sstart = line.begin();
            auto stop= line.end();
            auto eend = line.end();

            do {
                sstart = std::find_if(start, stop, [](auto chr) { return !std::isspace(chr); });
                if(sstart != stop){
                    eend = std::find_if(sstart+1, stop, [](auto chr) { return std::isspace(chr); });
                    auto s = std::stol(std::string(sstart, eend));
                    v.push_back(s);
                    start = eend + 1;
                }
                else{
                    break;
                }    
            }
            while(start != line.end());
        
            std::cout<<v.at(0) + v.at(1)<<std::endl;
        }

        void task1785(){
            std::string line;
            
            std::vector<std::pair<long, std::string>> locale = {{1,"few"}, {5,"several"}, {10, "pack"}, {20, "lots"}, {50, "horde"}, {100, "throng"}, {250, "swarm"}, {500, "zounds" }, {1000, "legion"}};

            getline(std::cin, line);
            auto s = std::stol(line);

            auto prev = locale.begin();
            for(auto i = locale.begin(); i != locale.end(); ++i){
                if(i->first > s)
                    break;
                prev = i;
            }

            std::cout<<prev->second<<std::endl;
        }

        void task1293() {
            std::string line;
            getline(std::cin, line);

            std::vector<long> v;

            auto start = line.begin();
            auto sstart = line.begin();
            auto stop= line.end();
            auto eend = line.end();

            do {
                sstart = std::find_if(start, stop, [](auto chr) { return !std::isspace(chr); });
                if(sstart != stop){
                    eend = std::find_if(sstart+1, stop, [](auto chr) { return std::isspace(chr); });
                    auto s = std::stol(std::string(sstart, eend));
                    v.push_back(s);
                    start = eend + 1;
                }
                else{
                    break;
                }    
            }
            while(start != line.end());

            std::cout<<v.at(0) * (2 * v.at(1) * v.at(2))<<std::endl;
        }

        void task2012() {
            std::string line;
            getline(std::cin, line);

            std::vector<long> v;

            const long time = 3600 * 5;
            const long taskCount = 12;

            auto start = line.begin();
            auto sstart = line.begin();
            auto stop= line.end();
            auto eend = line.end();

            do {
                sstart = std::find_if(start, stop, [](auto chr) { return !std::isspace(chr); });
                if(sstart != stop){
                    eend = std::find_if(sstart+1, stop, [](auto chr) { return std::isspace(chr); });
                    auto s = std::stol(std::string(sstart, eend));
                    v.push_back(s);
                    start = eend + 1;
                }
                else{
                    break;
                }    
            }
            while(start != line.end());

            std::cout<<(((taskCount - v.at(0)) - (4 * 60 / 45)) > 0 ? "NO" : "YES")<<std::endl;
        }
    }
}
