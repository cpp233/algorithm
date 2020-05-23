#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>
#include <sstream>
#include <fstream>
#include <memory>
#include <regex>
#include <iterator>
#include <map>
#include <unordered_map>
#include <ios>
#include <iomanip>

    int maxPower(std::string s) {
        int count = 0;
        if(s.empty() ){
            return count;
        }
        char temp;
        int tempCount = 1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == temp){
                tempCount++;
                // std::cout << "相等" << s[i] << " " << temp << std::endl;
            }else
            {
                temp = s[i];
                tempCount = 1;
            }
            if(tempCount > count){
                count = tempCount;
            }
            
        }
        return count;
    }


int main(int argc, char const *argv[])
{
    // std::vector<std::string> nums1 = { "abcdefg" };
    std::string nums1{"leetcode"};
    std::string nums2{"hooraaaaaaaaaaay"};
    std::string nums3{"tourist]"};
    
    std::cout << 
    std::fixed << 0.1 <<
    std::scientific << 0.1 <<
    std::hexfloat << 0.1 << 
    std::defaultfloat << 0.1  << std::endl;

    std::cout << std::setprecision(2) << 3.1415 << std::endl;
    std::cout << std::setw(10) << 3.1415 << std::endl;
    std::cout << std::setw(10) << std::setfill('-') << 3.1415 << std::endl;


    return 0;
}

