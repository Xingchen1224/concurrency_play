#include <iostream>
#include <future>
#include <chrono>
#include <memory>

void f_unique(std::unique_ptr<size_t> pu)
{
    std::cout << "inner f_unique: " << *pu << std::endl;
}

void f_shared(std::shared_ptr<size_t> ps)
{
    std::cout << "inner f_shared: " << *ps << std::endl;
}

int main()
{
    std::unique_ptr<size_t> p1 = std::make_unique<size_t>(222);
    
    std::cout << "unique before move: " << *p1 << std::endl;
    //f_unique(p1); // compile error: std::move() is required
    
    f_unique(std::move(p1));
    //std::cout << "unique after move: " << *p1 << std::endl; // runtime error: bad access
    
    std::shared_ptr<size_t> p2 = std::make_shared<size_t>(666);
    
    std::cout << "shared before func: " << *p2 << std::endl;
    f_shared(p2); // compile ok, runtime ok.
    //f_shared(std::move(p2));// compile ok, runtime error: bad access
    std::cout << "shared after func: " << *p2 << std::endl;
    
    return 0;
}

