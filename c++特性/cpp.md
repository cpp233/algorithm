# 控制输出形式操作符  
包含头文件\<ios\>\<iomanip\>
```
std::cout <<                // 接以下
std::boolalpha              // 布尔值以字符串形式输出
std::dec                    // 后续的整数都以十进制形式输出
std::hex                    // 后续的整数都以十六进制形式输出
std::oct                    // 后续的整数都以八进制形式输出
std::fixed                  // 以固定精度形式输出 
std::scientific             // 以科学计数法形式输出
std::hexfloat               // 以十六进制浮点形式输出
std::defaultfloat           // 默认形式输出

iomanip的操纵符往往需要传递一个参数
std::setprecision(2)                    // 改变浮点数的精度
std::setw(10)                           // 改变输出域的宽度
std::setw(10) << std::setfill('-')      // 把setw的空格换成-
```

# 获取类型   
必须在使用 typeid 前包含头文件 \<typeinfo\>（若不包含该头文件，则每次使用关键词 typeid 都令程序非良构。）
~~~
typeid(类型).name()
~~~

# auto decltype 区别   
定义的时候产生**const** 与**非const** 以及**引用** 与**非引用** 的差别

# const 指针解释 
  
~~~
int i = 1024;
int j = 2048;
const int* p1 = &i;      // 不能用此指针修改指向的值
// *p1 = 999;            // 报错
p1 = &j;                 // 此指针里面本身存放的地址可以改变
// *p1 = 999;            // 报错
int const *p3 = &i;      // 两种写法一致
p3 = &j;                 // 同上
// p3 = 999;             // 报错

int* const p2 = &i;      // 不能改变此指针的指向
*p2 = 4096;              // 可以用此指针来修改指向的值
// p2 = &j;              // 报错
~~~

# 不处理转义字符

格式为 R"delimiter(raw_characters)delimiter"
~~~
std::cout << R"anyworld(\\\ \0\n ///)anyworld" << std::endl;
~~~