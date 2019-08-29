#include <iostream>
#include <vector>
#include "smart-ptr/smart_ptr.h"
#include "smart-ptr/ref_counted_obj.h"
#include "smart-ptr/perfect_forward.h"

#include "smart-ptr/value_sematics.h"

void TestSmartPtr()
{
    // std::shared_ptr<int> sp = std::make_shared<int>(new int(5));
    std::shared_ptr<int> sp = std::make_shared<int>(5);
    std::unique_ptr<int> up = std::make_unique<int>(6);
    Adapter adp1(std::move(up));
    Adapter adp2(sp);
    Adapter adp3(std::move(sp));
    int count = sp.use_count();

    //adp.PrintVal();
}

void TestRefCountedObj()
{
    RefCountedObject<Adapter> *ref_adp = new RefCountedObject<Adapter>();
    std::unique_ptr<Adapter> adp1(new Adapter());
    std::unique_ptr<Adapter> adp2(std::move(adp1));
    // RefCountedObject<Adapter> ref_adp2(std::move(adp));
}

// 左值和右值
// 从函数返回左值引用
int global_val = 0;
int &fn1()
{
    return global_val;
}

// 从函数返回临时值，是右值
int fn2()
{
    return 0;
}

int TestRvalueLvalue()
{
    int i = 5;

    // 可以向fn1()的返回值左值引用进行赋值操作
    fn1() = 5;
    // 不可以向fn2()的返回值右值进行赋值操作，右值没有对应的内存空间
    //fn2() = 5;

    // 将fn2()的返回值赋值给一个右值引用
    int &&j = fn2();

    // 可以被赋值的右值引用
    j = 5;
    return 0;
}

// 右值引用、左值引用、引用折叠
void TestRreferenceLreference()
{
    // 左值引用就是普通的引用

    int i = 5;
    int &i_lvalue_reference = i;
    int &&i_rvalue_reference = i + 1;

    // 可以被赋值的引用：是否有const限定符

    // 左值和右值的转换
}

// std::move 和 std::forward
void TestMoveAndForward()
{
    int val = 5;
    int &r_val = val;
    f(r_val);
}

void TestDecltype()
{
    int a[] = {1, 2, 3};
    // the type of b is int&, why
    decltype(*a) b = a[0];

    // now b is 4
    a[0] = 4;

    // remove reference, the type of c is int
    std::remove_reference<decltype(*a)>::type c = a[1];

    a[1] = 5;

    // d is int[3]
    decltype(a) d;
    d[0] = 5;

     int e = 5;
    // type of e1 is int
    decltype(e) e1 = 6;

     int &e2 = e;
    // type of e3 is int&
    decltype(e2) e3 = e;

    // const_cast<int&>(e3) = 8;
    e3 = 8;

}

void TestValueSemantics(){
    Parent father;
    Child boy(&father);

    // Child boy2(&boy);
}


std::vector<int> readfile(){
    std::vector<int> ivec;
    for (size_t i = 0; i < 5; i++)
    {
       ivec.push_back(i);
    }

    // because std::vector<>'s constructor support move semantics
    return std::move(ivec);
}

void TestMoveSematics(){
    // because std::vector<>'s assign operater support move semantics
    std::vector<int> ivec = readfile();
}

void TestPerfectForward(){
    int val = source();
    f(val);
}


int main()
{
    // TestSmartPtr();
    //   TestRefCountedObj();

    // TestMoveAndForward();

    //TestDecltype();

    // TestMoveSematics();

    int len = 64;
    std::unique_ptr<uint8_t[]> bytes(new uint8_t[len]);

    std::unique_ptr<int> ptr_1(new int(3));
    std::unique_ptr<int> &ptr_2 = ptr_1; 
    *ptr_2 = 4;

    std::unique_ptr<int>& ptr_3 = *new std::unique_ptr<int>(new int(5));

    std::cout << "hello w";
}