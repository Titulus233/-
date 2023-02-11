#ifndef INT20_H
#define INT20_H

#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

bitset<20> intToBits(int a);
int bitsToInt(bitset<20> b);

class Int20
{
    private:
    bitset<20> bytes;
    public:
    void setBytes(bitset<20> a);
    bitset<20> getBytes() const;
    Int20 operator+(const Int20& b);
    Int20 operator-(const Int20& b);
    Int20 operator*(const Int20& b);
    Int20 operator/(const Int20& b);
    Int20 operator%(const Int20& b);
    Int20 operator++(int k);
    Int20 operator--(int k);
};

istream & operator>>(istream & is, Int20& b);
ostream & operator<<(std::ostream & os, const Int20& b);
void operator+=(long long &a, const Int20& b);
void operator-=(long long &a, const Int20& b);
#endif