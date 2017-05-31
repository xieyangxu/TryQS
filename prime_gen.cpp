#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "prime_gen.h"

long p[D_P+10];

void prime_gen() {
	p[1] = 2;
	long n = 3;
	int cnt = 1;
	for (; cnt <= D_P; n++) {
		int flag = 1;
		long limit = sqrt(n) + 1;
		for (int i = 1; i <= cnt; ++i)
		{
			if (n % p[i] == 0) {
				flag = 0;
				break;
			}
			if (p[i] > limit) break;
		}
		if (flag == 1) {
			p[++cnt] = n;
		}
	}
}

void prime_print() {
	//freopen("/Users/shenqianli/Desktop/p.txt","w",stdout);
    for (int i = 0; i < D_P/10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			printf("%ld ", p[10*i + j]);
		}
		printf("\n");
	}
}
