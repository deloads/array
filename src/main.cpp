#include <iostream>
#include "array.hpp"


struct Vec
{
    int x,y;

    Vec() = default;
    Vec(int x, int y): x(x), y(y) {}
};


int main(){

    Array<Vec,int> a;

    return 0;
}