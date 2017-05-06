#include <cmath>
#include <cstdio>
#include "env.h"
#include "relation_collect.h"

bool m[D_R+10][D_P+10];
long y[D_R+10];
long r[D_R+10];

void gen(long A, int ccnt, int num_prime) {
	long remain = A * A - f;
	for (int i = 1; i <= num_prime; ++i)
	{
		while ((remain % p[i]) == 0) {
			remain /= p[i];
			m[ccnt][i] ^= 1;
		}
		if (remain == 1) break;
	}
	y[ccnt] = A;
    r[ccnt]=remain;
}

void collect(long f, int num_relation, int num_prime) {
	long A = sqrt(f) + 1;
	int ccnt = 0;

	while (ccnt < num_relation) {
		gen(A, ccnt, num_prime);
		A++;
		ccnt++;
	}
}

void print_relation(int num_relation, int num_prime) {
	printf("RTable  ");
	for (int i = 1; i <= num_prime; ++i)
	{
		printf("%8ld ", p[i]);
	}
	printf("\n");
	for (int i = 0; i < num_relation; ++i)
	{
		printf("%8ld", y[i]);
		for (int j = 1; j <= num_prime; ++j)
		{
			printf("%8d ", m[i][j]);
		}
		printf("\n");
	}
	
}
