#include <iostream>

#include "smart-ptr/smart_ptr.h"

void TestSmartPtr(){
    // std::shared_ptr<int> sp = std::make_shared<int>(new int(5));
    std::shared_ptr<int> sp = std::make_shared<int>(5);
    Adapter adp(sp);

    adp.PrintVal();


    RefCountedObject<Adapter> ref_adp;
}


int main()
{
    TestSmartPtr();
    std::cout << "hello w";
}