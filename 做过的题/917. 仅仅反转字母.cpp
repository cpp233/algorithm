// 给定一个字符串 S，返回 “反转后的” 字符串，
// 其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

// 示例 1：

// 输入："ab-cd"
// 输出："dc-ba"
// 示例 2：

// 输入："a-bC-dEf-ghIj"
// 输出："j-Ih-gfE-dCba"
// 示例 3：

// 输入："Test1ng-Leet=code-Q!"
// 输出："Qedo1ct-eeLg=ntse-T!"

// 提示：

// S.length <= 100
// 33 <= S[i].ASCIIcode <= 122 
// S 中不包含 \ or "


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

    // 把不需要的字符提取出来，然后反转后再插入。
    std::string reverseOnlyLetters(std::string S) {
        std::map<int, char> m;
        for(int i = 0; i < S.size(); ++i){
            if( ('a' > S[i] || S[i] > 'z') &&
                ('A' > S[i] || S[i] > 'Z') ){
                m[i] = S[i];
                S[i] = ' ';
                
            }
        }
        while(std::string::npos != S.find(' ')){
            S.erase(S.find(' '), 1);
        }
        std::reverse(S.begin(), S.end());
        for(auto i : m){
            S.insert(i.first, 1, i.second);
        }
        return S;
    }

    //双指针法
    bool isChar(char c){
        return ('a' > c || c > 'z') && ('A' > c || c > 'Z');
    }
    std::string reverseOnlyLetters2(std::string S) {
        if(S.empty()){
            return S;
        }
        char* left = &S[0];
        char* right = &S[S.size()-1];
        while (left < right)
        {
            if( isChar(*left) ){
                left++;
            }
            if( isChar(*right) ){
                right--;
            }
            if (!isChar(*left) && !isChar(*right))
            {
                char temp = *left;
                *left = *right;
                *right = temp;
                left++;
                right--;
            }
        }
        
        return S;
    }


int main()
{
    // std::vector<std::string> nums1 = { "abcdefg" };
    std::string nums1{"a-bC-dEf-ghIj"};
    std::string nums2{"Test1ng-Leet=code-Q!"};
    std::string nums3{"7_28]"};
    std::string nums4{"a-bC-dEf-ghIj"};
    
    
    auto s1 = reverseOnlyLetters(nums1);
    auto s2 = reverseOnlyLetters(nums2);
    // auto s3 = reverseOnlyLetters2(nums3);
    auto s4 = reverseOnlyLetters2(nums4);
    for(auto i : s1){
        // std::cout << i;
    }
    std::cout << std::endl;
    for(auto i : s2){
        // std::cout << i;
    }
    std::cout << std::endl;
    // std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(100));

    return 0;
}