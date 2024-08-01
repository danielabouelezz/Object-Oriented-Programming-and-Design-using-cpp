/*** In a similar way, we want a static function shared among all objects.
     This means it can't access data member.
     But can access static as it is shared.
***/

#include <bits/stdc++.h>

class Test{
public:
    int x;
    static int factorial(int n)
    {
        // x = 10  // can't access member data

        int res = 1;
        for(int i{1}; i <= n; ++i)
        {
            res *= i;
        }
        return res;
    }
};

int main()
    {
        std::cout<<Test::factorial(5);

        return 0;
    }
