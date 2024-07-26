#include <bits/stdc++.h>

class Example{
private:
    int x, y, z;
public:
    Example(const int &x, const int &y, const int &z);
    int getX() const;
    int getY() const;
    int getZ() const;
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    void printAdrs();
};

Example::Example(const int &x, const int &y, const int &z):
    x(x), y(y), z(z){}

int Example::getX() const
{
    return x;
}
int Example::getY() const
{
    return y;
}

void Example::printAdrs()
{
    printf("Function address: %p\n", (void*)&Example::getX);
    printf("Function address: %p\n", (void*)&Example::getY);
}
int main()
{
    Example obj(1, 2, 3);

    obj.printAdrs();

    return 0;
}

