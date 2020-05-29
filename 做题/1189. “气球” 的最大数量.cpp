// 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
// 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。

// 示例 1：
// 输入：text = "nlaebolko"
// 输出：1

// 示例 2：
// 输入：text = "loonbalxballpoon"
// 输出：2

// 示例 3：
// 输入：text = "leetcode"
// 输出：0
//  

// 提示：
// 1 <= text.length <= 10^4
// text 全部由小写英文字母组成

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

    // 改进版
    int maxNumberOfBalloons2(std::string text) {
        int res = 0;
        std::string check{"balloon"};
        if(text.size() < check.size()){
            return res;
        }

        std::unordered_map<char, int> m;
        for(auto c : text){
            m[c]++;
        }
        while(true)
        {
            for(auto c : check){
                if(m[c] == 0){
                    m.erase(c);
                    return res;
                }else{
                    m[c]--;
                } 
            }
            ++res;
        }
        
        return res;
    }

    // 初版
    int maxNumberOfBalloons(std::string text) {
        std::unordered_map<char, int> m;
        std::string check{"balloon"};
        for(auto c : text){
            if(auto it = check.find(c); it != std::string::npos ){
                m[c]++;
            }
        }
        
        int res = 0;
        for(auto isChange = m.size(); isChange == m.size() ;++res )
        {
            for(auto c : check){
                if(m[c] == 0){
                    m.erase(c);
                    return res;
                }else{
                    m[c]--;
                } 
            }
        }
        
        return res;
    }

int main(int argc, char const *argv[])
{
    std::string s1{"loonbalxballpoon"};
    std::cout << maxNumberOfBalloons2(s1);

    return 0;
}