#include <iostream>
#include <utility>

// static_cast<remove_reference<decltype(arg)>::type&&>(arg)


// template <class T>
// typename remove_reference<T>::tpye&& move(T&& arg) noexcept;
// move返回arg的右值引用

// 右值的地址不能通过解引用得到，因为右值是临时

// 完美转发

int source() {return 100;}

template <typename T>
void g(T t){
    t++;
    std::cout << t << std::endl;
}

// 泛型转发函数
// f要将参数t原封不动的转发给g(), rvalue or lvalue, const or non-const
template <typename T>
void f(T& t){
    g(t);
}