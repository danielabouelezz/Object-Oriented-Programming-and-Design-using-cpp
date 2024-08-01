/// Friend Member Function only access my private section BUT not other member fuctions.

#include <bits/stdc++.h>

class A;  //Define early to break cycle

class B{
public:
    void AccessA1(A& x);
    void AccessA2(A& x);
};

class A{
private:
    int a1_private = 10;
    int a2_private = 20;

    void HiddenA()
    {
        std::cout<<"I am hidden\n";
    }

public:
    /// Friend function only access my private data.
    friend void B::AccessA1(A& x);
};

void B::AccessA1(A& x)
{
    std::cout<< x.a1_private<<"\n";
    x.HiddenA();
}

void B::AccessA2(A& x)
{
    /// syntax error: can't access these private data
    /***std::cout<<x.a2_private<<"\n";
    x.HiddenA();***/
}

int main()
{
    A a;
    B b;

    b.AccessA1(a);
    //b.AccessA2(a);
    return 0;
}
