/// What is the output of this program?
/// Why?

#include <bits/stdc++.h>

class Employee{
private:
    std::string name;
public:
    Employee(std::string name):
        name(name){
        std::cout<<"Constructor: "<<name<<"\n";
        }
    ~Employee(){
        std::cout<<"Destructor: "<<name<<"\n";
    }
};

int main()
{
    static Employee belal("Belal");
    Employee most("Mostafa");
    if(true)
        Employee("Mona");
    static Employee Asmaa("Asmaa");

    return 0;
}/// C-belal, C-mostafa, C-mona, D-Mona, C-Asmaa, D-Mostafa, D-asmaa, D-belal.

/***

Constructor's call are the easy part.

For destructor, Think in the object's life time
- Static object ends ONLY with the end of the program.
- So every static member ends only after complete end of program life time
	- If there are more than static, destruction in reverse order

- For local objects, once its scope is done
	- Notice mona's scope ends after the if, but most ends after return 0

***/
