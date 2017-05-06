//#include <iostream>
#include <cstring> 
#include <cstdlib>
#include "large_integer.h"
//#include <cstdio> 
//using namespace std;



BigInt::BigInt(const char*s)
{
	int i, j;
	memset(num, 0, sizeof(num));
	for (i = strlen(s) - 1, j = 0; i > 0; --i)
		num[j++] = s[i] - '0';
	if (s[0] == '-')
		negative = true;
	else
	{
		num[j] = s[0] - '0';
		negative = false;
	}
}
BigInt::BigInt(int i)
{
	if (i < 0)
	{
		negative = true;
		i = -i;
	}
	else
		negative = false;
	for (int j = 0; j<DIGIT_MAX; ++j)
	{
		num[j] = (i % 10);
		i /= 10;
	}
}

int BigInt::compare(const BigInt &b) const //>:1 ; =:0 ; <:-1
{
	if (!negative&&b.negative)
		return 1;
	else if (negative&&!b.negative)
		return -1;
	else if (negative&&b.negative)
	{
		for (int i = DIGIT_MAX - 1; i >= 0; --i)
		{
			if (num[i] < b.num[i])
				return 1;
			if (num[i] > b.num[i])
				return -1;
		}
		return 0;
	}
	for (int i = DIGIT_MAX - 1; i >= 0; --i)
	{
		if (num[i] > b.num[i])
			return 1;
		if (num[i] < b.num[i])
			return -1;
	}
	return 0;
}
bool BigInt::lessthan(const BigInt &b, int n) const
{
	for (int i = DIGIT_MAX - 1; i >= n; --i)
	{
		if (num[i] < b.num[i - n])
			return true;
		if (num[i] > b.num[i - n])
			return false;
	}
	return false;
}

BigInt BigInt::operator - () const
{
	BigInt tmp(*this);
	if (tmp.compare(0) != 0)
		tmp.negative = !negative;
	return tmp;
}
BigInt BigInt::operator +(const BigInt &b)
{
	BigInt tmp(*this);
	if (compare(0)*b.compare(0) < 0)
		return tmp - (-b);
	for (int i = 0; i<DIGIT_MAX; ++i)
	{
		tmp.num[i] += b.num[i];
		if (tmp.num[i]>9)
		{
			tmp.num[i] -= 10;
			tmp.num[i + 1]++;
		}
	}
	if (compare(0) == 0)
		tmp.negative = b.negative;
	return tmp;
}
BigInt BigInt::operator -(const BigInt &b)
{
	BigInt tmp(*this);
	if ((negative&&!b.negative) || (!negative&&b.negative))
		return tmp + (-b);
	if (compare(b) == 0)
		return 0;
	else if (compare(b) < 0)
		return -(-(-b) - tmp);
	else if (negative&&b.negative)
		return (-b) - (-tmp);
	for (int i = 0; i < DIGIT_MAX; ++i)
	{
		tmp.num[i] -= b.num[i];
		int j = i;
		while (tmp.num[j] < 0)
		{
			tmp.num[j] += 10;
			tmp.num[++j]--;
		}
	}
	tmp.negative = false;
	return tmp;
}
BigInt BigInt::operator *(const BigInt &b)
{
	int da = DIGIT_MAX - 1, db = DIGIT_MAX - 1;
	while (num[da] == 0 && da > 0)
		--da;
	while (b.num[db] == 0 && db > 0)
		--db;

	BigInt tmp(0);
	for (int i = 0; i <= da; ++i)
	for (int j = 0; j <= db; ++j)
	if (num[i] > 0 && b.num[j] > 0)
	{
		if (i + j >= DIGIT_MAX)
		{
			cerr << "multiplication error: too many digits!" << endl;
			return 0;
		}
		tmp.num[i + j] += num[i] * b.num[j];
	}
	for (int i = 0; i < DIGIT_MAX - 1 && i <= da + db; ++i)
	{
		tmp.num[i + 1] += (tmp.num[i] / 10);
		tmp.num[i] %= 10;
	}
	if (tmp.num[DIGIT_MAX - 1] > 9)
	{
		cerr << "multiplication error: too many digits!" << endl;
		return 0;
	}
	if (compare(0)*b.compare(0) >= 0)
		tmp.negative = false;
	else
		tmp.negative = true;
	return tmp;
}
BigInt BigInt::operator /(const BigInt &b) //a,b are positive
{
	if (b.compare(0) == 0)
	{
		cerr << "cannot divided by 0!" << endl;
		return 0;
	}
	if (compare(0)<0 || b.compare(0)<0)
	{
		cerr << "cannot solve this division..." << endl;
		return 0;
	}
	int da = DIGIT_MAX - 1, db = DIGIT_MAX - 1;
	while (num[da] == 0 && da > 0)
		--da;
	while (b.num[db] == 0 && db > 0)
		--db;
	if (compare(b) < 0)
		return 0;

	BigInt divisor(b), quotient(0), remainder(*this), tmp(0);
	for (int i = da - db; i >= 0; --i)
	{
		int j = 1;
		while (j < 10)
		{
			BigInt dtmp = divisor*j;
			if (remainder.lessthan(dtmp, i))
				break;
			++j;
		}
		quotient.num[i] = j - 1;
		tmp = divisor*(j - 1);
		for (int k = DIGIT_MAX - 1; k >= i; --k)
			tmp.num[k] = tmp.num[k - i];
		for (int k = i - 1; k >= 0; --k)
			tmp.num[k] = 0;
		remainder = remainder - tmp;
	}
	return quotient;
}
BigInt BigInt::operator %(const BigInt &b) //a,b are positive
{
	if (b.compare(0) == 0)
	{
		cerr << "cannot divided by 0!" << endl;
		return 0;
	}
	if (compare(0)<0 || b.compare(0)<0)
	{
		cerr << "cannot solve this complementation..." << endl;
		return 0;
	}
	int da = DIGIT_MAX - 1, db = DIGIT_MAX - 1;
	while (num[da] == 0 && da > 0)
		--da;
	while (b.num[db] == 0 && db > 0)
		--db;
	if (compare(b) < 0)
		return *this;

	BigInt divisor(b), quotient(0), remainder(*this), tmp(0);
	for (int i = da - db; i >= 0; --i)
	{
		int j = 1;
		while (j < 10)
		{
			BigInt dtmp = divisor*j;
			if (remainder.lessthan(dtmp, i))
				break;
			++j;
		}
		quotient.num[i] = j - 1;
		tmp = divisor*(j - 1);
		for (int k = DIGIT_MAX - 1; k >= i; --k)
			tmp.num[k] = tmp.num[k - i];
		for (int k = i - 1; k >= 0; --k)
			tmp.num[k] = 0;
		remainder = remainder - tmp;
	}
	return remainder;
}
BigInt BigInt::bigsqrt()
{
	if (compare(0) < 0)
	{
		cerr << "cannot solve this sqaure root: n < 0" << endl;
		return 0;
	}
	int digit = DIGIT_MAX - 1;
	while (num[digit] == 0 && digit > 0)
		--digit;

	BigInt ans(0), remainder(*this);
	for (int i = digit / 2; i >= 0; --i)
	{
		BigInt partial_ans(0), partial_remainder(0);
		for (int j = 0; j < digit / 2 - i; ++j)
			partial_ans.num[j] = ans.num[i + j + 1];
		for (int j = 0; j <= digit - 2 * i; ++j)
			partial_remainder.num[j] = remainder.num[2*i + j];

		int k = 1;
		while (k < 10)
		{
			if (partial_remainder.compare((partial_ans * 20 + k)*k) < 0)
				break;
			++k;
		}
		ans.num[i] = --k;
		partial_remainder = partial_remainder - (partial_ans * 20 + k)*k;
		for (int j = 0; j <= digit - 2 * i; ++j)
			remainder.num[2 * i + j] = partial_remainder.num[j];
	}
	return ans;
}

ostream &operator << (ostream &o, const BigInt &a)
{
	if (a.negative)
		o << '-';
	bool first = false;
	for (int i = DIGIT_MAX - 1; i >= 0; --i)
	{
		if (a.num[i])
			first = true;
		if (first)
			o << a.num[i];
	}
	if (!first)
		o << 0;
	return o;
}

long mygcd(long a,long b)
{
    if(a==1||b==1) return 1;
    if(a==b) return a;
    if(a<b){
        long t=a;
        a=b;b=t;
    }
    return mygcd(a-b,b);
}
/*
int main()
{
	char s1[5001], s2[5001];
	
	while (cin >> s1 >> s2) {
		BigInt a(s1);
		BigInt b(s2);

		cout << a + b << endl;
		cout << a - b << endl;
		cout << b - a << endl;
		cout << a*b << endl;
		cout << a/b << endl;
		cout << a%b << endl;
		cout << a.bigsqrt() << ' ' << b.bigsqrt() << endl;
	}
}*/
