#include <iostream>
#include <future>
#include <chrono>

void f1()
{
    std::cout << "f1!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "f1 5s later!"<<std::endl;
}

int main()
{
    
    // test for join and detach
    std::thread t1(f1);
    //t1.join();
    //t1.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "main 1s later!"<<std::endl;
    t1.join();
    //t1.detach();
    std::cout << "main thread quit!"<<std::endl;
    s
    return 0;
}

