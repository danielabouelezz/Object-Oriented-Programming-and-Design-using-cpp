/*In a recent code review, senior TL asked you to change the constructor to use const and &.
    Why do you think so?*/

#include <bits/stdc++.h>
class A{
public:
    A(){
        std::cout<<"Construct A\n";
    }
    ~A(){
        std::cout<<"Destruct A\n";
    }
};

class B{
public:
    B(){
        std::cout<<"Construct B\n";
    }
    ~B(){
        std::cout<<"Destruct B\n";
    }
};
class C{
public:
    C(){
        std::cout<<"Construct C\n";
    }
    ~C(){
        std::cout<<"Destruct C\n";
    }
};

class D{
private:
    A aa;
    B bb;
    C cc;
public:
    /* From this:
    D(A aa, B bb, C cc):
        aa(aa), bb(bb), cc(cc){}*/

    //To this:
    D(const A &aa, const B &bb, const C &cc):
        aa(aa), bb(bb), cc(cc){}
};
/*-Using 'const' ensures the original objects are not modified inside the constructor.
  -Using '&'(references) avoids unecessary copying of objects, which can be more efficient.
*/
int main()
{
    A a;
    B b;
    C c;
    D d(a, b, c);

    return 0;
}
