#include <memory>
class Adapter
{
public:
    Adapter() : val_(0){
        std::cout << "Adapter Con" << std::endl;
    };
    Adapter(std::shared_ptr<int> ps);
    Adapter(std::unique_ptr<int> pu);

    // std::move()
    // 作用：将左值引用转化为右值引用
    // 参数：右值引用
    // 返回值：
    // std::forward

    void PrintVal();

private:
    std::unique_ptr<int> unique_pi_;
    std::shared_ptr<int> shared_pi_;
    int val_;
};


// // RAII: Class T should support AddRef() and DecRef()
// template <typename T>
// class scoped_refptr
// {
// public:
//     typedef T element_type;
//     scoped_refptr() : ptr_(nullptr) {}

//     scoped_refptr(T *p) : ptr_(p)
//     {
//         if (ptr_)
//             ptr_->AddRef();
//     }

// protected:
//     T *ptr_;
// };