#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    using std::cout, std::endl;
    int a = arith::add(45, 12);
    int b = arith::sub(34, 19);
    int c = arith::mult(-34, -12);
    int d = arith::div(298, -2);
    cout << "a = " << a << '\n'
         << "b = " << b << '\n'
         << "c = " << c << '\n'
         << "d = " << d << endl;
    return 0;
}
