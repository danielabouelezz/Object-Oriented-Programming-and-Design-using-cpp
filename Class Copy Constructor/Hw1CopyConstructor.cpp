/*.)The format we used for copy constructor argument:
    -const MyNumber &another
  1)What happens if we moved a constructor to the private section?
    -Think first, Try second.
  2)What happens if we moved the copy constructor to the private section?
  3)C++ won't allow you to not use the &, why?
    What kind of behaviour will happen?
  4)C++ don't force you to use const. Why is it a good practice to use it?
*/

#include <bits/stdc++.h>

class MyNumber{
private:
    int* val1;
    int val2;
public:
    MyNumber(int x = 3, int y = 5):
        val1(new int(x)), val2(y){
            std::cout<<"Normal constructor\n";
        }
    // Moving the constructor to the private section means that objects of the class
    // cannot be created from outside the class. Only methods within the class
    //(or friends of the class) can call this constructor. If you try to create
    //an object using this constructor from outside the class, you will get a compilation error.

    MyNumber(const MyNumber &another){
        val1 = new int;
        *val1 = *another.val1;
        val2 = another.val2;
        std::cout<<"Copy constructor\n";
    }
    //Moving the copy constructor to the private section will prevent objects of the class
    //from being copied from outside the class. This means you cannot use copy initialization
    //or pass objects by value (which relies on the copy constructor) from outside the class.
    // Attempting to do so will result in a compilation error. This is often done to prevent
    //copying of objects to avoid shallow copying and potential resource management issues.

    //If we dont use the & sybole in the copy constructor  it will take the parameter by value
    //instead of by reference. This means a copy of the object will be created when the
    //copy constructor is called. This will lead to several issues,
    //like performance overhead(creating copy of the objecto just to pass it to the copy constructor)
    //and Shallow copy issues.

    //Using const before passing the copied object is good practice for several reasons,
    // it avoids modification, allows the compiler to optimize the function call, it communicates
    // the intent that the fuction does not modify the passed object.
    ~MyNumber(){
        if(val1 != nullptr)
        {
            delete val1;
            val1 = nullptr;
        }
        std::cout<<"Destructor \n";
    }

    void printValueAndAddress()
    {
        std::cout<<"value1: "<<*val1<<" "<<val1<<"\n";
        std::cout<<"value2: "<<val2<<" "<<&val2<<"\n";
    }
};

int main()
{
    MyNumber test;
    MyNumber test2(test);

    test.printValueAndAddress();
    test2.printValueAndAddress();

    return 0;
}
