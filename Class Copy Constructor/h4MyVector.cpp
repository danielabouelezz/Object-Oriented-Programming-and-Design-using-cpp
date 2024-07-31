/*We already coded this before
  Consider following enhancements
  1-Provide Copy constructor
  2-In get method, make sure no out of index access
  3-provide set method to change arra content
  4-method to get array length
*/

#include <bits/stdc++.h>

class MyVector{
private:
    int* arr;
    int len = 100;
public:
    MyVector(int len, int defaultValue):
        len(len), arr(new int[len]){
            for(int i{0}; i < len; ++i)
            {
                arr[i] = defaultValue;
            }
        }

    MyVector(const MyVector &another)
    {
        len = another.len;
        arr = new int[len];
        for(int i{0}; i < len; ++i)
            {
                arr[i] = another.arr[i];
            }
    }

    ~MyVector(){
        delete[] arr;
        arr = nullptr;
    }

    void set(int pos, int value)
    {
        if(pos >= 0 && pos < len)
        {
            this->arr[pos] = value;
        }
        std::cout<<"Out of index position\n";
        return;
    }

    int get(int pos) const
    {
        if(pos < len && pos >= 0)
        {
            return this->arr[pos];
        }
        std::cout<<"Out of index position\n";
        return -1;
    }

    int getLen() const
    {
        return len;
    }
};

int main()
{
    return 0;
}
