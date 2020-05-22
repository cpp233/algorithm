// 给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//  

// 示例:

// 输入: s = "abcdefg", k = 2
// 输出: "bacdfeg"
//  

// 提示：

// 该字符串只包含小写英文字母。
// 给定字符串的长度和 k 在 [1, 10000] 范围内。


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

    // 硬来、建议不要这样。这个有BUG，没写完。看下面的函数
    std::string reverseStr(std::string s, int k) {
        // ab cd ef g
        // ba cd fe g
        std::string ss = s;
        if(ss.empty() || k > ss.size()){
            return ss;
        }

        for(int i = 0; i < ss.size(); i+=(2*k) ){
            for(int l = i, r = i+k-1; l < r;++l, --r){
                char temp = ss[l];
                ss[l] = ss[r];
                ss[r] = temp;
            }
        }
        return ss;
    }
    //用算法库
    std::string reverseStr2(std::string s, int k) {
        // ab cd ef g
        // ba cd fe g
        // std::string ss = s;
        if(s.empty() || k > s.size()){
            std::reverse(s.begin(), s.end());
            return s;
        }

        for(int i = 0; i < s.size(); i+=(2*k) ){
            if(i+k <= s.size()){        //防止超出string
                std::reverse(s.begin()+i, s.begin()+i+k);
            }
            if(i+k > s.size()){         //最后面一部分独自处理
                 std::reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }

int main()
{
    // std::vector<std::string> nums1 = { "abcdefg" };
    std::string nums1{"abcdefg"};
    std::string nums2{
        "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl"
        };
    auto s1 = reverseStr(nums2, 39);
    auto s2 = reverseStr2(nums1, 3);

    std::cout << "标准答案" << 
        "fdcqkmxwholhytmhafpesaentdvxginrjlyqzyhehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqllgsqddebemjanqcqnfkjmi" << std::endl;

    for(auto i : s1){
        std::cout << i;
    }
    std::cout << std::endl;
    for(auto i : s2){
        std::cout << i;
    }
    std::cout << std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(100));

    return 0;
}

