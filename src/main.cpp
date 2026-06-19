#include <iostream>
#include "array.hpp"


struct Vec
{
    int x,y;

    Vec() = default;
    Vec(int x, int y): x(x), y(y) {}

    bool operator<(const Vec& other) const{
        if(y != other.y){
            return y < other.y;
        }
        return x < other.x;
    }

    bool operator!=(const Vec& other) const{
        return x != other.x || y != other.y;
    }
};


int main(){

    Array<Vec,int> a;

    a.set({0,1},10);

    if(a.get({0,1}) != nullptr){
        std::cout << *a.get({0,1}) << std::endl;
    }

    return 0;
}