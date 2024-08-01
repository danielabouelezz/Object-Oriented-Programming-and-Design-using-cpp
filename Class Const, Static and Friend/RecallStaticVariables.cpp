/***Declared once - in memory till program ends
    Shared among different to its block
 ***/

 #include <bits/stdc++.h>

 void hello()
 {
     int i1 = 0;
     static int i2 = 0;

     std::cout<<i1<<" " <<i2 <<"\n";
     i1++;
     i2++;
 }

 int main()
 {
     hello();
     hello();
     hello();

     return 0;
 }
