#ifndef _HashSearch_h_
#define _HashSearch_h_

#include <vector>
#include <algorithm>
// 查找
// 找出V1、V2重叠的部分
std::vector<int> hashSearch(const std::vector<int>& v1, const std::vector<int>& v2){
    
    auto max1 = std::max_element(v1.begin(), v1.end());
    auto max2 = std::max_element(v2.begin(), v2.end());
    int size = 0;
    
    *max1 > *max2 ? size = *max1: size = *max2;

    std::vector<bool> hash(size, false);
    
    std::vector<int> tempV;
    for (auto &v : v1){
        hash[v] = true;
    }
    for (auto &v : v2)
    {
        if(hash[v] == true){
            tempV.emplace_back(v);
        }
    }
    return tempV;
}

#endif