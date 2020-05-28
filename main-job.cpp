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
#include <cmath>

    int maxNumberOfBalloons(std::string text) {
        std::unordered_map<char, int> m;
        std::string check{"balloon"};
        for(auto c : text){
            if(auto it = check.find(c); it != std::string::npos ){
                m[c]++;
            }
        }
    for(auto mm : m){
        std::cout << mm.first << mm.second << std::endl;
    }
        return 0;
    }


int main(int argc, char const *argv[])
{
    std::string s1{"loonbalxballpoon"};
    maxNumberOfBalloons(s1);

    return 0;

}

