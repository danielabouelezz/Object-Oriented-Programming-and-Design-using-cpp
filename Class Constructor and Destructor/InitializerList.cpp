#include <bits/stdc++.h>
/* As we can see for the example below changing the order of the parameters while using
    the initializer list, won't affect the result.
    We used the regular "Commented" constructor and the none regular one below it. */

class MyClass{
private:
    std::string name;
    std::string lastName;
    int age;
    int ID;
public:
    MyClass():
        name(""), lastName(""), age(0), ID(0){};
    /*MyClass(std::string name, std::string lastName, int age, int ID):
        name(name), lastName(lastName), age(age), ID(ID)
        {
            std::ostringstream oss;
            oss<<name<<","<<lastName<<","<<age<<","<<ID;
        };*/
    MyClass(std::string name, std::string lastName, int age, int ID):
        age(age), name(name), ID(ID), lastName(lastName){
        }

    std::string getName()
    {
        return name;
    }
    std::string getLastName()
    {
        return lastName;
    }
    int getAge()
    {
        return age;
    }
    int getID()
    {
        return ID;
    }
};


int main()
{
    MyClass obj("Daniel", "ezz", 26, 221);
    std::cout<<obj.getName()<<", "<<obj.getLastName()<<", "<<obj.getAge()<<", "<<obj.getID();
    return 0;
}
