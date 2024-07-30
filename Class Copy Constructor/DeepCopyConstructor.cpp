#include <bits/stdc++.h>

class MyNumber{
private:
    int* val1;
    int val2;
public:
    MyNumber(int x = 3, int y = 5){
        std::cout<<"Normal constructor\n";
        val1 = new int;
        *val1 = x;
        val2 = y;
    }

    MyNumber(const MyNumber &another){
        std::cout<<"Copy constructor\n";
        val1 = new int;
        *val1 = *another.val1;
        val2 = another.val2;
    }

    ~MyNumber(){
        if(val1 != nullptr)
        {
            delete val1;
            val1 = nullptr;

        }
        std::cout<<"MyNumber destructor\n";
    }

    void PrintValueAndAddress()
    {
        std::cout<<"val1 : "<<*val1<<" "<<val1<<"\n";
        std::cout<<"val2 : "<<val2<<" "<<&val2<<"\n";
    }
};

int main()
{
    MyNumber a;      //Normal constructor
    MyNumber b(a);   //Copy constructor

    a.PrintValueAndAddress();
    b.PrintValueAndAddress();

    return 0;
}
