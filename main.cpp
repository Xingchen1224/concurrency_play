#include <iostream>
#include <future>
#include <chrono>

void f1(std::string && what, int&& x = 0)
{
    std::cout << x << " bottle of " << what << std::endl;
}

int main()
{
    std::thread t1(f1,"beers",2);
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "main 1s later!"<<std::endl;
    t1.join();
   
    std::cout << "main thread quit!"<<std::endl;
    
    return 0;
}

