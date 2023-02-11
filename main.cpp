#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

bitset<20> intToBits(int a)
{
    bitset<20> result;
    if (a < 0)
        {
            result.set(19, 1);
            a = -1 * a;
        }
    for (int i = 1; i <= 32; i++)
    {
        if (a >= pow(2.0, 32-i))
        {
            a = a - pow(2.0, 32-i);
            if (32-i < 19)
            {
                result.set(32-i,1);
            } 
        }
    }
    return result;
}

int bitsToInt(bitset<20> b)
{
    int result = 0;
    bool flag = false;
    if (b[19] == 1)
    {
        flag = true;
        b.set(19, 0);
    }
    result = (int)(b.to_ulong());
    if (flag)
    {
        result = -1 * result;
    }
    return result;
}
class Int20
{
private:
    bitset<20> bytes;
public:
    void setBytes(bitset<20> a)
    {
        this->bytes = a;
    }

    bitset<20> getBytes() const
    {
        return this->bytes;
    }

    Int20 operator+(const Int20& b)
    {
        Int20 result;
        int temp1 = 0, temp2 = 0;
        temp1 = bitsToInt(this->bytes);
        temp2 = bitsToInt(b.bytes);

        temp1 += temp2;

        result.setBytes(intToBits(temp1));
        return result;
    }   
    Int20 operator-(const Int20& b)
    {
        Int20 result;
        int temp1 = 0, temp2 = 0;
        temp1 = bitsToInt(this->bytes);
        temp2 = bitsToInt(b.bytes);

        temp1 -= temp2;

        result.setBytes(intToBits(temp1));
        return result;
    }   
    Int20 operator*(const Int20& b)
    {
        Int20 result;
        int temp1 = 0, temp2 = 0;
        temp1 = bitsToInt(this->bytes);
        temp2 = bitsToInt(b.bytes);

        temp1 *= temp2;

        result.setBytes(intToBits(temp1));
        return result;
    }
    Int20 operator/(const Int20& b)
    {
        Int20 result;
        int temp1 = 0, temp2 = 0;
        temp1 = bitsToInt(this->bytes);
        temp2 = bitsToInt(b.bytes);

        temp1 /= temp2;

        result.setBytes(intToBits(temp1));
        return result;
    }

    Int20 operator%(const Int20& b)
    {
        Int20 result;
        int temp1 = 0, temp2 = 0;
        temp1 = bitsToInt(this->bytes);
        temp2 = bitsToInt(b.bytes);

        temp1 %= temp2;

        result.setBytes(intToBits(temp1));
        return result;
    }
    Int20 operator++(int k)
    {
        Int20 tmp(*this);
        int temp1 = 0;
        temp1 = bitsToInt(this->bytes);

        temp1 ++;
        setBytes(intToBits(temp1));

        return tmp;
    }
    Int20 operator--(int k)
    {
        Int20 tmp(*this);
        int temp1 = 0;
        temp1 = bitsToInt(this->bytes);

        temp1 --;
        setBytes(intToBits(temp1));

        return tmp;
    }

};

istream & operator>>(istream & is, Int20& b)
    {
        int temp2;
        is >> temp2;

        b.setBytes(intToBits(temp2));
        return is;

    }

ostream & operator<<(std::ostream & os, const Int20& b)
    {
        int temp2 = 0;
        bitset<20> temp1 = b.getBytes();
        temp2 = bitsToInt(temp1);

        os << temp2;
        return os;

    }

/*
long long operator+=(long long a, const Int20& b)
    {
        int temp1 = 0;
        temp1 = (long long)bitsToInt(b.getBytes());

        a += temp1;
        return a;
    }
*/
void operator+=(long long &a, const Int20& b)
    {
        int temp1 = 0;
        temp1 = (long long)bitsToInt(b.getBytes());

        a += temp1;
        //std::cout << a<< std::endl;
        //return a;
    }
void operator-=(long long &a, const Int20& b)
    {
        int temp1 = 0;
        temp1 = (long long)bitsToInt(b.getBytes());

        a -= temp1;
        //return a;
    }



int main()
{
    Int20 first, second;
    std::cin >> first >> second;
    long long sum1 = 0, sum2 = 0;
    for (long long loop = 0; loop < 1048560; loop += 1)
    {
        first++;
        second--;
        sum1 += first;
        sum2 -= second;
    }

    std::cout << first + second << sum1 << sum2 << std::endl;
    return 0;
}

