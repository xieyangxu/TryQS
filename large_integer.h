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
	BigInt(const char*);
	BigInt(int);

	int compare(const BigInt&) const;
	int kcompare(const BigInt&, int) const;
	
	BigInt operator - () const;
	BigInt operator +(const BigInt&);
	BigInt operator -(const BigInt&);
	BigInt operator *(const BigInt&);
	BigInt operator /(const BigInt&);
	BigInt operator %(const BigInt&);
	BigInt bigsqrt();

	friend ostream &operator << (ostream&, const BigInt&);
};
long mygcd(long a,long b);

#endif
