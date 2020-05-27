﻿#include <iostream>
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
#include <cmath>
    // 第一次
    int romanToInt(std::string s) {
        std::map<std::string, int>m{
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},};
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            if(auto it = m.find(s.substr(i, 2)); it != m.end()){
                res += it->second;
                ++i;
            }else{
                 res += m[s.substr(i,1)];
            }
        }
        return res;
    }
    //优化后
    int romanToInt2(std::string s) {
        std::map<char, int>m{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},};
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            if( m[s[i]] < m[s[i+1]] ){
                res -= m[s[i]];
            }else{
                res += m[s[i]];
            }
        }
        return res;
    }

int main(int argc, char const *argv[])
{
    std::string s1{"MCMXCIV"};

    std::cout << romanToInt2(s1);

    return 0;

}

