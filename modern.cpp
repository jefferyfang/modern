// modern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string.h>

class People {
public:
    // 按值传入字符串，可接收左值、右值。
    // 接收左值时为复制，接收右值时为移动
    People(std::string name)
        : name_(std::move(name)) // 显式移动构造，将传入的字符串移入成员变量
    {
        std::cout << "Hello People(std::string name)=" << name_ << std::endl;
    }
    std::string name_;
};

void foo(char c, void* p)
{
    std::cout << "Hello foo(char c, void* p)!\n";
}
void foo(char c, int i)
{
    std::cout << "Hello foo(char c, int i)!\n";
}

// constexpr
void test_constexpr1() {
    int i = 2;

    const int c1 = 2;
    const int c2 = i; //const修饰的变量可以用变量来初始化，合法
    //const int c3;     //非法，需要给定初值

    constexpr int ce1 = 1 + 2; //定义一个常量表达式 ce1，合法
    constexpr int ce2 = c1; //非法
    //constexpr int ce3 = i;  //非法
    //constexpr int ce4;      //非法
}

#define SIZE 5
void test_constexpr2() {
    const int i = 2;
    const int c = 5;
    constexpr int ce = 5;
    int arr1[5];
    int arr2[SIZE];
    int arr3[c]; //非法
    int arr4[i]; //可以，i是常量表达式
}

template<int N>
auto func() {
    if constexpr (N == 1)
        return 1;
    else
        return -1;
}

std::tuple<std::string, int> create_person() {
    return { "zzh", 20 };
}

int main()
{
    std::cout << "Hello World!\n";
    foo('x', NULL);
    foo('x', nullptr);    
    People a("Alice"); // 移动构造name

    std::string bn = "Bob";
    People b(bn); // 拷贝构造name

    test_constexpr1();

    //调用
    func<1>();
    //上面的函数会变成
    /*auto func(){
        return 1;
    } */

    auto __temp = create_person(); //auto[] ->这里是auto
    auto& name = std::get<0>(__temp);
    auto& age = std::get<1>(__temp);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
