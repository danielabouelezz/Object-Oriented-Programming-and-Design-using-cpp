/*** What if we need a shared variable among all objects?
     So defined once and used by all? Static member
     Once created
        Could be no objects yet
        Available till program ends
***/

#include <bits/stdc++.h>

class Test{
public:
    static int x; //Declare: shared among all objects
};

int Test::x = 0; //Define outside

void f()
{
    Test::x += 10; //Same x
}

int main()
{
    Test::x += 1;  //Access

    f();

    std::cout<<Test::x<<"\n";

    return 0;
}
