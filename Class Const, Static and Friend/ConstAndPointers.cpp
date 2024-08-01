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

    const Rectangle* r2 = new Rectangle(4, 5);
    //delete r2;   Best practice is to add this line to delete allocated memory
    /// r2->seWidth(10.2):  // Can't, const data
    r2 = &r1;        /// OK, not const pointer

    Rectangle* const r3 = new Rectangle(1, 2);
    r3->setWidth(10.2);        ///OK, non-const data
    /// r3 = &r1;           ///Can't, const pointer

    const Rectangle* const r4 = new Rectangle(1, 2);
    ///r4->setWidth(10.2);  //Can't, const data
    /// r4 = &r1           // Can't, const pointer

    const Rectangle* const r5 = &r1;     /// The opposite is not ok


    delete r3;
    delete r4;
    ///Note; r2 is reassigned to &r1, so we don't delete it
    return 0;
}
