#include <iostream>
#include "smart_ptr.h" 
Adapter::Adapter(std::shared_ptr<int> pc) : pc_(std::move(pc)){
}

void Adapter::PrintVal(){
    std::cout << "current val : " << *pc_;
    std::cout << std::endl;
}