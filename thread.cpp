#include <iostream>
#include <thread>

class MyClass
{
    public:
        void operator()() const
        {
            std::cout << "Hello Concurrent in Class World\n";
        }
};


void hello()
{
    std::cout << "Hello Concurrent World\n";
}

int main()
{
    std::thread t(hello);
    MyClass c;
    std::thread ct(c);
    std::thread ct2(MyClass());
    t.join();
    ct.join();
}
