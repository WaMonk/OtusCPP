#include <timus.h>


#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

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
    }
}

