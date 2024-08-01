/** Create as much as possible const function
        E.g.: getters, print, compute...
    Also, const is a MESSAGE for developer/ User.
**/

#include <bits/stdc++.h>

class Rectangle{
private:
    double width;
    double height;
public:
    Rectangle(double width = 0.0, double height = 0.0):
        width(width), height(height){}

    double ComputeArea() const
    {
        /// width = 1; // function is const, can't change member variables.
        return width * height;
    }

    //Setters & Getters
    double GetHeight() const
    {
        return height;
    }
    double GetWidth() const
    {
        return width;
    }
    void setHeight(double height)
    {
        this->height = height;
    }
    void setWidth(double width)
    {
        this->width = width;
    }
};

int main()
{
    Rectangle r1(2, 3);
    r1.ComputeArea();
    r1.setWidth(10);

    const Rectangle r2(4, 5);
    r2.ComputeArea();
    /// const object can't call non-const member function
    ///r2.setWidth(10);

    return 0;
}
