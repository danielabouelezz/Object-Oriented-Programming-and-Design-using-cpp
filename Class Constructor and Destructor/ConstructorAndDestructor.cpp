#include <bits/stdc++.h>

class MyVector{
private:
    int* arr;
    int len;
public:
    /*MyVector(int len_, int initialValue = 0)
    {
        len = len_;
        arr = new int[len_];
        for(int i{0}; i < len; ++i)
            {
                arr[i] = initialValue;
            }
    }*/

    MyVector(int len_, int initialValue):
        len(len_){
            arr = new int[len];

            for(int i{0}; i < len; ++i)
            {
                arr[i] = initialValue;
            }
        }

    ~MyVector(){
        delete[] arr;
        arr = nullptr;
    }

    int get(int pos)
    {
        return arr[pos];
    }
};

int main()
{
    MyVector v(10, 12345);

    std::cout<<v.get(5);
}
