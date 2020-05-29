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

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(/* args */);
    Date(Date d){
        year = d.year;
    }
    ~Date();
};

Date::Date(/* args */)
{
}

Date::~Date()
{
}


int main(int argc, char const *argv[])
{


    return 0;
}

