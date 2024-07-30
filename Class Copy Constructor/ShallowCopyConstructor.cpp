/*By default, the copy constructor and assignment operator perform shallow copies,
 which is not suitable for a class managing dynamically allocated memory.
  This can lead to double deletions and undefined behavior.
  (Shallow copy, double deletion).
*/

#include <bits/stdc++.h>

class MyNumber{
private:
    int *val1;
    int val2;
public:
    MyNumber(int x = 3, int y = 5){
        val1 = new int;
        *val1 = x;
        val2 = y;
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

void fun1(MyNumber x){}
MyNumber fun2()
{
    MyNumber e(1, 2);
    return e;
}

int main()
{
    MyNumber a;             //Normal constructor
    MyNumber b(10, 20);     //Normal constructor

    MyNumber c(b);          //copy constructor to build c
    MyNumber d = b;         //copy constructor to initialize in declaration
    fun1(c);                //copy constructor to pass object
    fun2();                 //copy constructor to return object

    a = b;                  //assignment NOT copy constructor

    a.PrintValueAndAddress();
    b.PrintValueAndAddress();
    c.PrintValueAndAddress();
    d.PrintValueAndAddress();
    return 0;
}
