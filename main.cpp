#include "env.h"
#include "prime_gen.h"
#include "relation_collect.h"
#include "large_integer.h"
#include "linear_combiner.h"
#include "myresolve.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



BigInt f("2551097447021173");

int main(int argc, char const *argv[])
{
	prime_gen();
	//prime_print();

    collect(f, D_R, D_P);
	//void collect(long f, int num_relation, int num_prime);
	//print_relation(D_R, D_P, 0);
	//void print_relation(int num_relation, int num_prime, int num_partial);

    myresolve(f,D_R,D_P,10000);
	return 0;
}
