/*** Try to comment line 31
        undefined reference to C::b
     Now try also to comment line 37
        No compiler error!
     Sadly compiler won't be able catch the error that we did not define b
        It is caught only during linking
     Little more extra syntax
***/

#include <bits/stdc++.h>

class A{};
class B{
public:
    int f;
    B(int a, int b)
    {
        f = 10;
    }
};

class C{
public:
    static std::vector<int> v;
    static int arr[10];
    static A a;
    static B b;
};

std::vector<int> C::v = std::vector<int>(20);
int C::arr[10];
A C::a;
B C::b = B(1, 2);

int main()
{
    std::cout<<C::b.f;
    return 0;
}

