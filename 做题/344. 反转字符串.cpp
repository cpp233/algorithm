// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

// 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

//  

// 示例 1：

// 输入：["h","e","l","l","o"]
// 输出：["o","l","l","e","h"]
// 示例 2：

// 输入：["H","a","n","n","a","h"]
// 输出：["h","a","n","n","a","H"]





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

    //双指针
    void reverseString(std::vector<char>& s) {
        if(s.empty()){
            return ;
        }
        char *pl = &s[0];
        char *pr = &s[s.size()-1];
        while (pl < pr)
        {
            char temp = *pl;
            *pl = *pr;
            *pr = temp;
            pl++;
            pr--;
        }
    }

    //
    void reverseString2(std::vector<char>& s) {
        if(s.empty()){
            return ;
        }
        for(int i = 0, j = s.size()-1; i < j; ++i, --j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

int main()
{
    std::vector<char> nums1 = { 'h','e','l','l','o' };
    std::vector<char> nums2 = { 'H','a','n','n','a','h' };
    reverseString2(nums1);
    reverseString2(nums2);
    for(auto i : nums1){
        std::cout << i;
    }
    std::cout << std::endl;
    for(auto i : nums2){
        std::cout << i;
    }
    std::cout << std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(100));

    return 0;
}