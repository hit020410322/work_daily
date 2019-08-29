#include <iostream>
#include "smart_ptr.h" 
Adapter::Adapter(std::shared_ptr<int> ps) : shared_pi_(ps){
    std::cout << "Adapter Con shared_ptr" << std::endl;
}


Adapter::Adapter(std::unique_ptr<int> pu) : unique_pi_(std::move(pu)){
    std::cout << "Adapter Con unique_ptr" << std::endl;

}


void Adapter::PrintVal(){
    std::cout << "current val : " << val_;
    std::cout << std::endl;
}