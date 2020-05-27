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

输出一个字符char的二进制形式
std::bitset<8>
输出一个整形int的二进制形式
std::bitset<8*4>
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
const int* p1 = &i;      // 不能用此指针修改指向的值,指向const的指针
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

# 引用和指针
~~~
引用：仅仅是其他变量的别名，没有独立的内存，不能修改去引用其他变量。
指针：储存其他变量额地址，有独立的内存，可以修改指向其他变量。
示例：
    int i = 0;
    int *p = &i;
    //int &ii;          // 错误，引用初始化需要指定变量
    int &iii = i;
    int *&ip = p;       // 从右往左看，&是一个引用，int*引用的是整形指针
    int &*ip = iii;     // 错误，*是指针,int&指向引用，引用没有独立内存空间
    int &*ip2 = &iii;   // 同上，取地址符&不能作用于引用

int value = 10;
const int &r1 = value;  // 实际上绑定到了一个临时变量
                        // const int temp = value;
                        // const int &r1 = temp;
~~~
# 数组的指针&引用   
* 数组和指针：
~~~
int arr1[10];
int arr2[3];
int (*p1)[10] = &arr1;  // (*p)是一个指针,[10]指向数组[10],int类型是整形
int (*p2)[10] = &arr2;  // 错误,int[10]和int[3]大小不一致
~~~
* 对数组的引用：
~~~
int (&refa1)[10] = arr1;// 正确
int (&refa2)[10] = arr1;// 错误，大小不一致
~~~
* 数组里面存放引用：
~~~
int &ref[10];           // 错误，引用没有独立内存空间
~~~


# 不处理转义字符

格式为 R"delimiter(raw_characters)delimiter"
~~~
std::cout << R"anyworld(\\\ \0\n ///)anyworld" << std::endl;
~~~

# 不要对浮点数进行比较   
~~~
double a = 100-99.9;
double b = 10-9.9;
修改精度到足够位数可以发现计算机不能精确表示浮点数
std::setprecision(17)
如果非要比较，通常是看两数之差的绝对值是否足够小
std::fabs(a-b) < 1e-10
~~~

# c++17新增   
~~~
if/switch语句中的初始化语句
std::string s = "Hello, i is fish"; 
if(auto i = s.find("Hello"); i != std::string::npos){
    std::cout << i << std::endl;
}
~~~
# c++11新增 
* 可变数目的形参
~~~
void f(std::initializer_list<int> il){
    ... //
}
f({1, 2, 3});
~~~
* constexpr

>constexpr 用于定义编译时可计算的常量表达式。  
>1、编译时常量函数度，编译器可以可以计算该函数的值。比如一些宏（macro）函数，就可以用 constexpr 函数来更好的代替。  
>2、编译时常量数据，比如某些专在类和类模板中定义的静态常量数据，以前是用 static const 定义，现在可以改用 constexpr 定义了，可以获得更好的效率和属安全性.  
>比如 
~~~  
int sth(){
    return 4;
}
const int n=sth();
~~~
>本来这样的代码是不能通过编译的，因为编译器无法确定sth()得到的是不是常量，但改为
~~~
constexpr int sth(){
    return 4;
}
~~~
>之后,由于明确指出了函数的返回值是常量，于是编译器就找到信心了。   
>这样做的目的我觉得是加强安全性和可靠性吧   

