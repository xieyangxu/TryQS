#include <cmath>
#include <cstdio>
#include <map>
#include "env.h"
#include "relation_collect.h"

bool m[D_R+10][D_P+10];
long y[D_R+10];
long r[D_R+10];
long q[D_R+10];

bool pm[D_PR+10][D_P+10];
long py[D_PR+10];
long pr[D_PR+10];

map<long, int> pi;

void gen(long A, int &ccnt, int num_prime, int &pcnt) {
	long remain = A * A - f;
	bool *temp = new bool[D_P+10]();

	for (int i = 1; i <= num_prime; ++i)
	{
		while ((remain % p[i]) == 0) {
			remain /= p[i];
			temp[i] ^= 1;
		}
		if (remain == 1) break;
	}

	// completely factored
	if (remain == 1)
	{
		y[ccnt] = A;
    	r[ccnt] = remain;
    	q[ccnt] = A * A - f;
    	for (int i = 1; i <= num_prime; ++i)
    	{
    		m[ccnt][i] = temp[i];
    	}
    	ccnt++;
	}
	else //partial
	{
		map<long, int>::iterator it = pi.find(remain);
		if (it != pi.end()) // exit same remain
		{
			long y2 = py[it->second];
			y[ccnt] = A * y2;  // save as y1 * y2
    		r[ccnt] = remain;   // save remain^2 as remain
    		q[ccnt] = (A * A - f) * (y2 * y2 - f);
    		bool *prev = pm[it->second];
    		for (int i = 1; i <= num_prime; ++i)
    		{
    			m[ccnt][i] = temp[i] ^ prev[i];
    		}
    		ccnt++;
		}
		else // new remain
		{
			py[pcnt] = A;
			pr[pcnt] = remain;
			for (int i = 1; i <= num_prime; ++i)
			{
				pm[pcnt][i] = temp[i];
			}
			pi.insert(pair<long, int>(remain, pcnt));
			pcnt++;
		}
	}
}

void collect(long f, int num_relation, int num_prime) {
	long A = sqrt(f) + 1;
	int ccnt = 0;
	int pcnt = 0;

	while (ccnt < num_relation) {
		gen(A, ccnt, num_prime, pcnt);
		A++;
		//ccnt++;
	}
}

void print_relation(int num_relation, int num_prime, int num_partial) {
	printf("RTable    ");
	for (int i = 1; i <= num_prime; ++i)
	{
		printf("%4ld ", p[i]);
	}
	printf("       Rem\n");
	for (int i = 0; i < num_relation; ++i)
	{
		printf("%10ld", y[i]);
		for (int j = 1; j <= num_prime; ++j)
		{
			printf("%4d ", m[i][j]);
		}
		printf("%10ld\n", r[i]);
	}
	printf("\n");

	printf("PTable    ");
	for (int i = 1; i <= num_prime; ++i)
	{
		printf("%4ld ", p[i]);
	}
	printf("   Rem\n");
	for (int i = 0; i < num_partial; ++i)
	{
		printf("%10ld", py[i]);
		for (int j = 1; j <= num_prime; ++j)
		{
			printf("%4d ", pm[i][j]);
		}
		printf("%10ld\n", pr[i]);
	}
}
