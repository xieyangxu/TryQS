#include "env.h"
#include "prime_gen.h"
#include "relation_collect.h"
#include "large_integer.h"
#include "linear_combiner.h"
#include "myresolve.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



long f;	

int main(int argc, char const *argv[])
{
	
	f = 991241;
	prime_gen();
	//prime_print();

	collect(f, 50, 30);
	//void collect(long f, int num_relation, int num_prime);
	print_relation(50, 30, 100);
	//void print_relation(int num_relation, int num_prime, int num_partial);

    myresolve(f,50,30,20);
	return 0;
}
