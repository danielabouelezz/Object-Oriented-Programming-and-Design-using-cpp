/* This is an example that answers the following questions:
    1) What are the possible ways to finish ClassC constructor
    2) How many times ClassA Constructord will be called?
        -Why?
        -Give a tip for the coder.
*/

#include <bits/stdc++.h>

class ClassA{
public:
    ClassA(){
        std::cout<<"ClassA constructor\n";
    }
};

class ClassB{
private:
    ClassA aa;
    int x;
public:
    /*ClassB(int x){
        this->x = x;
        this->aa = ClassA();
    }*/

    ClassB(int x):
        x(x), aa(classA()){
        /* Originally the constructor of classA was called twice, once to be default initialized,
            second time inside the constructor

           Changing to Initializer list, we initialized it before construction.
           so we initialize it only once.

           Tip: Always use Initializer list
           Note: if a member object is not initialized through a member initializer,
                 the member object's default constructor will be called "implicitly"

            Avoid duplicate initialization!
        */
        }
};

class ClassC{
private:
    int &y;
    ClassB bb;
public:
    /*ClassC(int &y, const ClassB &bb){
    // Write your solution here:
        this->y = y;
        this->bb = bb;
    }*/

    ClassC(int &y, const ClassB &bb):
        y(y), bb(bb){
            //1-The only way to initialize a reference is initializer list.
            //2-The only way to initialize a class that doesn't have default constructor
            //   (eg. ClassB) is  via initializer list.
        }
};
// Always remember this : USE INITIALIZER LIST AS MUCH AS POSSIBLE!
 int main()
 {
     int hello = 10;
     ClassB b(5);
     ClassC cc(hello, b);
     return 0;
 }
