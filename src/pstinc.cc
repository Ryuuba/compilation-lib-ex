#include "../include/arith"

namespace arith{

int pst_inc(int& a)
{
    int b = a;
    a = a + 1;
    return b;
}

};