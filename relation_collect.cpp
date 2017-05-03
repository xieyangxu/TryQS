#include <cmath>
#include "env.h"
#include "relation_collect.h"

bool m[D_R][D_P+10];

void gen(long A, int ccnt) {
	long remain = A;
	for (int i = 1; i < D_P; ++i)
	{
		while ((remain % p[i]) == 0) {
			remain /= p[i];
			m[ccnt][i] ^= 1;
		}
		if (remain == 1) break;
	}
}

void collect(long f) {
	long A = sqrt(f) + 1;
	int ccnt = 0;

	while (ccnt < D_P) {
		gen(A, ccnt);
	}
}