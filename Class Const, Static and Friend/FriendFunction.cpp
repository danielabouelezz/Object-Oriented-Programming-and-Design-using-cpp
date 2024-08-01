/// Using friend with global functions

#include <bits/stdc++.h>

class A{
private:
    int a1_private = 10;
    int a2_private = 20;

    void HiddenA()
    {
        std::cout<< "I am hidden \n";
    }
public:
    ///global friend function
    friend void PrintA(A& x);
};

void PrintA(A& x)
{
    std::cout<<x.a1_private<<"\n";
    std::cout<<x.a2_private<<"\n";
    x.HiddenA();
}

int main()
{
    A a;

    PrintA(a);

    return 0;
}
