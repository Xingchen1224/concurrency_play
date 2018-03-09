#include <iostream>
#include <future>
#include <chrono>
#include <memory>
#include <vector>
#include <iterator>

void f1(int a, int& b, int&& c)
{
    std::cout << "a: " << a << " b:" << b << " c:" << c<< std::endl;
}

class BigDataClass
{
public:
    BigDataClass()
    {
        size_t count = 10000000;
        data.reserve(count);
        for (size_t i=0; i<count; ++i) {
            data.emplace_back(i);
        }
    }
    
    void computeSum()
    {
        size_t sum = 0;
        
        std::vector<size_t>::iterator itr = data.begin();
        while (itr != data.end())
        {
            sum += (*itr);
            ++itr;
        }
        
        std::cout << sum << std::endl;
    }
private:
    std::vector<size_t> data;
};

void f2(BigDataClass ins)
{
    ins.computeSum();
}

void f3(BigDataClass& ref)
{
    ref.computeSum();
}

void f4(BigDataClass&& rval)
{
    rval.computeSum();
}

int main()
{
    int aa = 111;
    int bb = 222;
    int cc = 333;
   
    //f1(aa,bb,cc); // compile error
    f1(aa,bb,std::move(cc));
    
    BigDataClass b;
    
    auto now1 = std::chrono::system_clock::now();
    f2(b);
    auto now2 = std::chrono::system_clock::now();
    std::cout << "value takes: " << std::chrono::duration_cast<std::chrono::milliseconds>(now2 - now1).count() << " ms" << std::endl;
    
    auto now3 = std::chrono::system_clock::now();
    f3(b);
    auto now4 = std::chrono::system_clock::now();
    std::cout << "ref takes: " << std::chrono::duration_cast<std::chrono::milliseconds>(now4 - now3).count() << " ms" << std::endl;
    
    auto now5 = std::chrono::system_clock::now();
    f4(std::move(b));
    auto now6 = std::chrono::system_clock::now();
    std::cout << "rval takes: " << std::chrono::duration_cast<std::chrono::milliseconds>(now6 - now5).count() << " ms" << std::endl;
    
    return 0;
}

