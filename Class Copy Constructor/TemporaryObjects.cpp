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
    /*
    You notice a constructor that takes object of same type, hencing copy name.
    Always use const and &, const may be removed, but & no, removing & will lead to compile error.
    */
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

void play1(MyNumber a){}
void play2(MyNumber &a){}
void play3(const MyNumber &a){}

MyNumber play4()
{
    MyNumber x(1, 1);
    return x; //Returned objects is temporary
}

int main()
{
    play1(MyNumber());
    //play2(MyNumger());        //Cannot be bound to a non-const reference
    play3(MyNumber());
    //play2(play4());           //Cannot be bound to a non-const reference


    /* Notice: sometimes the copy constructor won't be called!
       Due to C++ return value optimization (RVO)
       It eliminates the temporary object created to hold a function's return value
    */
    return 0;
}
