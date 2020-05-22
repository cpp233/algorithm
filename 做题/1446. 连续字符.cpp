// 给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

// 请你返回字符串的能量。


// 示例 1：

// 输入：s = "leetcode"
// 输出：2
// 解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
// 示例 2：

// 输入：s = "abbcccddddeeeeedcba"
// 输出：5
// 解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
// 示例 3：

// 输入：s = "triplepillooooow"
// 输出：5
// 示例 4：

// 输入：s = "hooraaaaaaaaaaay"
// 输出：11
// 示例 5：

// 输入：s = "tourist"
// 输出：1
//  

// 提示：

// 1 <= s.length <= 500
// s 只包含小写英文字母。
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

    // 硬来  之后根据需要增加更优解
    int maxPower(std::string s) {
        int count = 0;
        if( s.empty() ){
            return count;
        }
        char temp;
        int tempCount = 1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == temp){
                tempCount++;
            }else{
                temp = s[i];
                tempCount = 1;
            }
            if(tempCount > count){
                count = tempCount;
            } 
        }
        return count;
    }

int main()
{
    // std::vector<std::string> nums1 = { "abcdefg" };
    std::string nums1{"leetcode"};
    std::string nums2{"hooraaaaaaaaaaay"};
    std::string nums3{"tourist]"};
    
    
    std::cout << maxPower(nums1) << std::endl;
    std::cout << maxPower(nums2) << std::endl;
    std::cout << maxPower(nums3) << std::endl;

    std::cout << std::endl;

    return 0;
}