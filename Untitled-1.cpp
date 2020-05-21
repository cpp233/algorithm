#include <iostream>
#include <algorithm>
#include <string>
#include <map>

std::string f(std::string s)
{
    std::map<int , char> m;
    for(int i = 0; i < s.size(); ++i){
        if( ('a' > s[i] || 'z' < s[i] ) &&
            ('A' > s[i] || 'Z' < s[i] ) ){
            m[i] = s[i];
            s[i] = ' ';
        }
    }
    while (s.npos != s.find(' '))
    {
        s.erase(s.find(' '), 1);
    }
    
    
    std::cout << s << std::endl;
    
    std::reverse(s.begin(), s.end());
    
    for(auto i : m){
        s.insert(i.first, 1, i.second);
    }      
    return s;
}

int main()
{

    std::string s1{"a-s-d---1fasdas"};

    printf("%d, %d, %d, %d, %d\n", 'a', 'z','A', 'Z', '-');
    std::cout << ('a' > 1);
    std::cout << ('A' > 1);
    std::cout << std::endl;
    std::cout << f(s1);

    return 0;
}