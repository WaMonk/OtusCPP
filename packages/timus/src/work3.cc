#include <work3.h>

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <numeric>

namespace otus {
    namespace timus {

    void task1409() {
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

		long all = v[0] + v[1] - 1;
		std::cout<<all - v[0]<<" "<<all - v[1]<<std::endl;
    }
		
	void task1877() {
		long first = 0;
		long second = 0;
		std::string line;

		getline(std::cin, line);
		first = std::stol(line);
		
		getline(std::cin, line);
		second = std::stol(line);

		if(first % 2 == 0 || second % 2 != 0){
			std::cout<<"yes"<<std::endl;
		}
		else{
			std::cout<<"no"<<std::endl;
		}

	}

	void task2001() {
		std::vector<long> v;

		for(size_t i = 0; i < 3; i++){
			
			std::string line; 
			getline(std::cin, line);
			auto start = line.begin();
			auto sstart = line.begin();
			auto stop= line.end();
			auto eend = line.end();

			do {
                        
                        sstart = std::find_if(start, stop, [](auto chr) { return !std::isspace(chr); });
                        if(sstart != stop){
                            eend = std::find_if(sstart+1, stop, [](auto chr) { return std::isspace(chr); });
                            auto s = std::stoll(std::string(sstart, eend));
                            v.push_back(s);
                            start = eend + 1;
                        }
                        else{
                            break;
                        }    
                    }
                    while(start != line.end());
		}
		std::cout<<v[0] - v[4]<<" "<<v[1] - v[3]<<std::endl;
	}
	
	void task1264() { 
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

		std::cout<<v[0] * ( v[1] + 1)<<std::endl;
	}
	
	void task1787() { 
		long carSpeed, carCount;

		std::cin>>carSpeed>>carCount;
		long current = 0;
		for(size_t i = 0; i < carCount; ++i){
			long add = 0;
			std::cin>>add;
			current += add;
			current = current >= carSpeed? current - carSpeed : 0;
		}

		std::cout<<current<<std::endl;
	}
}}