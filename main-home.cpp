#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> getRandom(int count){
    std::vector<int> v;
    
    std::srand(std::time(nullptr));
    // mingw64无法实现
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<int> dist(0, 100);

    for(int i = 0;i < count; i++){
        // v.emplace_back(dist(rd));
        v.emplace_back( std::rand()%100 );
    }
    return v;
}

// 排序
std::vector<int> insertSort(const std::vector<int>& v){

    if(v.size() < 1){
        return v;
    }

    auto tempV = v;
    for(int i = 1; i < tempV.size(); ++i){

        if(tempV[i] < tempV[i-1]){
            for(int j = 0; j < i;++j){
                if(tempV[i]<tempV[j]){
                    auto temp = tempV[i];
                    for(int k = i; k > j;--k){
                        tempV[k] = tempV[k-1];
                    }
                    tempV[j] = temp;
                    for(auto vvv : tempV){
                        std::cout << vvv << '\t';
                    }
                    std::cout << std::endl;
                }
            }
        }
    }

    return tempV;
}
std::vector<int> selectionSort(const std::vector<int>& v){

    auto tempV = v;

    for(int i=0; i < tempV.size(); ++i){
        int k = i;
        for(int j = i+1; j < tempV.size(); ++j){
            if(tempV[j] < tempV[k]){
                k = j;
            }
        }
        int temp = tempV[i];
        tempV[i] = tempV[k];
        tempV[k] = temp;
    }

    return tempV;
}
std::vector<int> bubbleSorting(const std::vector<int>& v){

    if(v.size() < 1){
        return v;
    }

    auto tempV = v;
    for(int i = v.size(); i > 0; --i){
        for(int j = 0; j+1 < i; ++j){
            if( tempV[j] > tempV[j+1] ){
                auto temp = tempV[j+1];
                tempV[j+1] = tempV[j];
                tempV[j] = temp;
            }
        }
    }

    return tempV;
}

// 查找
// 找出V1、V2重叠的部分
std::vector<int> hashSearch(const std::vector<int>& v1, const std::vector<int>& v2){
    
    auto max1 = std::max_element(v1.begin(), v1.end());
    auto max2 = std::max_element(v2.begin(), v2.end());
    int size = 0;
    // 如果数组最大值很大，会浪费空间
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

// ------------------------------------------------
// 如果数组最大值很大，上面的方法容易浪费空间
// 用求余法限定大小（被除数为N）,任意数字被N除、余一定在0-N之间
// 所以可以用数组元素个数 arr.size()+1 当N
struct Hash
{
    bool isMe;
    int value;
};
std::vector<Hash> getHash(const std::vector<int>& v){
    int size = v.size()+1;                  //要留空一个。否则无法跳出
    Hash h = {false, 0};
    std::vector<Hash> hash(size, h);
    for (auto &vv : v){
        auto rem = vv%size;
        if( !hash[rem].isMe ){
            hash[rem].isMe = true;
            hash[rem].value = vv;
        }else{ 
            while( hash[rem].isMe ){
                if(rem > size){
                    rem = 0;
                }else{
                    rem++;
                }
            }
            hash[rem].isMe = true;
            hash[rem].value = vv;
        }
    }
    return hash;
}
std::vector<int> checkHash(const std::vector<int>& v, std::vector<Hash>& hash){
    std::vector<int> tempV;
    for(auto &vv : v){
        auto rem = vv % hash.size();
        if( hash[rem].isMe && (hash[rem].value == vv) ){
            tempV.emplace_back(vv);
        }else{
            while ( hash[rem].isMe )
            {
                rem++;
                if(hash[rem].isMe && (hash[rem].value == vv) ){
                    tempV.emplace_back(vv);
                    break;
                } 
            }
            
        }  
    }
    return tempV;
}
std::vector<int> hashSearch_remainder(const std::vector<int>& v1, const std::vector<int>& v2){
    
    std::vector<Hash> hash;
    
    std::vector<int> tempV;

    v1.size() > v2.size() ? hash = getHash(v1) : hash = getHash(v2);
    v1.size() > v2.size() ? tempV = checkHash(v2, hash) : tempV = checkHash(v1, hash);
    
    return tempV;
}


void test(){
    for(int i = 9; i <= 10 ; i++){
        auto v1 = getRandom(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "未排序:\n";
        for(auto i : v1){
            std::cout << i << '\t';
        }
        std::cout << std::endl;
        auto v2 = insertSort(v1);
        std::cout << "排序后:\n";
        for(auto i : v2){
            std::cout << i << '\t';
        }
        std::cout << '\n' << std::endl;
    }
}

int main(int argc, char const *argv[]){

    std::cout << "main:" << std::endl;
    int temp;
    std::cin  >> temp;

    auto v1 = getRandom(temp);
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "获取随机数完毕" << std::endl;


    auto start = std::chrono::steady_clock::now();
    // dosomething
    test();
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end- start).count();
    

    std::cout << "耗时:" << time << "ms" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(60));
    return 0;
}


