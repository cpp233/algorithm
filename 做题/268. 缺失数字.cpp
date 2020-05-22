// 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

// 示例 1:

// 输入: [3,0,1]
// 输出: 2

// 示例 2:
// 输入: [9,6,4,2,3,5,7,0,1]
// 输出: 8

// 说明:
// 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?



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

    //硬来
    int missingNumber(std::vector<int>& nums) {
        int res = 0;
        std::sort(nums.begin(), nums.end());
        if(nums[0] != 0){
            return 0;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(  nums.size() == (i+1) ){
                res = nums[i]+1;
                break;
            }
            if(nums[i]+1 != nums[i+1] ){
                res = nums[i]+1;
                break;
            }
        }
        return res;
    }
    // 哈希数组法
    int missingNumber2(std::vector<int>& nums) {
        int res;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i ){
                res = i;
                break;
            }
        }
        return res;
    }
    // map方法
    int missingNumber3(std::vector<int>& nums) {
        int res;
        std::unordered_map<int, bool> m;
        for(auto i : nums){
            m[i] = true;
        }
        for(int i = 0; i <= nums.size(); ++i){
            if(!m[i]){
                res = i;
                break;
            }
        }
        return res;
    }
    // 位运算
    int missingNumber4(std::vector<int>& nums) {
        int res = nums.size();              //如果全部按顺序，则size为没有的
        for(int i = 0; i < nums.size(); ++i){
            res ^= i ^ nums[i];
        }
        return res;
    }
    // 高斯求和公式
    int missingNumber5(std::vector<int>& nums) {
        int expectedSum = nums.size()*(nums.size() + 1)/2;
        int actualSum = 0;
        for (auto num : nums) actualSum += num;
        return expectedSum - actualSum;
    }

int main()
{
    std::vector<int> nums = { 3,0,1 };
    std::cout << missingNumber4(nums);

    // std::this_thread::sleep_for(std::chrono::seconds(100));

    return 0;
}