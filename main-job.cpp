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

void test(int v1, int v2){
    std::cout << v1 << '\t' << v2 << std::endl;
}

void test2(std::initializer_list<int> il){
    for(auto i : il){
        std::cout << i << '\t';
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    test2({1, 2, 3, 4});
    return 0;

}

