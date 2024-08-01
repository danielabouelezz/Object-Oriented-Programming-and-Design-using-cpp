/*** A practical example where we wanna keep track of employess count
     Public static method is provided to return the count
     Static belal is just like any static variable (exists till end of program)
***/

#include <bits/stdc++.h>

class Employee{
private:
    std::string name;
    static int employees_count;
public:
    Employee(std::string name):
        name(name){
            ++Employee::employees_count;
        }
    static int GetEmployeeCount()
    {
        return Employee::employees_count;
    }
};

int Employee::employees_count = 0;

int main()
{
    Employee most("Mostafa");
    Employee("Mona");
    static Employee belal("Belal");

    std::cout<<Employee::GetEmployeeCount();
}
