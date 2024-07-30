/* In assign operation, compiler copy member by member
   Be careful from = with pointers.
   As we can see form this example the assigned value for b was lost
      after we did a = b, which an grave error and could lead to bad consecuenses
      if we tryed to delete the value in any of these variables because both of them are
      looking at the same address now which could lead to unpredicted behavior.
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

int main()
{
    MyNumber a;
    MyNumber b(10, 20);

    a.PrintValueAndAddress();
    b.PrintValueAndAddress();
    b = a; //Assign a to b (shallow)
    b.PrintValueAndAddress();

    return 0;
}
