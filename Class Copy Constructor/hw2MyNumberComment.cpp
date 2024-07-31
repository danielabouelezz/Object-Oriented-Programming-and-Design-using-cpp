// Why did we commented line 18?
// -Think first. Try second.

#include <bits/stdc++.h>

class MyNumber{
private:
    int *val1;
    int val2;
public:
    MyNumber(int x = 3, int y = 5):
        val1(new int(x)), val2(y){
            std::cout<<"MyNumber constructor\n"
        }

    ~MyNumber()
    {
        //delete val1;
        std::cout<<"MyNumber destructor\n"
    }
    /* Assigning a to b as we can see in main, will result in shallow copy which means that
        both a and b will be looking at the same allocated momory (*val1), so when the destructor
        is called at the end of the scope the shared allocated memory will be dealoocated
        so the second one will be what we call a dangling pointer and if the second object's destructor
        is called, it will attempt to delete the already deleted memory, causing undefined behavior
        (typically a crash or memory corruption).
        That's why we commented the destructor. However, this leads to a memory leak because the
        dynamically allocated memory is never freed.
    */

    void PrintValueAndAddress()
    {
        std::cout<<"value1: "<<*val1<<" "<<val1<<"\n";
        std::cout<<"value2: "<<val2<<" "<<&val2<<"\n";
    }
};

int main()
{
    MyNumber a;
    MyNumber b(10, 20);

    a.PrintValueAndAddress();
    b.PrintValueAndAddress();
    b = a; // Assign a to b (shallow);
    b.PrintValueAndAddress();

    return 0;
}
