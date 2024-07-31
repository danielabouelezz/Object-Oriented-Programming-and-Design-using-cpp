/* One of developers wanted to add get length functionality.Coded as following:
        int& GetLen(){
            return len;
        }
    Notice the int& (return by reference)
    which OOP concept is violated?
    In main, show how a user can abuse our class with such mistake

Note : the original code is at the end.
*/

#include <bits/stdc++.h>

class MyVector{
private:
    int *arr;
    int len = 100;
public:
    MyVector(int len, int defaultVlaue = 0):
        len(len), arr(new int[len])
    {
        std::cout<<"MyVector constructor\n";
        for(int i{0}; i < len; ++i)
            {
                arr[i] = defaultVlaue;
            }
    }

    ~MyVector(){
        std::cout<<"MyVector destructor\n";
        delete[] arr;
        arr = nullptr;
    }

    int get(int pos)
    {
        return this->arr[pos];
    }

/*  int& GetLen()          // returning the len value by reference violated the encap
    {                      // concept. And as we can see from main we can change the value of
        return len;        // len. which is a mistake and can be abused by the user.
  }
*/

// The correct GetLen() method
// The following method will not let us change the value of len.
    int GetLen() const
    {
        return len;
    }
};

int main()
{
    MyVector v1(10);
    std::cout<<v1.GetLen()<<"\n";
    //v1.GetLen() = 3;   // This will change the value of len if you used the first implementation
    std::cout<<v1.GetLen()<<"\n";

    return 0;
}
