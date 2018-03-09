#include <iostream>
#include <future>
#include <chrono>

void f1(std::string && what, int&& x = 0)
{
    std::cout << x << " bottles of " << what << std::endl;
}

void f2(std::string what, int x = 0)
{
    std::cout << x << " glasses of " << what << std::endl;
}

class F3
{
public:
    void f3(size_t data)
    {
        ++data;
        this->m_data = data;
        std::cout << "data: " << data << std::endl;
    }
private:
    size_t m_data{0};
};

int main()
{
    std::thread t1(f1,"beer",2); // global func void
    t1.join();
    
    std::thread t2(f2,"milk",3); // global func with params
    t2.join();
    
    F3 f3_obj;
    std::thread t3(&F3::f3,&f3_obj, 666);
    t3.join();
    
    return 0;
}

