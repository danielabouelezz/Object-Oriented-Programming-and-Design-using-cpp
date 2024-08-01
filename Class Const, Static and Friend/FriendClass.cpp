/*** A friend class can access my private
     Here B is A's friend
     Inside B, it can access its private section(variables & functions)
***/

#include <bits/stdc++.h>

class A{
private:
    int a1_private = 10;
    int a2_private = 20;

    void HiddenA()
    {
        std::cout<<"I am hidden\n";
    }
public:
    //friend class : access its private section
    friend class B;
};

class B{
public:
    void AccessA1(A& x)
    {
        std::cout<<x.a1_private<<"\n";
    }
    void AccessA2(A& x)
    {
        std::cout<<x.a2_private<<"\n";
    }
};

int main()
{
    A a;
    B b;
    b.AccessA1(a);
    b.AccessA2(a);

    return 0;
}
