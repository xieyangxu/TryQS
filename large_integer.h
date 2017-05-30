#ifndef LARGE_INTEGER_H
#define LARGE_INTEGER_H

#include <iostream> 
#include <math.h>
#define DIGIT_MAX 5000
//const int MAX = 5000;

using namespace std;

class BigInt {
	bool negative;
	unsigned num[DIGIT_MAX];
public:
	BigInt();
	BigInt(const char*);
	BigInt(int);

	int compare(const BigInt&) const;
	int kcompare(const BigInt&, int) const;
	
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
