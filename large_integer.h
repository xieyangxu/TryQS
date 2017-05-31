#ifndef LARGE_INTEGER_H
#define LARGE_INTEGER_H

#include <iostream>
#include <math.h>
#define DIGIT_MAX 1000
//const int MAX = 3000;

using namespace std;

class BigInt {
    bool valid, negative;
    unsigned long long num[DIGIT_MAX];
    
    int compare(const BigInt&) const;
    int kcompare(const BigInt&, int) const;
public:
    BigInt();
    BigInt(const char*);
    BigInt(int);
    BigInt(long);
    
    bool operator == (const BigInt &) const;
    bool operator != (const BigInt &) const;
    bool operator < (const BigInt &) const;
    
    BigInt operator - () const;
    BigInt operator +(const BigInt&);
    BigInt operator -(const BigInt&);
    BigInt operator *(const BigInt&);
    BigInt operator /(const BigInt&);
    BigInt operator %(const BigInt&);
    BigInt bigsqrt();
    
    friend ostream &operator << (ostream&, const BigInt&);
};

BigInt biggcd(BigInt, BigInt);
#endif
