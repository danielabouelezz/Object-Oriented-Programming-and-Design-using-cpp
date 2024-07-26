#include <iostream>
#include <string>

class Student{
private:
    std::string name;
    std::string lastName;
    int age;
public:
    std::string getName() const;
    std::string getLastName() const;
    int getAge() const;
    void setName(std::string name);
    void setLastName(std::string lastName);
    void setAge(int age);
};

std::string Student::getName() const
{
    return name;
}

void Student::setName(std::string name)
{
    this->name = name;
}

class KindergartenApp{
private:
    Student student;
    bool shy;
public:
    Student getStudent() const;
    bool getIsShy() const;
    void setStudent(Student student);
    void setIsShy(bool shy);
};
Student KindergartenApp::getStudent() const
{
    return student;
}

void KindergartenApp::setStudent(Student student)
{
    this->student = student;
}

class CollegeSchoolApp{
private:
    Student student;
    double highSchoolGPA;
public:
    Student getStudent() const;
    double gethighSchoolGPA() const;
    void setStudent(Student student);
    void setHighSchoolGPA(double highSchoolGPA);
};

Student CollegeSchoolApp::getStudent() const
{
    std::cout<<student.getName();
    return student;
}

void CollegeSchoolApp::setStudent(Student student)
{
    this->student = student;
}
double CollegeSchoolApp::gethighSchoolGPA() const
{
    return highSchoolGPA;
}

void CollegeSchoolApp::setHighSchoolGPA(double highSchoolGPA)
{
    this->highSchoolGPA = highSchoolGPA;
}

int main()
{
    Student st1;
    st1.setName("dany");

    CollegeSchoolApp CSapp;
    CSapp.setStudent(st1);
    CSapp.getStudent();

    return 0;
}
