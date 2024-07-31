/* In this code, which lines of code don't compile. Why?
   Which limes of code cause RTE?
*/

#include <bits/stdc++.h>

void print1(std::string& s){}
void print2(const std::string& s){}

std::string msg1()
{
    std::string x = "aa";
    return x;
}
const std::string& msg2()
{
    return "aa";  /// Retruns a reference to a temporary string literal, which is problematic
}
const std::string& msg3()
{
    std::string x = "aa";
    return x;    /// Returns reference to a local variable which will lead to dangling reference.
}

int main()
{
    std::string hello("hello");

    print1(hello);   // Correct compilation
    print1(std::string("world"));    /// Compile error, cannot bind a temporary value to a non-const reference;
    print("!");       /// Compile error, cannot bind a temporary value to a non-const reference;

    print2(hello);  // Correct compilation
    print2(std::string("world"));   // Correct compilation
    print2("!");    // Correct compilation

    std::string a1 = msg1();  // Correct compilation
    std::string &a2 = msg1(); /// Compile error, cannot bind a temporary to a non-const reference
    const std::string &a3 = msg1();  // Correct compilation, passing a temporary to a const reference

    std::string a = msg2();  /// Causes RTE, returning a reference of temporariry string which
                             /// can lead to undifined behavior.
    std::string b = msg3();  /// Causes RTE, returning a refernce to a local variable which will be
                             /// destroyed after the function returns leading to dangling reference.

    return 0;
}
